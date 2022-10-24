#include QMK_KEYBOARD_H

enum cantor_layers {
  _QWERTY,
  _RAISE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │Sft│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Esc│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Alt│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Ent│
      *               └───┤Ctl├───┐   ┌───┤Rai├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_QWERTY] = LAYOUT_split_3x6_3(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSFT,
        KC_ESC,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RALT,
                                            KC_LGUI, KC_LCTL, KC_SPC,        KC_SPC,  RAISE,   KC_ENT
    ),


/* Raise
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ 0 │ 1 │ 2 │ 3 │` ~│       │   │   │   │   │Psc│Del│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ - │ 4 │ 5 │ 6 │' "│       │Lft│Dwn│Up │Rgt│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ = │ 7 │ 8 │ 9 │ \|│       │   │ ( |[{ | ]}| ) │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Rbt├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_RAISE] = LAYOUT_split_3x6_3(
        _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_GRV,                           _______, _______, _______, _______, KC_PSCR, KC_DEL,
        _______, KC_MINS, KC_4,    KC_5,    KC_6,    KC_QUOT,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_BSLS,                          _______, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, _______,
                                            QK_BOOT, _______, _______,        _______, _______, _______
    )
};
