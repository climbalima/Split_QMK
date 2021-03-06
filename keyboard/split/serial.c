/*
 * WARNING: be careful changing this code, it is very timing dependent
 */

#define F_CPU 16000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "serial.h"

// Serial pulse period in microseconds. Its probably a bad idea to lower this
// value.
#define SERIAL_DELAY 24

uint8_t volatile serial_slave_buffer[SERIAL_SLAVE_BUFFER_LENGTH] = {0};
uint8_t volatile serial_master_buffer[SERIAL_MASTER_BUFFER_LENGTH] = {0};

inline static
void serial_delay(void) {
  _delay_us(SERIAL_DELAY);
}

inline static
void serial_output(void) {
  SERIAL_PIN_DDR1 |= SERIAL_PIN_MASK1;
}

// make the serial pin an input with pull-up resistor
inline static
void serial_input(void) {
  SERIAL_PIN_DDR  &= ~SERIAL_PIN_MASK;
  SERIAL_PIN_PORT |= SERIAL_PIN_MASK;
}

inline static
uint8_t serial_read_pin(void) {
  return !!(SERIAL_PIN_INPUT & SERIAL_PIN_MASK);
}

inline static
void serial_low(void) {
  SERIAL_PIN_PORT1 &= ~SERIAL_PIN_MASK1;
}

inline static
void serial_high(void) {
  SERIAL_PIN_PORT1 |= SERIAL_PIN_MASK1;
}

void serial_master_init(void) {
  serial_output();
  serial_high();
}

void serial_slave_init(void) {
  serial_input();

  // Enable INT0
  EIMSK |= _BV(INT0);
  // Trigger on falling edge of INT0
  EICRA &= ~(_BV(ISC00) | _BV(ISC01));
}

// Used by the master to synchronize timing with the slave.
static
void sync_recv(void) {
  serial_input();
  // This shouldn't hang if the slave disconnects because the
  // serial line will float to high if the slave does disconnect.
  while (!serial_read_pin());
  serial_delay();
}

// Used by the slave to send a synchronization signal to the master.
static
void sync_send(void) {
  serial_output();

  serial_low();
  serial_delay();

  serial_high();
}

// Reads a byte from the serial line
static
uint8_t serial_read_byte(void) {
  uint8_t byte = 0;
  serial_input();
  for ( uint8_t i = 0; i < 8; ++i) {
    byte = (byte << 1) | serial_read_pin();
    serial_delay();
    _delay_us(1);
  }

  return byte;
}

// Sends a byte with MSB ordering
static
void serial_write_byte(uint8_t data) {
  uint8_t b = 8;
  serial_output();
  while( b-- ) {
    if(data & (1 << b)) {
      serial_high();
    } else {
      serial_low();
    }
    serial_delay();
  }
}

// interrupt handle to be used by the slave device
ISR(SERIAL_PIN_INTERRUPT) {
  sync_send();

  for (int i = 0; i < SERIAL_SLAVE_BUFFER_LENGTH; ++i) {
    serial_write_byte(serial_slave_buffer[i]);
    sync_send();
  }

  // wait for the sync to finish sending
  serial_delay();

  // read the middle of pulses
  _delay_us(SERIAL_DELAY/2);

  for (int i = 0; i < SERIAL_MASTER_BUFFER_LENGTH; ++i) {
    serial_master_buffer[i] = serial_read_byte();
    /* serial_master_buffer[2] = serial_read_byte(); */
    sync_send();
  }

  serial_input();
}

// Copies the serial_slave_buffer to the master and sends the
// serial_master_buffer to the slave.
//
// Returns:
// 0 => no error
// 1 => slave did not respond
int serial_transaction(void) {
  // this code is very time dependent, so we need to disable interrupts
  cli();

  // signal to the slave that we want to start a transaction
  serial_output();
  serial_low();
  _delay_us(1);

  // wait for the slaves response
  serial_input();
  serial_high();
  _delay_us(SERIAL_DELAY);

  // check if the slave is present
  if (serial_read_pin()) {
    // slave failed to pull the line low, assume not present
    sei();
    return 1;
  }

  // if the slave is present syncronize with it
  sync_recv();

  // receive data from the slave
  for (int i = 0; i < SERIAL_SLAVE_BUFFER_LENGTH; ++i) {
    serial_slave_buffer[i] = serial_read_byte();
    sync_recv();
  }

  // send data to the slave
  for (int i = 0; i < SERIAL_MASTER_BUFFER_LENGTH; ++i) {
    serial_write_byte(serial_master_buffer[i]);
    sync_recv();
  }

  // always, release the line when not in use
  serial_output();
  serial_high();

  sei();
  return 0;
}
