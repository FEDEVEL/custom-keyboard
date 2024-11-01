#include QMK_KEYBOARD_H

enum layer_names {
    _BASE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_mp10(
        KC_A   , QK_USER_0   , QK_USER_1   ,
        KC_D   , KC_E   , KC_F   ,
        KC_G   , KC_H   , KC_I   ,
        KC_Q   , KC_R   , KC_S  
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) }
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

// void keyboard_post_init_user(void) {
//     rgblight_set_clipping_range(0, 10);
//     rgblight_setrgb_at(0, 0, 0, 9);
//     rgblight_set_clipping_range(0, 9);
// }

enum custom_keycodes {
  SRL = QK_USER_0,
  SBL
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SRL:
      if (record->event.pressed) {
        // Do something when pressed
        // rgblight_set_clipping_range(0, 10);
        // rgblight_setrgb_at(0, 0, 0, 9);
        // rgblight_set_clipping_range(0, 9);


      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    case SBL:
      if (record->event.pressed) {
        // Do something when pressed
        // rgblight_set_clipping_range(0, 10);
        // rgblight_setrgb_at(0, 0, 255, 9);
        // rgblight_set_clipping_range(0, 9);

        
      } else {
        // Do something else when release
      }
      return false; // Skip all further processing of this key
    default:
      return true; // Process all other keycodes normally
  }
}
