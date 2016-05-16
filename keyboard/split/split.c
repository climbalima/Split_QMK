#include "split.h"
#include "c44-util.h"
#include "lufa.h"


__attribute__ ((weak))
void matrix_init_user(void) {
	// leave this function blank - it can be defined in a keymap file
};

__attribute__ ((weak))
void matrix_scan_user(void) {
	// leave this function blank - it can be defined in a keymap file
}

__attribute__ ((weak))
void process_action_user(keyrecord_t *record) {
	// leave this function blank - it can be defined in a keymap file
}

__attribute__ ((weak))
void led_set_user(uint8_t usb_led) {
	// leave this function blank - it can be defined in a keymap file
}

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up

	matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	matrix_scan_user();
}

void process_action_kb(keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware

	process_action_user(record);
}

void led_set_kb(uint8_t usb_led) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

	led_set_user(usb_led);
}
void matrix_slave_scan(void);

int main(void)  __attribute__ ((weak));
int main(void)
{
    setup_hardware();
    setup_set_handedness();
    sei();

    /* wait for USB startup to get ready for debug output */
    uint8_t timeout = 200;  // timeout when USB is not available
    while (timeout-- && USB_DeviceState != DEVICE_STATE_Configured) {
         _delay_us(5);
#if defined(INTERRUPT_CONTROL_ENDPOINT)
        ;
#else
        USB_USBTask();
#endif
    }

    /* if (USB_DeviceState != DEVICE_STATE_Configured) { */
    if (!has_usb()) {
        // USB failed to connect, so run this device in slave mode.
        matrix_init();
        serial_slave_init();

        while (1) {
            matrix_slave_scan();
        }
    }

    /* init modules */
    keyboard_init();
    host_set_driver(&lufa_driver);

#ifdef SLEEP_LED_ENABLE
    sleep_led_init();
#endif
#ifdef RGBLIGHT_ENABLE
        rgblight_init();
#endif
    while (1) {
        keyboard_task();

#if !defined(INTERRUPT_CONTROL_ENDPOINT)
        USB_USBTask();
#endif
    }
}
