#include QMK_KEYBOARD_H
#include <keymap_swedish.h>

# define PASTE S(KC_INS)
enum layer_number {
  _QWERTY = 0,
  _SVDVORAK,
  _LOWER,
  _RAISE,
  _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_SVDVORAK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  +   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  Å   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  |  Ä   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_PLUS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    SE_ARNG,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    SE_ODIA, SE_ADIA,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, SE_LBRC,  SE_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  SE_MINS,  KC_RSFT,
                        KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_RGUI
),
/* SVDVORAK-ish
 */

 [_SVDVORAK] = LAYOUT(
  KC_ESC,   KC_1,    KC_2,    KC_3,   KC_4,  KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    SE_PLUS,
  KC_TAB,   SE_ADIA, KC_COMM, KC_DOT, KC_P,  KC_Y,                     KC_F, KC_G,  KC_C, KC_R, KC_L, SE_ARNG,
  KC_LCTL,  KC_A,    KC_O,    KC_E,   KC_U,  KC_I,                     KC_D, KC_H,  KC_T, KC_N, KC_S, SE_MINS,
  KC_LSFT,  SE_ODIA, KC_Q,    KC_J,   KC_K,  KC_X, SE_LBRC,  SE_RBRC,  KC_B, KC_M,  KC_W, KC_V, KC_Z, KC_RSFT,
                        KC_LGUI, KC_LALT, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_RGUI
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  | Home |                    |S(Ins)|   7  |   8  |   9  | PgUp |  Ins |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |  End |-------.    ,-------|  Del |   4  |   5  |   6  | PgDn |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |   ^  |-------|    |-------|   ~  |   1  |   2  |   3  |   0  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______,_______, _______, _______,
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_HOME,                   PASTE,   KC_7,    KC_8,   KC_9,    KC_PGUP, KC_INS,
  _______, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_END ,                   KC_DEL,  KC_4,    KC_5,   KC_6,    KC_PGDN, XXXXXXX,
  _______, KC_F9,   KC_F10,  KC_F11,  KC_F12,  SE_CIRC, _______, _______, SE_TILD, KC_1,    KC_2,   KC_3,    KC_0,    _______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   §  |   ¨  |   £  |   €  |   ¤  |                    |      |      |   ´  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   !  |   @  |   {  |   }  |   /  |                    |   %  |   |  |   `  |   *  |   -  |   +  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   #  |   &  |   (  |   )  |   $  |-------.    ,-------| Left | Down |  Up  |Right |   =  |   ?  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |      |   \  |   "  |   [  |   ]  |   '  |-------|    |-------|   <  |   >  |   ;  |   :  |   _  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, SE_SECT, SE_DIAE, SE_PND,  SE_EURO, SE_CURR,                     _______, _______, SE_ACUT, _______, _______, _______,
  _______, SE_EXLM, SE_AT,   SE_LCBR, SE_RCBR, SE_SLSH,                     SE_PERC, SE_PIPE, SE_GRV,  SE_ASTR, SE_MINS, SE_PLUS,
  _______, SE_HASH, SE_AMPR, SE_LPRN, SE_RPRN, SE_DLR,                      KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, SE_EQL,  SE_QUES,
  _______, SE_BSLS, SE_DQUO, SE_LBRC, SE_RBRC, SE_QUOT,  _______, _______,  SE_LABK, SE_RABK, SE_SCLN, SE_COLN, SE_UNDS, _______,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX,KC_QWERTY,KC_SVDVORAK,XXXXXXX,XXXXXXX,                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, UG_TOGG, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_NEXT, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  switch (keycode) {
      case KC_QWERTY:
          if (record->event.pressed) {
              set_single_persistent_default_layer(_QWERTY);
          }
          return false;
      case KC_SVDVORAK:
          if (record->event.pressed) {
              set_single_persistent_default_layer(_SVDVORAK);
          }
          return false;
  }
  return true;
}
