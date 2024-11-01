// Copyright 2022 Leon Anavi <leon@anavi.org>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "raw_hid.h"

enum layer_names {
    _BASE
};

enum custom_keycodes {
  CUSTOM_PLAYPAUSE = QK_USER_0/*,
  SBL = QK_USER_1*/
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_mp10(
        KC_Q   , KC_W   , CUSTOM_PLAYPAUSE   ,
	KC_A   , KC_S   , KC_D   ,
	RGB_M_R , RGB_MOD , RGB_TOG
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) }
};
#endif

// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (index == 0) { /* First encoder */
//         if (clockwise) {
//             rgblight_step();
//         } else {
//             rgblight_step_reverse();
//         }
//     }
//     return false;
// }

/*void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t response[length];
    memset(response, 0, length);
    response[0] = 'B';

    if(data[0] == 'A') {
        raw_hid_send(response, length);
    }
}*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CUSTOM_PLAYPAUSE:
      if (record->event.pressed) {
        // Do something when pressed
        uint8_t response[RAW_EPSIZE];
        memset(response, 0, RAW_EPSIZE);
        response[0] = 0x04;
        response[1] = 0x3C;
        //response[13] = 0xA2;
        //response[14] = 0xC0;
        raw_hid_send(response, RAW_EPSIZE);

      } else {
        uint8_t response[RAW_EPSIZE];
        memset(response, 0, RAW_EPSIZE);
        response[0] = 0x04;
        //response[13] = 0xF2;
        //response[14] = 0x90;
        raw_hid_send(response, RAW_EPSIZE);
      }
      return false; // Skip all further processing of this key
      
    default:
      return true; // Process all other keycodes normally
  }
}