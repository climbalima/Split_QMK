// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "melbeachmoose.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = KEYMAP( /* Base */
  KC_ESC,  KC_F1,  KC_F2,  KC_F3, KC_F4, KC_F5,KC_F6, KC_F7, KC_F8, KC_F9,   KC_F10, KC_F11,  KC_F12, KC_DELETE,  KC_PSCR, KC_HOME, KC_END,  KC_VOLU, KC_VOLD, \
  KC_GRV,  KC_1,   KC_2,   KC_3,  KC_4,  KC_5, KC_6,  KC_7,  KC_8,  KC_9,    KC_0,   KC_MINS,  KC_EQL, KC_BSPC,   KC_NLCK, KC_PSLS, KC_PAST, KC_PMNS,      \
  KC_TAB,  KC_Q,   KC_W,   KC_E,  KC_R,  KC_T, KC_Y,  KC_U,  KC_I,  KC_O,    KC_P,   KC_LBRC, KC_RBRC,KC_BSLS,    KC_P7,   KC_P8,   KC_P9, \
  KC_CAPS, KC_A,   KC_S,   KC_D,  KC_F,  KC_G, KC_H,  KC_J,  KC_K,  KC_L,    KC_SCLN,KC_QUOT, KC_ENT,             KC_P4,   KC_P5,   KC_P6,   KC_PPLS, \
  KC_LSFT, KC_Z,   KC_X,   KC_C,  KC_V, KC_B,  KC_N,  KC_M,  KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,                   KC_P1,   KC_P2,   KC_P3,  \
  KC_LCTL, KC_LGUI,KC_LALT,                    KC_SPC,              KC_RALT, KC_RGUI,KC_PAUS, KC_RCTL,            KC_P0,            KC_PDOT, KC_PENT \
),
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};
