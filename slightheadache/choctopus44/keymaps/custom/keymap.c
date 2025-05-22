/* Copyright 2021 SlightHeadache
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC, \
    KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT, \
    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_MPLY,   KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT, \
                        RAISE,    KC_ESC,   KC_LSFT,   KC_BSPC,            KC_SPC,   LOWER,    KC_CAPS,  KC_RGUI   \
  ),
  
  [_LOWER] = LAYOUT(
    KC_TAB,   ADJUST,   KC_AMPR,  KC_UP,    KC_ASTR,  KC_GRV,              KC_EQL,  KC_7,    KC_8,    KC_9,    KC_DOT,  KC_BSPC, \
    KC_LCTL,  KC_UNDS,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_AT,               KC_MINS, KC_4,    KC_5,    KC_6,    KC_LPRN, KC_RPRN, \
    KC_LALT,  KC_DEL,   KC_BSLS,  KC_SLSH,  KC_PIPE,  KC_DQUO,   KC_MUTE,  KC_0,    KC_1,    KC_2,    KC_3,    KC_LBRC, KC_RBRC, \
                        _______,  KC_ESC,   KC_LSFT,  KC_BSPC,             KC_SPC,  _______, KC_CAPS,  KC_RGUI \
  ),
  
  [_RAISE] = LAYOUT(
    _______, _______,  _______,  _______,  _______,  _______,             KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6, \
    KC_LCTL, KC_LALT,  KC_DEL,   _______,  _______,  _______,             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, \
    _______, _______,  _______,  _______,  _______,  _______,    KC_ENT, _______,  _______, _______, _______, _______,  _______, \
                      _______,  _______,  _______,   _______,             _______,  _______,  _______,  _______ \
  ),
  
  [_ADJUST] = LAYOUT(
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  KC_PSCR,  XXXXXXX,  KC_PAUSE, XXXXXXX, \
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  KC_INS,   KC_HOME,  KC_PGUP,  XXXXXXX, \
    XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_DEL,   KC_END,   KC_PGDN,  XXXXXXX, \
                        _______,  _______,  _______,   _______,            _______,  _______,  _______,  _______ \
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
    return true;
}
