#include QMK_KEYBOARD_H

enum layers {
  _QWERTY = 0,
  _COLEMAK,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NUM,
};

/*
enum {
    TD_MNXT_MPRV = 0,
    TD_MPLY_MSEL
};
*/

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define NUMBR  MO(_NUM)

#define KY_TABG LGUI_T(KC_TAB)
#define KY_ESCC LCTL_T(KC_ESC)

#define NXT_PRV TD(TD_MNXT_MPRV)
#define PLY_SEL TD(TD_MPLY_MSEL)
#define KY_ZMIN LCTL(KC_EQL)
#define KY_ZOUT LCTL(KC_MINS)
#define KY_ZRST LCTL(KC_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
  KY_TABG, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
  KY_ESCC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  NUMBR,   KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
),

[_COLEMAK] = LAYOUT(
  KY_TABG, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
  KY_ESCC, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
  NUMBR,   KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_ENT,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT
),

[_LOWER] = LAYOUT(
  KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
  KC_ESC,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_PIPE, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_GRV,
  _______, KC_BSPC, KC_DQUO, KC_MINS, KC_SLSH, KC_DOT,  KC_BSLS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_TILD,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______
),

[_RAISE] = LAYOUT(
  _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F11,  KC_DEL,
  _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_F12,  KC_INS,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLD, KC_VOLU, _______
),

[_ADJUST] = LAYOUT(
  QK_BOOT, _______, _______, _______, _______, _______,   _______,      _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,   _______,      KC_BRID, KC_BRIU, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,   _______,      _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,   TG(_COLEMAK), _______, _______, _______, _______, _______
),

[_NUM] = LAYOUT(
  KY_ZMIN, KC_P7  , KC_P8  , KC_P9  , KC_PMNS, KC_BSPC , _______, _______, _______, _______, _______, _______,
  KY_ZOUT, KC_P4  , KC_P5  , KC_P6  , KC_PPLS, _______, _______, _______, _______, _______, _______, _______,
  KY_ZRST, KC_P1  , KC_P2  , KC_P3  , KC_PSLS, KC_PAST, _______, _______, _______, _______, _______, _______,
  _______, KC_P0  , KC_P0  , KC_PDOT, KC_PENT, _______, _______, _______, _______, _______, _______, _______
)
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/*
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_MNXT_MPRV] = ACTION_TAP_DANCE_DOUBLE(KC_MNXT, KC_MPRV),
    [TD_MPLY_MSEL] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MSEL)
};
*/

// void keyboard_post_init_user(void) {
//     debug_enable=true;
//     debug_matrix=true;
// }
