#include QMK_KEYBOARD_H

enum layer_names {
    _BASE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_mp10(
        QK_USER_0   , KC_A   ,  KC_A  ,
        KC_A   , KC_A   , KC_A   ,
        KC_A   , KC_A   , KC_A   ,
        KC_A   , KC_A   , KC_A  
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT) }
};
#endif

void keyboard_pre_init_user(void) {
  setPinOutput(GP26);
  setPinOutput(GP27);
  setPinOutput(GP28);
}

void keyboard_post_init_user(void) {
  writePinHigh(GP26);
  writePinHigh(GP27);
  writePinHigh(GP28);
}

enum custom_keycodes {
  LAYER_SCROLL = QK_USER_0
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LAYER_SCROLL:
      if (!record->event.pressed) {
        //Already handled the keycode, no further processing is needed
        return false;
      }

      uint8_t current_layer = get_highest_layer(layer_state);
      if (current_layer > 3 || current_layer < 0) {
        return false;
      }

      uint8_t next_layer = current_layer + 1;
      if (next_layer > 3) {
        next_layer = 0;
      }

      if (next_layer == 0) {
        writePinHigh(GP26);
        writePinHigh(GP27);
        writePinHigh(GP28);
      }
      if (next_layer == 1) {
        writePinLow(GP26);
        writePinHigh(GP27);
        writePinHigh(GP28);
      }
      if (next_layer == 2) {
        writePinHigh(GP26);
        writePinLow(GP27);
        writePinHigh(GP28);
      }
      if (next_layer == 3) {
        writePinHigh(GP26);
        writePinHigh(GP27);
        writePinLow(GP28);
      }

      layer_move(next_layer);
      
      return false;
    default:
      return true; //Process all other keycodes normally
  }
}