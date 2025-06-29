#pragma once

//#define USE_MATRIX_I2C
#ifdef KEYBOARD_crkbd_rev1_legacy
#    undef USE_I2C
#    define USE_SERIAL
#endif

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

// https://docs.qmk.fm/#/feature_caps_word
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0
// Apply the modifier on keys that are tapped during a short hold of a modtap.
#define PERMISSIVE_HOLD
#define CHORDAL_HOLD

// todo
// - HOLD_ON_OTHER_KEY_PRESS -> https://docs.qmk.fm/#/ChangeLog/20230226?id=i-m-t-i
//   - see https://docs.qmk.fm/#/tap_hold?id=hold-on-other-key-press
// - try dynamic tapping term https://docs.qmk.fm/#/ChangeLog/20211127?id=dynamic-tapping-term
// - try to rename keeb without copying /workspaces/qmk_firmware/keyboards/crkbd/info.json
// - checkout autocorrect https://docs.qmk.fm/#/ChangeLog/20221126?id=autocorrect
// - check "Standardised the lower/raise/adjust layer change pattern with explicit keycodes and configurable target layers" in https://docs.qmk.fm/#/ChangeLog/20230226

#define RGB_DI_PIN 16        // For QMK RGB system
#define WS2812_DI_PIN GP16   // For low-level ChibiOS driver
// #define RGBLED_NUM 1
// #define RGBLIGHT_LED_COUNT RGBLED_NUM
#define RGBLIGHT_LIMIT_VAL 120  // Limit brightness (0-255)
#define RGBLIGHT_SLEEP      // Turns off RGB when USB suspended
#define RGBLIGHT_DISABLE_HUE_SHIFT
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_RGB
