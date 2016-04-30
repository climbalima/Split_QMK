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
           KC_ESC   , KC_1, KC_2, KC_3, KC_4, KC_5, 
           KC_TAB   , KC_Q   , KC_W    , KC_E    , KC_R    , KC_T    ,
           KC_FN0  , KC_A   , KC_S    , KC_D    , KC_F    , KC_G    , 
           KC_LSFT  , KC_Z   , KC_X    , KC_C    , KC_V    , KC_B    , 
           KC_LCTL  , KC_LCTL , KC_LGUI , KC_LALT , KC_SPC  , KC_SPC , 
        /* right hand */
           KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, 
           KC_Y    , KC_U   , KC_I    , KC_O    , KC_P    , KC_LBRC, KC_RBRC, KC_BSLS , 
           KC_H    , KC_J   , KC_K    , KC_L    , KC_SCLN , KC_QUOT , KC_ENT, KC_DELETE, 
           KC_N    , KC_M   , KC_COMM , KC_DOT  , KC_SLSH , KC_RSFT , KC_UP, KC_FN0,
           KC_SPC , KC_SPC, KC_FN0, KC_RGUI, KC_RCTL, KC_LEFT , KC_DOWN ,  KC_RGHT 
        )
    ,
        
   KEYMAP(
           KC_GRV    , KC_F1     , KC_F2     , KC_F3          , KC_F4          , KC_F5  , 
           KC_TRNS   , KC_F1  , KC_F2     , KC_F3          , KC_F4         , KC_F5 , 
           KC_TRNS   , KC_F7    , KC_F8    , KC_F9         , KC_F10        , KC_F11, 
           KC_TRNS   , KC_TRNS  , KC_TRNS  , KC_TRNS       , KC_TRNS       , KC_TRNS ,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 

        /* right hand */
           KC_F6  , KC_F7    , KC_F8   , KC_F9    , KC_F10,   KC_F11, KC_F12, KC_DELETE , 
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , 
           KC_TRNS, KC_TRNS , KC_TRNS, KC_TRNS , KC_TRNS , KC_TRNS , KC_TRNS, KC_TRNS, 
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS , KC_TRNS , KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
        )
      , 
};

/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
   [0] ACTION_LAYER_MOMENTARY(1),
};