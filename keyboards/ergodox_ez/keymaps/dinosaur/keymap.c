#include QMK_KEYBOARD_H

// Layers. Higher numbers win when multiple are held; SYM sits on top so it
// can stack onto NUM/NAV/MED/FUN when both a primary/tertiary trigger and a
// secondary trigger are pressed at the same time.
enum layers {
    BASE,
    NUM,
    NAV,
    MED,
    FUN,
    SYM,
};

enum custom_keycodes {
    RIGHT_ARROW = SAFE_RANGE,
};

enum tap_dance_indices {
    TD_BOOT,
    TD_LC,
    TD_LO,
};

// Home-row mod-tap aliases (GACS).
#define HM_A LGUI_T(KC_A)
#define HM_R LALT_T(KC_R)
#define HM_S LCTL_T(KC_S)
#define HM_T LSFT_T(KC_T)
#define HM_N RSFT_T(KC_N)
#define HM_E RCTL_T(KC_E)
#define HM_I RALT_T(KC_I)
#define HM_O RGUI_T(KC_O)

// Layer-tap thumb aliases.
#define LT_ESC LT(MED, KC_ESC)
#define LT_BSP LT(NUM, KC_BSPC)
#define LT_DEL LT(SYM, KC_DEL)
#define LT_ENT LT(SYM, KC_ENT)
#define LT_SPC LT(NAV, KC_SPC)
#define LT_TAB LT(FUN, KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// BASE — Colemak with home-row mods on the home row and layer-tap thumbs.
// Ergodox-extras outside the 3x5+3 design area keep their values from the
// previous keymap (no conflict with the new design).
[BASE] = LAYOUT_ergodox(
    // ---- LEFT HAND ----
    // Row 0 (top — extras above the alpha grid)
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_LEFT,
    // Row 1 (alphas Q W F P G at args 1..5)
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_NO,
    // Row 2 (alphas A R S T D at args 1..5; home-row mods)
    KC_ESC,  HM_A,    HM_R,    HM_S,    HM_T,    KC_D,
    // Row 3 (alphas Z X C V B at args 1..5)
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LGUI,
    // Row 4 (extras below alphas)
    KC_GRV,  KC_LCTL, KC_LALT, KC_LEFT, KC_RGHT,
    // Left thumb cluster: args 0..5
    //   0=upper-outer (extra), 1=upper-inner (extra),
    //   2=inner-top  (LT SYM DEL),
    //   3=outer      (LT MED ESC),
    //   4=middle     (LT NUM BSP),
    //   5=inner-bot  (extra)
                                                 KC_LALT, KC_LGUI,
                                                          LT_DEL,
                                        LT_ESC,  LT_BSP,  KC_END,

    // ---- RIGHT HAND ----
    // Row 0 (top — extras)
    KC_RGHT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    // Row 1 (alphas J L U Y ; at args 1..5)
    KC_NO,   KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
    // Row 2 (alphas H N E I O at args 0..4 — note: row 2 has only 6 args; outer-pinky extra is arg 5)
             KC_H,    HM_N,    HM_E,    HM_I,    HM_O,    KC_QUOT,
    // Row 3 (alphas K M , . / at args 1..5)
    KC_RGUI, KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    // Row 4 (extras)
                      KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, KC_NO,
    // Right thumb cluster: args 0..5
    //   0=upper-inner (extra), 1=upper-outer (extra),
    //   2=inner-top  (LT SYM ENT),
    //   3=inner-bot  (extra),
    //   4=middle     (LT NAV SPC),
    //   5=outer      (LT FUN TAB)
    KC_LALT, KC_RCTL,
    LT_ENT,
    KC_PGDN, LT_SPC,  LT_TAB
),

