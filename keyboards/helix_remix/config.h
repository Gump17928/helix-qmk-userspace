#pragma once

/* Left half is the USB master. */
#define MASTER_LEFT

/* Custom split transaction id used in helix_remix.c for data sync. */
#define SPLIT_TRANSACTION_IDS_USER USER_DATA_SYNC


#ifdef RGBLIGHT_ENABLE

/* Turn LEDs off when host sleeps. */
#define RGBLIGHT_SLEEP

/* Data-in pin. */
#define RGB_DI_PIN D3

/* Keep brightness capped to avoid pro-micro brownout. */
#define RGBLIGHT_LIMIT_VAL 35

/* 32 LEDs per half. */
#define RGBLED_NUM 64
#define RGBLIGHT_SPLIT
#define RGBLED_SPLIT {32, 32}

#define RGBLIGHT_LAYERS

// #define RGBLIGHT_ANIMATIONS
// #define RGBLIGHT_EFFECT_RGB_TEST

#define LED_LAYOUT( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, L36, R30, R31, R32, R33, R34, R35, R36, \
    L40, L41, L42, L43, L44, L45, L46, R40, R41, R42, R43, R44, R45, R46 \
) { \
    L05, L04, L03, L02, L01, L00, \
    L10, L11, L12, L13, L14, L15, \
    L25, L24, L23, L22, L21, L20, \
    L30, L31, L32, L33, L34, L35, L36, \
    L46, L45, L44, L43, L42, L41, L40, \
    R00, R01, R02, R03, R04, R05, \
    R15, R14, R13, R12, R11, R10, \
    R20, R21, R22, R23, R24, R25, \
    R36, R35, R34, R33, R32, R31, R30, \
    R40, R41, R42, R43, R44, R45, R46 \
}

#define RGBLIGHT_LED_MAP LED_LAYOUT( \
   0,  1,  2,  3,  4,  5,            37, 36, 35, 34, 33, 32, \
   6,  7,  8,  9, 10, 11,            43, 42, 41, 40, 39, 38, \
  12, 13, 14, 15, 16, 17,            49, 48, 47, 46, 45, 44, \
  18, 19, 20, 21, 22, 23, 24,    56, 55, 54, 53, 52, 51, 50, \
  25, 26, 27, 28, 29, 30, 31,    63, 62, 61, 60, 59, 58, 57)
#endif

#ifdef OLED_ENABLE
#define OLED_TIMEOUT 5000
#define OLED_FONT_H "helixfont.h"
#endif
