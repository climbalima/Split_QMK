#ifndef MELBEACHMOOSE_H
#define MELBEACHMOOSE_H

#include "matrix.h"
#include "keymap_common.h"
#include "backlight.h"
#include <stddef.h>

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguements
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, k0f, k0g, k0h, k0i, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, k1d, k1e, k1f, k1g, k1h,  \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, k2e, k2f, \
    k30, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, k3c, k3d, k3e, k3f, k3g, \
    k40, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, k4c, k4d, k4e, \
    k50, k51, k52, k53, k54, k55, k56, k57, k58, k59, k5a, k5b \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, k0c, k0d, k0e, k0f, k0g, k0h, k0i }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, k1c, KC_NO, k1d, k1e, k1f, k1g, k1h }, \
    { k20, KC_NO, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, k2c, k2d, k2e, k2f, KC_NO }, \
    { k30, KC_NO, k31, k32, k33, k34, k35, k36, k37, k38, k39, k3a, k3b, KC_NO, k3c,  k3d,  k3e, k3f, k3g}, \
    { k40, KC_NO, k41, k42, k43, k44, k45, k46, k47, k48, k49, k4a, k4b, KC_NO, k4c, k4d, k4e, KC_NO}, \
    { k50, KC_NO,  k51, k52, KC_NO, KC_NO, KC_NO,  k53, KC_NO, KC_NO, KC_NO, k54, k55, k56, k57, k58,KC_NO, k59, k5a, k5b} \
}

void matrix_init_user(void);
void matrix_scan_user(void);
void process_action_user(keyrecord_t *record);
void led_set_user(uint8_t usb_led);

#endif
