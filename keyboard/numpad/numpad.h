#ifndef NUMPAD_H
#define NUMPAD_H

#include "matrix.h"
#include "keymap_common.h"
#include "backlight.h"
#include <stddef.h>

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
    k00, k01, k02, k03, \
    k10,  k11, k12,   \
    k20, k21, k22, k23, \
    k30, k31, k32,  \
    k40, k41, k42 \
) \
{ \
    { k00, k01, k02, k03 }, \
    { k10, k11, k12, KC_NO }, \
    { k20, k21, k22, k23 }, \
    { k30, k31, k32, KC_NO }, \
    { KC_NO, k40, k41, k42 } \
}

void matrix_init_user(void);
void matrix_scan_user(void);
void process_action_user(keyrecord_t *record);
void led_set_user(uint8_t usb_led);

#endif
