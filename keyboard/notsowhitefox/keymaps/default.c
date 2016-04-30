// This is the canonical layout file for the Quantum project. If you want to add another keyboard,
// this is the style you want to emulate.

#include "notsowhitefox.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = KEYMAP( /* Base */
  KC_ESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,  KC_EQL,   KC_BSPC, KC_DEL, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,  KC_RBRC,  KC_BSLS, KC_PGUP, \
  MO(1),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,            KC_ENT, KC_PGDN, \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,  KC_RSFT, KC_UP,  DF(2),\
  KC_LCTL, KC_LGUI,KC_LALT,          KC_SPC,                                        F(1),  F(2),  KC_LEFT, KC_DOWN, KC_RGHT
),
[1] = KEYMAP(
 KC_GRV, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,     KC_F10,    KC_F11,    KC_F12,    KC_DEL,  KC_TRNS,  \
  KC_TRNS,KC_TRNS,KC_UP,  KC_TRNS,KC_CALC,KC_INS, KC_TRNS,KC_PGUP,KC_TRNS, KC_TRNS,   KC_PSCR,   KC_SLCK,   KC_PAUS,   KC_TRNS, KC_TRNS, \
  KC_TRNS,KC_LEFT,KC_DOWN,KC_RGHT,KC_TRNS,KC_HOME,KC_LEFT,KC_DOWN,KC_UP,   KC_RGHT,   KC_END,    KC_TRNS,       KC_TRNS,       KC_TRNS, \
  KC_TRNS,        BL_DEC, BL_TOGG,BL_INC, KC_TRNS,   KC_TRNS,KC_PGDN,KC_TRNS, KC_VOLD,   KC_MUTE,   KC_VOLU,    KC_TRNS, KC_TRNS,   KC_PGUP, \
  KC_TRNS,KC_TRNS,KC_TRNS,          KC_TRNS,                               KC_APP,    KC_HOME, KC_TRNS, KC_TRNS, KC_END
  ),
[2] = KEYMAP(
  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_TRNS,\
  KC_NO,  KC_NO,  KC_UP,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  BL_DEC, BL_INC, BL_TOGG, KC_TRNS,\
  KC_NO,  KC_LEFT,KC_DOWN,KC_RGHT,KC_NO,  KC_HOME,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_END, KC_NO,  KC_NO, KC_NO, \
  KC_NO,          F(1),     F(2),     F(3),     F(4),     F(5),     F(6),     F(7),     F(8),   KC_NO,  KC_NO, KC_UP,KC_TRNS, KC_TRNS, \
  KC_NO,  KC_NO,  KC_NO,         DF(0),                                         KC_TRNS,  KC_LEFT, KC_DOWN, KC_TRNS, KC_TRNS
  )
};
enum function_id {
    RGBLED_TOGGLE,
    RGBLED_STEP_MODE,
    RGBLED_INCREASE_HUE,
    RGBLED_DECREASE_HUE,
    RGBLED_INCREASE_SAT,
    RGBLED_DECREASE_SAT,
    RGBLED_INCREASE_VAL,
    RGBLED_DECREASE_VAL,
};

const uint16_t PROGMEM fn_actions[] = {
  [0]  = ACTION_LAYER_TAP_KEY(2, KC_SPC),
  [1]  = ACTION_FUNCTION(RGBLED_TOGGLE),
  [2]  = ACTION_FUNCTION(RGBLED_STEP_MODE),
  [3]  = ACTION_FUNCTION(RGBLED_INCREASE_HUE),
  [4]  = ACTION_FUNCTION(RGBLED_DECREASE_HUE),
  [5]  = ACTION_FUNCTION(RGBLED_INCREASE_SAT),
  [6]  = ACTION_FUNCTION(RGBLED_DECREASE_SAT),
  [7]  = ACTION_FUNCTION(RGBLED_INCREASE_VAL),
  [8]  = ACTION_FUNCTION(RGBLED_DECREASE_VAL),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
  switch (id) {
    case RGBLED_TOGGLE:
      //led operations
      if (record->event.pressed) {
        rgblight_toggle();
      }

      break;
    case RGBLED_INCREASE_HUE:
      if (record->event.pressed) {
        rgblight_increase_hue();
      }
      break;
    case RGBLED_DECREASE_HUE:
      if (record->event.pressed) {
        rgblight_decrease_hue();
      }
      break;
    case RGBLED_INCREASE_SAT:
      if (record->event.pressed) {
        rgblight_increase_sat();
      }
      break;
    case RGBLED_DECREASE_SAT:
      if (record->event.pressed) {
        rgblight_decrease_sat();
      }
      break;
      case RGBLED_INCREASE_VAL:
        if (record->event.pressed) {
          rgblight_increase_val();
        }
        break;
      case RGBLED_DECREASE_VAL:
        if (record->event.pressed) {
          rgblight_decrease_val();
        }
        break;
      case RGBLED_STEP_MODE:
        if (record->event.pressed) {
          rgblight_step();
        }
        break;
  }
}