// NUM — Number layer (right hand active; trigger LT_BSP on left middle thumb).
[NUM] = LAYOUT_ergodox(
    // ---- LEFT HAND (trigger-side) ----
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, TD(TD_BOOT), KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
    KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   TD(TD_LO), TD(TD_LC), KC_NO,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // Left thumb: extras TRNS; trigger arg 4 TRNS; other LT thumbs NO
                                                 KC_TRNS, KC_TRNS,
                                                          KC_NO,
                                        KC_NO,   KC_TRNS, KC_TRNS,

    // ---- RIGHT HAND (active — numpad) ----
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_SLSH, KC_7,    KC_8,    KC_9,    KC_MINS, KC_TRNS,
             KC_ASTR, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
    KC_TRNS, KC_PERC, KC_1,    KC_2,    KC_3,    KC_CIRC, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // Right thumb: extras TRNS; numpad continuation . 0 = on inner-top / middle / outer
    KC_TRNS, KC_TRNS,
    KC_DOT,
    KC_TRNS, KC_0,    KC_EQL
),

// NAV — Navigation layer (left hand active; trigger LT_SPC on right middle thumb).
[NAV] = LAYOUT_ergodox(
    // ---- LEFT HAND (active) ----
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, C(KC_Y), C(KC_V), C(KC_C), C(KC_X), C(KC_Z), KC_TRNS,
    KC_TRNS, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_TRNS, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // Left thumb (active-side, "stay as base"): all TRNS
                                                 KC_TRNS, KC_TRNS,
                                                          KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,

    // ---- RIGHT HAND (trigger-side) ----
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   TD(TD_BOOT), KC_TRNS,
             KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_TRNS,
    KC_TRNS, KC_NO,   TD(TD_LC), TD(TD_LO), KC_NO, KC_NO, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // Right thumb: extras TRNS; trigger arg 4 TRNS; other LT thumbs NO
    KC_TRNS, KC_TRNS,
    KC_NO,
    KC_TRNS, KC_TRNS, KC_NO
),

// MED — Media layer (right hand active; trigger LT_ESC on left OUTER thumb).
// DESIGN.md draws `--` at the middle for MED's left thumbs, but the trigger
// is Esc (outer). Treating the diagram as a notation slip — TRNS is at the
// actual trigger arg (left thumb arg 3 = outer).
[MED] = LAYOUT_ergodox(
    // ---- LEFT HAND (trigger-side) ----
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, TD(TD_BOOT), KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
    KC_TRNS, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, KC_NO,
    KC_TRNS, KC_NO,   KC_NO,   TD(TD_LO), TD(TD_LC), KC_NO, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // Left thumb: extras TRNS; trigger arg 3 TRNS; other LT thumbs NO
                                                 KC_TRNS, KC_TRNS,
                                                          KC_NO,
                                        KC_TRNS, KC_NO,   KC_TRNS,

    // ---- RIGHT HAND (active) ----
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
             KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,   KC_TRNS,
    KC_TRNS, KC_MPLY, KC_MSTP, KC_MUTE, KC_NO,   KC_NO,   KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // Right thumb (active-side, "stay as base"): all TRNS
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),

// FUN — Function layer (left hand active; trigger LT_TAB on right OUTER thumb).
// Same MED-style notation slip: design draws `--` at middle but trigger is at
// outer (right thumb arg 5).
[FUN] = LAYOUT_ergodox(
    // ---- LEFT HAND (active — F-keys) ----
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, KC_TRNS,
    KC_TRNS, KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL,
    KC_TRNS, KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // Left thumb (active-side, "stay as base"): all TRNS
                                                 KC_TRNS, KC_TRNS,
                                                          KC_TRNS,
                                        KC_TRNS, KC_TRNS, KC_TRNS,

    // ---- RIGHT HAND (trigger-side) ----
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   TD(TD_BOOT), KC_TRNS,
             KC_NO,   KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_TRNS,
    KC_TRNS, KC_NO,   TD(TD_LC), TD(TD_LO), KC_NO, KC_NO, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // Right thumb: extras TRNS; trigger arg 5 TRNS; other LT thumbs NO
    KC_TRNS, KC_TRNS,
    KC_NO,
    KC_TRNS, KC_NO,   KC_TRNS
),

