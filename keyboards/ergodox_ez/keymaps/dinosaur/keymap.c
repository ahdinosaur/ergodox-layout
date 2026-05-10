#include QMK_KEYBOARD_H
#include "version.h"

// keyboard-helper integration (submodule at ./keyboard-helper).
// The ID must match a table key in the host's `keymaps.toml`.
#define KEYBOARD_HELPER_ID "ergodox-ez-dinosaur"
#include "keyboard_helper.h"

enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,  // print firmware version
};

// Keycode reference: https://docs.qmk.fm/keycodes
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------| LMeta|           | RMeta|------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv   | Ctrl | Alt  | Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L2  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LMeta|       | Alt  | Ctrl |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Back |Delete|------|       |------| Enter  |Space |
 *                                 | space|      | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
    // left hand
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    TG(SYMB),
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,
    KC_GRV,  KC_LCTL, KC_LALT, KC_LEFT, KC_RGHT,

                                                 ALT_T(KC_APP), KC_LGUI,
                                                                KC_HOME,
                                        KC_BSPC, KC_DEL,        KC_END,

    // right hand
    KC_RGHT,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,           KC_MINS,
    TG(SYMB), KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,           KC_BSLS,
              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,        KC_QUOT,
    KC_RGUI,  KC_N,    KC_M,    KC_COMM, KC_DOT,  CTL_T(KC_SLSH), KC_RSFT,
                       KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC,        MO(MDIA),

    KC_LALT, KC_RCTL,
    KC_PGUP,
    KC_PGDN, KC_ENT, KC_SPC
),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |EE_CLR|      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
    // left hand
    VRSN,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
    _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, _______,
    _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,
    _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______,
    EE_CLR,  _______, _______, _______, _______,

                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,

    // right hand
    _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
             KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, _______,
    _______, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, _______,
                      _______, KC_DOT,  KC_0,    KC_EQL,  _______,

    _______, _______,
    _______,
    _______, _______, _______
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
    // left hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, MS_UP,   _______, _______, _______,
    _______, _______, MS_LEFT, MS_DOWN, MS_RGHT, _______,
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, MS_BTN1, MS_BTN2,

                                                 _______, _______,
                                                          _______,
                                        _______, _______, _______,

    // right hand
    _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,
             _______, _______, _______, _______, _______, KC_MPLY,
    _______, _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                      KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,

    _______, _______,
    _______,
    _______, _______, KC_WBAK
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    keyboard_helper_on_key_event(keycode, record);
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    keyboard_helper_on_layer_state(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (get_highest_layer(state)) {
        case SYMB:
            ergodox_right_led_1_on();
            break;
        case MDIA:
            ergodox_right_led_2_on();
            break;
        default:
            break;
    }

    return state;
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    keyboard_helper_on_raw_hid(data, length);
}
