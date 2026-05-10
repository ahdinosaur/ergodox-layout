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

// Override the helper's default `row * MATRIX_COLS + col` because the
// `LAYOUT_ergodox` macro permutes the matrix into physical-visual
// order. The host-side visualizer keys positions off LAYOUT-arg index
// (= the flat key order in ergodox-ez-dinosaur.yaml), so without this
// override every press would highlight the wrong cell. Layer
// indication does not depend on position and works either way.
//
// The map is derived from
// `qmk_firmware/keyboards/ergodox_ez/info.json` →
// `layouts.LAYOUT_ergodox.layout`: each entry there is one LAYOUT
// argument, and its `matrix: [row, col]` field gives the matrix
// position that argument fills. The 8 entries written `KH_NO_POS`
// are matrix slots with no physical key; a correctly wired ergodox
// will never fire an event from them, but a deliberate sentinel
// beats falling back to a default that would alias a valid index.
#define KH_NO_POS 0xFFFFu

// Pin the table to the matrix shape it was hand-built for. If QMK
// ever changes the ergodox_ez matrix dimensions the array would
// resize silently and the extra slots would default-init to 0 — a
// valid LAYOUT index — aliasing every press into the top-left key.
_Static_assert(MATRIX_ROWS == 14 && MATRIX_COLS == 6,
               "kh_layout_arg_index is hand-derived for ergodox_ez 14x6; "
               "regenerate from info.json if matrix dims change.");

static const uint16_t kh_layout_arg_index[MATRIX_ROWS][MATRIX_COLS] PROGMEM = {
    // Left half. col 5 = left thumb cluster.
    /*  0 */ {  0,  7, 14, 20, 27, KH_NO_POS },
    /*  1 */ {  1,  8, 15, 21, 28, 37 },
    /*  2 */ {  2,  9, 16, 22, 29, 36 },
    /*  3 */ {  3, 10, 17, 23, 30, 35 },
    /*  4 */ {  4, 11, 18, 24, 31, 34 },
    /*  5 */ {  5, 12, 19, 25, KH_NO_POS, 32 },
    /*  6 */ {  6, 13, KH_NO_POS, 26, KH_NO_POS, 33 },
    // Right half. col 5 = right thumb cluster.
    /*  7 */ { 38, 45, KH_NO_POS, 58, KH_NO_POS, 70 },
    /*  8 */ { 39, 46, 52, 59, KH_NO_POS, 71 },
    /*  9 */ { 40, 47, 53, 60, 65, 72 },
    /* 10 */ { 41, 48, 54, 61, 66, 75 },
    /* 11 */ { 42, 49, 55, 62, 67, 74 },
    /* 12 */ { 43, 50, 56, 63, 68, 73 },
    /* 13 */ { 44, 51, 57, 64, 69, KH_NO_POS },
};

uint16_t keyboard_helper_position_from_keypos(keypos_t key) {
    if (key.row >= MATRIX_ROWS || key.col >= MATRIX_COLS) {
        return KH_NO_POS;
    }
    return pgm_read_word(&kh_layout_arg_index[key.row][key.col]);
}
