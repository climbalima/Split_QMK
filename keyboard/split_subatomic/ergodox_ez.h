#ifndef ERGODOX_EZ_H
#define ERGODOX_EZ_H

#include "matrix.h"
#include "keymap_common.h"
#include "backlight.h"
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include "i2cmaster.h"
#include <util/delay.h>

#define CPU_PRESCALE(n) (CLKPR = 0x80, CLKPR = (n))
#define CPU_16MHz       0x00

// I2C aliases and register addresses (see "mcp23018.md")
#define I2C_ADDR        0b0100000
#define I2C_ADDR_WRITE  ( (I2C_ADDR<<1) | I2C_WRITE )
#define I2C_ADDR_READ   ( (I2C_ADDR<<1) | I2C_READ  )
#define IODIRA          0x00            // i/o direction register
#define IODIRB          0x01
#define GPPUA           0x0C            // GPIO pull-up resistor register
#define GPPUB           0x0D
#define GPIOA           0x12            // general purpose i/o port register (write modifies OLAT)
#define GPIOB           0x13
#define OLATA           0x14            // output latch register
#define OLATB           0x15

extern uint8_t mcp23018_status;

void init_ergodox(void);
void ergodox_blink_all_leds(void);
uint8_t init_mcp23018(void);
uint8_t ergodox_left_leds_update(void);

#define LED_BRIGHTNESS_LO       15
#define LED_BRIGHTNESS_HI       255


inline void ergodox_board_led_on(void)      { DDRD |=  (1<<6); PORTD |=  (1<<6); }
inline void ergodox_right_led_1_on(void)    { DDRB |=  (1<<5); PORTB |=  (1<<5); }
inline void ergodox_right_led_2_on(void)    { DDRB |=  (1<<6); PORTB |=  (1<<6); }
inline void ergodox_right_led_3_on(void)    { DDRB |=  (1<<7); PORTB |=  (1<<7); }
inline void ergodox_right_led_on(uint8_t led) { DDRB |= (1<<(led+4)); PORTB |= (1<<(led+4)); }

inline void ergodox_board_led_off(void)     { DDRD &= ~(1<<6); PORTD &= ~(1<<6); }
inline void ergodox_right_led_1_off(void)   { DDRB &= ~(1<<5); PORTB &= ~(1<<5); }
inline void ergodox_right_led_2_off(void)   { DDRB &= ~(1<<6); PORTB &= ~(1<<6); }
inline void ergodox_right_led_3_off(void)   { DDRB &= ~(1<<7); PORTB &= ~(1<<7); }
inline void ergodox_right_led_off(uint8_t led) { DDRB &= ~(1<<(led+4)); PORTB &= ~(1<<(led+4)); }

inline void ergodox_led_all_on(void)
{
    ergodox_board_led_on();
    ergodox_right_led_1_on();
    ergodox_right_led_2_on();
    ergodox_right_led_3_on();
}

inline void ergodox_led_all_off(void)
{
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
}

inline void ergodox_right_led_1_set(uint8_t n)    { OCR1A = n; }
inline void ergodox_right_led_2_set(uint8_t n)    { OCR1B = n; }
inline void ergodox_right_led_3_set(uint8_t n)    { OCR1C = n; }
inline void ergodox_right_led_set(uint8_t led, uint8_t n)  {
    (led == 1) ? (OCR1A = n) :
    (led == 2) ? (OCR1B = n) :
                 (OCR1C = n);
}

inline void ergodox_led_all_set(uint8_t n)
{
    ergodox_right_led_1_set(n);
    ergodox_right_led_2_set(n);
    ergodox_right_led_3_set(n);
}

#define KEYMAP(                                                 \
                                                                \
    /* left hand, spatial positions */                          \
    k00,k01,k02,k03,k04,k05,k06,k07 ,                               \
    k10,k11,k12,k13,k14,k15,k16,k17,                               \
    k20,k21,k22,k23,k24,k25,k26,k27,                                    \
    k30,k31,k32,k33,k34,k35,k36,k37,                               \
    k40,k41,k42,k43,k44,k45,k46,k47,                                        \
                                                       \
                                                                \
    /* right hand, spatial positions */                         \
    k08,k09,k0A,k0B,k0C,k0D,                            \
    k18,k19,k1A,k1B,k1C,k1D,                          \
    k28,k29,k2A,k2B,k2C,k2D,                            \
    k38,k39,k3A,k3B,k3C,k3D,                           \
    k48,k49,k4A,k4B,k4C,k4D,                            \
     )                                               \
                                                                \
   /* matrix positions */                                       \
   {                                                            \
    { k00, k10, k20, k30, k40, k50, k60, k70 },   \
    { k01, k11, k21, k31, k41, k51, k61, k71 },   \
    { k02, k12, k22, k32, k42, k52, k62, k72 },   \
    { k03, k13, k23, k33, k43, k53  k63, k73 },   \
    { k04, k14, k24, k34, k44, k54, k64, k74 },   \
    \
                                                                 \
    { k05, k15, k25 k35, k45, k55, KC_NO, KC_NO },   \
    { k06, k16, k26, k36 k46, k56, KC_NO, KC_NO},   \
    { k07, k17, k27, k37, k47, k57, KC_NO, KC_NO },   \
    { k08, k18, k28, k38, k48, k58, KC_NO, KC_NO },   \
    { k09, k19, k29, k39, k49, k59, KC_NO, KC_NO }   \
    }

void matrix_init_user(void);
void matrix_scan_user(void);



#endif
