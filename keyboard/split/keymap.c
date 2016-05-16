/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"
#include "keymap_common.h"


/* const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    KEYMAP(
        /* left hand */
           KC_ESC   , KC_Q   , KC_W    , KC_E    , KC_R    , KC_T    , 
           KC_TAB   , KC_A   , KC_S    , KC_D    , KC_F    , KC_G    , 
           KC_LSFT  , KC_Z   , KC_X    , KC_C    , KC_V    , KC_B    , 
           KC_LCTL  , KC_LCTL , KC_LGUI , KC_LALT , KC_FN9  , KC_SPC ,  
        /* right hand */
           KC_Y    , KC_U   , KC_I    , KC_O    , KC_P    , KC_BSPC , 
           KC_H    , KC_J   , KC_K    , KC_L    , KC_SCLN , KC_QUOT , 
           KC_N    , KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_ENT , 
           KC_SPC , KC_FN8 , KC_LEFT , KC_DOWN , KC_UP, KC_RGHT 
        )
    ,
        
   KEYMAP(
           KC_GRV    , KC_1     , KC_2     , KC_3          , KC_4          , KC_5  , 
           KC_TRNS   , KC_F1  , KC_F2     , KC_F3          , KC_F4         , KC_F5 , 
           KC_TRNS   , KC_F7    , KC_F8    , KC_F9         , KC_F10        , KC_F11, 
           KC_TRNS   , KC_TRNS  , KC_TRNS  , KC_TRNS       , KC_TRNS       , KC_TRNS,  
        /* right hand */
           KC_6  , KC_7    , KC_8   , KC_9    , KC_0   , KC_DELETE , 
           KC_F6 , KC_LBRC , KC_RBRC, KC_MINS , KC_EQL , KC_BSLS , 
           KC_F12, KC_TRNS , KC_TRNS, KC_TRNS , KC_TRNS , KC_TRNS , 
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS , KC_TRNS 
        )
      , 
    
    KEYMAP(
       /* left hand */
           SHIFT(KC_GRV), SHIFT(KC_1) , SHIFT(KC_2), SHIFT(KC_3)   , SHIFT(KC_4), SHIFT(KC_5) ,  
           KC_TRNS      , KC_TRNS     , KC_TRNS    , KC_TRNS       , KC_TRNS    , KC_TRNS     , 
          KC_FN0,     KC_FN1,     KC_FN2,     KC_FN3,     KC_FN4,     KC_FN5,      
           KC_FN6,     KC_FN7, KC_TRNS , KC_TRNS , KC_TRNS, KC_TRNS ,
        /* right hand */
           SHIFT(KC_6), SHIFT(KC_7)   , SHIFT(KC_8)   , SHIFT(KC_9)    , SHIFT(KC_0)  , KC_TRNS , 
           KC_TRNS    , SHIFT(KC_LBRC), SHIFT(KC_RBRC), SHIFT(KC_MINS) , SHIFT(KC_EQL) , SHIFT(KC_BSLS)  , 
          KC_TRNS      , KC_F1       , KC_F2      , KC_F3         , KC_F4      , KC_F5       , 
           KC_TRNS      , KC_TRNS     , KC_TRNS    , KC_TRNS       , KC_TRNS    , KC_TRNS     
        )
    ,
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
  [0]  = ACTION_FUNCTION(RGBLED_TOGGLE),
  [1]  = ACTION_FUNCTION(RGBLED_STEP_MODE),
  [2]  = ACTION_FUNCTION(RGBLED_INCREASE_HUE),
  [3]  = ACTION_FUNCTION(RGBLED_DECREASE_HUE),
  [4]  = ACTION_FUNCTION(RGBLED_INCREASE_SAT),
  [5]  = ACTION_FUNCTION(RGBLED_DECREASE_SAT),
  [6]  = ACTION_FUNCTION(RGBLED_INCREASE_VAL),
  [7]  = ACTION_FUNCTION(RGBLED_DECREASE_VAL),
  [8] ACTION_LAYER_MOMENTARY(1),
  [9] ACTION_LAYER_MOMENTARY(2),
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
