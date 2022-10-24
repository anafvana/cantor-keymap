#include QMK_KEYBOARD_H

enum cantor_layers {
  _QWERTY,
  _RAISE
};

enum unicode_names {
    LC_AE,
    UC_AE,
    CIRCUMFLEX,
    SUN,
};

const uint32_t PROGMEM unicode_map[] = {
    [LC_AE] = 0xE6,
    [UC_AE] = 0xC6, 
    [CIRCUMFLEX] = 0x5E, 
    [SUN]  = 0xA4, 
};

#define RAISE MO(_RAISE)
#define KC_AE XP(LC_AE, UC_AE)
#define CIRCSUN XP(CIRCUMFLEX, SUN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Esc│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Tab│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │Ent│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │' "│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Alt│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Rai│
      *               └───┤Ctl├───┐   ┌───┤   ├───┘
      *                   └───┤Sft│   │Sft├───┘
      *                       └───┘   └───┘
      */
    [_QWERTY] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
        KC_QUOT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                            KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LALT,
                                            KC_LGUI, KC_LCTL, KC_LSFT,       KC_RSFT, KC_SPC,  RAISE
    ),


/* Raise
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ 0 │ 1 │ 2 │ 3 │^ ¤│       │   │   │   │   │Psc│Del│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ - │ 4 │ 5 │ 6 │ \|│       │Lft│Dwn│Up │Rgt│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │` ~│ = │ 7 │ 8 │ 9 │ æ │       │   │ ( |[{ | ]}| ) │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_RAISE] = LAYOUT_split_3x6_3(
        _______, KC_0,    KC_1,    KC_2,    KC_3,    CIRCSUN,                           _______, _______, _______, _______, KC_PSCR, KC_DEL,
        _______, KC_MINS, KC_4,    KC_5,    KC_6,    KC_BSLS,                          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        KC_GRV,  KC_EQL,  KC_7,    KC_8,    KC_9,    KC_AE,                            _______, KC_LPRN, KC_LBRC, KC_RBRC, KC_RPRN, _______,
                                            _______, _______, _______,        _______, _______, _______
    )
};