// SYM — Symbol layer (bilateral; triggers LT_DEL on left inner OR LT_ENT on right inner).
[SYM] = LAYOUT_ergodox(
    // ---- LEFT HAND ----
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_TRNS,
    KC_TRNS, KC_ASTR, KC_UNDS, KC_MINS, KC_EQL,  KC_DQT,
    KC_TRNS, KC_TILD, KC_SLSH, KC_PLUS, KC_GRV,  KC_QUOT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // Left thumb: extras TRNS; trigger arg 2 TRNS; other LT thumbs NO
                                                 KC_TRNS, KC_TRNS,
                                                          KC_TRNS,
                                        KC_NO,   KC_NO,   KC_TRNS,

    // ---- RIGHT HAND ----
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_CIRC, KC_AMPR, KC_LBRC, KC_RBRC, KC_PIPE, KC_TRNS,
             KC_COLN, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR, KC_TRNS,
    KC_TRNS, KC_BSLS, RIGHT_ARROW, KC_LT, KC_GT, KC_QUES, KC_TRNS,
                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    // Right thumb: extras TRNS; trigger arg 2 TRNS; other LT thumbs NO
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_NO,   KC_NO
),

};

// chordal_hold_layout: 'L' = left hand, 'R' = right hand, '*' = exempt from
// the opposite-hands rule. The 6 layer-tap thumbs are '*' so the trigger-side
// Boot/Lc/Lo extras (on the SAME hand as the held thumb) can chord with the
// thumb. All other positions are tagged by hand.
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_ergodox(
        // ---- LEFT HAND ----
        'L','L','L','L','L','L','L',
        'L','L','L','L','L','L','L',
        'L','L','L','L','L','L',
        'L','L','L','L','L','L','L',
        'L','L','L','L','L',
        // Left thumb: extras 'L'; LT thumbs '*'
                                  'L','L',
                                       '*',
                              '*','*','L',

        // ---- RIGHT HAND ----
        'R','R','R','R','R','R','R',
        'R','R','R','R','R','R','R',
        'R','R','R','R','R','R',
        'R','R','R','R','R','R','R',
        'R','R','R','R','R',
        // Right thumb: extras 'R'; LT thumbs '*'
        'R','R',
            '*',
        'R','*','*'
    );

// Flow Tap: limit to alpha/punctuation typing keys. Omitting KC_SPC (and
// implicitly all other layer-tap thumb tap-keycodes — KC_BSPC, KC_DEL,
// KC_ENT, KC_TAB, KC_ESC) lets the thumbs activate their layers without
// Flow Tap forcing them to their tap action during fast typing.
bool is_flow_tap_key(uint16_t keycode) {
    switch (get_tap_keycode(keycode)) {
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_SLSH:
            return true;
    }
    return false;
}

// Tap dance: all three keys do nothing on a single tap and fire on the
// second tap. This prevents accidental triggering of bootloader / layer-lock
// while typing on the trigger-side hand of a held layer.
static void td_boot_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) reset_keyboard();
}

static void td_lc_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 2) {
        layer_lock_invert(get_highest_layer(layer_state));
    }
}

static void td_lo_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count < 2) return;
    switch (get_highest_layer(layer_state)) {
        case NUM: layer_lock_invert(NAV); break;
        case NAV: layer_lock_invert(NUM); break;
        case MED: layer_lock_invert(FUN); break;
        case FUN: layer_lock_invert(MED); break;
        // BASE and SYM intentionally do nothing — Lc/Lo aren't reachable from those layers.
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_BOOT] = ACTION_TAP_DANCE_FN(td_boot_finished),
    [TD_LC]   = ACTION_TAP_DANCE_FN(td_lc_finished),
    [TD_LO]   = ACTION_TAP_DANCE_FN(td_lo_finished),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RIGHT_ARROW:
            if (record->event.pressed) {
                SEND_STRING("->");
            }
            return false;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    switch (get_highest_layer(state)) {
        case NUM:
            ergodox_right_led_1_on();
            break;
        case NAV:
            ergodox_right_led_2_on();
            break;
        case MED:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case FUN:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case SYM:
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    return state;
}

// Light the on-board (left half) LED whenever any layer is locked.
bool layer_lock_set_user(layer_state_t locked_layers) {
    if (locked_layers) {
        ergodox_board_led_on();
    } else {
        ergodox_board_led_off();
    }
    return true;
}
