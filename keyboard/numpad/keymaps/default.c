// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "numpad.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = KEYMAP( /* Base */
  KC_NLCK,  KC_PSLS,  KC_PAST, KC_PMNS, \
  KC_P7, KC_P8, KC_P9,   \
  KC_P4, KC_P5, KC_P6, KC_PPLS, \
  KC_P1, KC_P2, KC_P3, \
  KC_P0, KC_PDOT, KC_PENT \
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
