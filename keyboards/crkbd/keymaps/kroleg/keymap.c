#include QMK_KEYBOARD_H

#include "print.h"

enum layer_number {
    _QWERTY = 0,
    _COLEMAK,
    _SYM,
    _SYM_RU,
    _NAV,
    _THIRD,
    _THIRD_DUPE
};

// home row mods for qwerty
#define QH_S LALT_T(KC_S)
#define QH_D LSFT_T(KC_D)
#define QH_F LGUI_T(KC_F)
#define QH_J RGUI_T(KC_J)
#define QH_K RSFT_T(KC_K)
#define QH_L LALT_T(KC_L)
#define QH_SCLN RCTL_T(KC_SCLN)

// home row mods COLEMAK
#define HOME_A LCTL_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LSFT_T(KC_S)
#define HOME_T LGUI_T(KC_T)
#define HOME_N RGUI_T(KC_N)
#define HOME_E RSFT_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RCTL_T(KC_O)

// thumbs
#define SFT_SPC LSFT_T(KC_SPC)

enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    CMDTAB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = LAYOUT_split_3x5_3(
		KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_LBRC, KC_P,
		HOME_A,  QH_S,    QH_D,    QH_F,    KC_G,        KC_H,    QH_J,    QH_K,    QH_L,    QH_SCLN,
		KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_NO,
                          KC_TAB,  MO(_SYM_RU), KC_ENT,  SFT_SPC, MO(_NAV), KC_NO
	),
    [_COLEMAK] = LAYOUT_split_3x5_3(
		KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_NO,
		HOME_A,  HOME_R,  HOME_S,  HOME_T,  KC_G,        KC_M,    HOME_N,  HOME_E,  HOME_I,  HOME_O,
		KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_EXLM,
                          KC_TRNS, MO(_SYM), KC_TRNS,   KC_TRNS, MO(_NAV), KC_TRNS
	),
	[_SYM] = LAYOUT_split_3x5_3(
		KC_AMPR,KC_PERC, KC_ASTR,  KC_LCBR, KC_RCBR,     KC_LT,   KC_GT,   KC_TILD, KC_CIRC, KC_HASH,
		KC_ESC, KC_UNDS, KC_EQL,   KC_LBRC, KC_RBRC,     KC_DQUO, KC_QUOT, KC_COLN, KC_SLSH, KC_QUES,
		KC_AT,  KC_MINS, KC_PLUS,  KC_LPRN, KC_RPRN,     KC_DLR,  KC_GRAVE,KC_SCLN, KC_PIPE, KC_BSLS,
		                  KC_NO,   KC_TRNS, KC_TRNS,     KC_SPC,  KC_TRNS, QMKBEST
	),
    [_SYM_RU] = LAYOUT_split_3x5_3(
		KC_AMPR,KC_PERC, KC_ASTR,  KC_LCBR, KC_RCBR,     KC_NO,   KC_NO,   KC_TILD, KC_CIRC, KC_HASH,
		KC_ESC, KC_UNDS, KC_EQL,   KC_LBRC, KC_RBRC,     KC_AT,   KC_GT,   KC_LT, KC_SLSH, KC_QUES,
		KC_AT,  KC_MINS, KC_PLUS,  KC_LPRN, KC_RPRN,     KC_DLR,  KC_GRAVE,KC_SCLN, KC_PIPE, KC_BSLS,
		                  KC_NO,   KC_TRNS, KC_TRNS,     KC_SPC,  KC_TRNS, QMKBEST
	),
	[_NAV] = LAYOUT_split_3x5_3(
		KC_DOT,  KC_4,    KC_3,    KC_2,    KC_1,        KC_NO,   KC_HOME, KC_UP,   KC_END,  KC_NO,
		KC_LCTL, KC_LALT, KC_LSFT, KC_LGUI, KC_0,        CMDTAB,  KC_LEFT, KC_DOWN, KC_RGHT, KC_ESC,
		KC_9,    KC_8,    KC_7,    KC_6,    KC_5,        KC_NO,   LSFT(KC_TAB),  KC_BSPC, KC_TAB, KC_TRNS,
		                  KC_NO,   MO(_SYM), KC_TRNS,     KC_TRNS, KC_TRNS, KC_NO
	),
    [_THIRD] = LAYOUT_split_3x5_3(
		QMKBEST, KC_NO, KC_NO, KC_NO, KC_NO,        KC_VOLD, KC_VOLU, KC_NO,   KC_NO,  KC_NO,
		KC_NO,   KC_NO, KC_NO, KC_F13, KC_NO,       KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO,
		                KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO
	),
    [_THIRD_DUPE] = LAYOUT_split_3x5_3(
		QMKBEST, KC_NO, KC_NO, KC_NO, KC_NO,        KC_VOLD, KC_VOLU, KC_NO,   KC_NO,  KC_NO,
		KC_NO,   KC_NO, KC_NO, KC_F13, KC_NO,       KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,        KC_NO,   KC_NO,  KC_NO, KC_NO, KC_NO,
		                KC_NO, KC_NO, KC_NO,        KC_NO, KC_NO, KC_NO
	)
};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool in_cmd_tab;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    // switch (biton32(default_layer_state)) {
    //     case _COLEMAK:
    //         // LED2 for COLEMAK
    //         print("is COLEMAK\n");
    //         break;
    //     case _QWERTY:
    //         print("is QWERTY\n");
    //         break;
    // };
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();

    static bool cmdm_registered;
    if (record->event.pressed) {
        if (keycode == KC_M && mod_state & MOD_MASK_GUI) {
            del_mods(MOD_MASK_GUI);
            register_code(KC_M);
            // Update the boolean variable to reflect the status of KC_DEL
            cmdm_registered = true;
            // Reapplying modifier state so that the held shift key(s)
            // still work even after having tapped the Backspace/Delete key.
            set_mods(mod_state);
            return false;
        }

    } else {  // on release of KC_BSPC

        uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %i, time: %u, interrupt: %i, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);

        // In case KC_DEL is still being sent even after the release of KC_BSPC
        if (cmdm_registered) {
            unregister_code(KC_M);
            cmdm_registered = false;
            return false;
        }
        if (mod_state & MOD_MASK_CTRL) {
            print("ctrl  & ");
        }
    }

    uint8_t current_layer = get_highest_layer(layer_state);

    static bool cmd_switched_to_colemak;
    static bool alt_kc_registered;

    switch (keycode) {
    // because we switch layer to colemak whe QH_J/QH_F is held we need to handle "release" on HOME_N
    case HOME_N:
        if (!record->event.pressed && cmd_switched_to_colemak) {
            cmd_switched_to_colemak = true;
            layer_off(_COLEMAK);
        }
        return true; // this allows normal processing
        break;
    case QH_F:
    case QH_J:
        if (record->tap.count && record->event.pressed) {
            return true; // for normal processing of tap
            break;
        } else if (record->event.pressed) {
            cmd_switched_to_colemak = true;
            layer_on(_COLEMAK);
            return true; // true so GUI mod will still be applied (because that's what QH_J does)
        }
        return true; // this allows normal processing on key release
        break;

    // alt+E -> Э
    case KC_T:
        if (current_layer == _QWERTY) {
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_ALT) {
                    // First temporarily canceling both alts so that it isn't applied to the  keycode
                    del_mods(MOD_MASK_ALT);
                    register_code(KC_QUOT);
                    // Update the boolean variable to reflect the status of KC_T
                    alt_kc_registered = true;
                    // Reapplying modifier state so that the held alt key(s)
                    // still work even after having tapped the key.
                    set_mods(mod_state);
                    return false;
                }
            } else {  // on release
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (alt_kc_registered) {
                    unregister_code(KC_QUOT);
                    alt_kc_registered = false;
                    return false;
                }
            }
        }
        break;

    // alt+Ш -> Щ
    case KC_I:
        if (current_layer == _QWERTY) {
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_ALT) {
                    // First temporarily canceling both alts so that it isn't applied to the  keycode
                    del_mods(MOD_MASK_ALT);
                    register_code(KC_O);
                    // Update the boolean variable to reflect the status of KC_T
                    alt_kc_registered = true;
                    // Reapplying modifier state so that the held alt key(s)
                    // still work even after having tapped the key.
                    set_mods(mod_state);
                    return false;
                }
            } else {  // on release
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (alt_kc_registered) {
                    unregister_code(KC_O);
                    alt_kc_registered = false;
                    return false;
                }
            }
        }
        break;

    // alt+Ь -> Ъ
    case KC_M:
        if (current_layer == _QWERTY) {
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_ALT) {
                    // First temporarily canceling both alts so that it isn't applied to the  keycode
                    del_mods(MOD_MASK_ALT);
                    register_code(KC_RBRC);
                    // Update the boolean variable to reflect the status of KC_T
                    alt_kc_registered = true;
                    // Reapplying modifier state so that the held alt key(s)
                    // still work even after having tapped the key.
                    set_mods(mod_state);
                    return false;
                }
            } else {  // on release
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (alt_kc_registered) {
                    unregister_code(KC_RBRC);
                    alt_kc_registered = false;
                    return false;
                }
            }
        }
        break;

    case QMKBEST:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            // SEND_STRING("QMK is the best thing ever!");
        } else {
            // when keycode QMKBEST is released
            register_code(KC_LCTL);
            register_code(KC_SPC);
            unregister_code(KC_SPC);
            unregister_code(KC_LCTL);
            if (biton32(default_layer_state) == _COLEMAK) {
                set_single_persistent_default_layer(_QWERTY);
            } else {
                set_single_persistent_default_layer(_COLEMAK);
            }
        }
        break;
    case CMDTAB:
        if (record->event.pressed) { // when keycode is pressed
            register_code(KC_LGUI);
            register_code(KC_TAB);
            in_cmd_tab = true;
        } else { // when keycode is released
            unregister_code(KC_TAB);
        }
        break;
    }

    return true;  // Let QMK send the enter press/release events
}

layer_state_t layer_state_set_user(layer_state_t state) {
uprintf("layer: %u\n", state);
    if (in_cmd_tab) {
        unregister_code(KC_LGUI);
        in_cmd_tab = false;
    }
    state = update_tri_layer_state(state, _SYM, _NAV, _THIRD);
    state = update_tri_layer_state(state, _SYM_RU, _NAV, _THIRD_DUPE);
    return state;
}


void matrix_init_user(void) {
    bootmagic();
}
