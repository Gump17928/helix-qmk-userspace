#include QMK_KEYBOARD_H
#include <transactions.h>

#include "helix_remix.h"
#include "key_layout.h"

#ifdef OLED_ENABLE
#include "oled_pct.h"
#endif

enum layer_number {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};


enum custom_keycodes {
  MAC_WIN = SAFE_RANGE,
};

// keymapviz keymap.c -k helix -t json -o hremix{}.json

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = KEY_LAYOUT( \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                   KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    _______, KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,                   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,   \
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_ENT, KC_DEL, KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_UP,   KC_RSFT,  \
    KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______, KC_SPC, KC_SPC, _______, _______, KC_PSCR, KC_LEFT, KC_DOWN, KC_RGHT  \
    ),

  [_LOWER] = KEY_LAYOUT( \
    S(KC_SCLN), KC_MINS,    _______,    KC_SLSH,    S(KC_5),    S(KC_MINS),                     _______,        _______,    KC_PEQL, KC_PSLS,  KC_PAST, KC_PMNS, \
    _______,  S(KC_6),   S(KC_1),    S(KC_SLSH), _______,    _______,                        _______,        _______,    KC_P7,   KC_P8,    KC_P9,   KC_BSPC,  \
    S(KC_8),    S(KC_9),    _______,    _______,    _______,    _______,                        _______,        _______,    KC_P4,   KC_P5,    KC_P6,   KC_PENT, \
    S(KC_COMM), S(KC_DOT),  _______,    _______,    _______,    _______,    KC_SLEP, KC_SLEP,   KC_SLSH,        _______,    KC_P1,   KC_P2,    KC_P3,   KC_RALT, \
    _______,    _______,    _______,    _______,    _______,    _______,    _______, _______,   S(KC_SLSH),     _______,    KC_P0,   KC_COMMA, KC_PDOT, KC_PPLS \
    ),  

  [_RAISE] = KEY_LAYOUT( \
    KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11 , KC_F12 , \
    S(KC_CAPS), KC_NUM, KC_CALC, KC_MYCM, KC_MAIL, KC_WHOM,                   _______, _______, KC_NUM, KC_PSCR, KC_SCRL, KC_PAUSE, \
    KC_VOLD,    KC_VOLU, KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT,                   _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP, \
    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,  KC_END,  KC_PGDN, \
    _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ \
    ),
    
  [_ADJUST] =  KEY_LAYOUT( \
    _______, _______, _______, _______, _______, _______,                     KC_KP_1,      KC_KP_2,    KC_KP_3,       KC_KP_4, KC_KP_5, _______, \
    _______, _______, _______, _______, _______, _______,                     KC_KP_6,      KC_KP_7,    KC_KP_8,       KC_KP_9, KC_KP_0, KC_BSPC, \
    _______, _______, _______, _______, _______, _______,                     _______,      _______,    _______,       KC_LSFT, KC_LCTL, KC_ENT, \
    _______, _______, _______, _______, _______, _______, _______,   _______, _______,      _______,    _______,       KC_LGUI, KC_UP,   KC_SPC, \
    _______, _______, _______, _______, _______, _______, _______,   _______, _______,      _______,    KC_PSCR,       KC_LEFT, KC_DOWN, KC_RGHT \
    ),
};


#ifdef RGBLIGHT_LAYERS

#define HSV_KEY_NONE 0,0,0
#define HSV_KEY_BASE 0,0,255
#define HSV_KEY_FUNC 6,210,255
#define HSV_KEY_ARROW 38,252,255
#define HSV_KEY_TENKEY 115,206,214
#define HSV_KEY_SPACE 182,150,241
#define HSV_KEY_LAYER_LOWER 68,206,219
#define HSV_KEY_LAYER_RAISE 166,216,227
#define HSV_KEY_LAYER_ADJUST 187,167,232


const rgblight_segment_t PROGMEM led_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_KEY_FUNC },
    {6, 1, HSV_KEY_FUNC},
    {12, 1, HSV_KEY_FUNC},
    {18, 1, HSV_KEY_FUNC}, {24, 1, HSV_KEY_FUNC},
    {25, 3, HSV_KEY_FUNC}, {28, 1, HSV_KEY_LAYER_ADJUST },
      {29, 1, HSV_KEY_LAYER_RAISE }, {30, 1, HSV_KEY_LAYER_LOWER },
      {31, 1, HSV_KEY_SPACE },

    {38, 1, HSV_KEY_FUNC},
    {44, 1, HSV_KEY_FUNC},
    {50, 1, HSV_KEY_FUNC}, { 51, 1, HSV_KEY_ARROW }, { 56, 1, HSV_KEY_FUNC },
    {57, 3, HSV_KEY_ARROW}, { 60, 1, HSV_KEY_FUNC },
      {61, 1, HSV_KEY_LAYER_ADJUST}, {62, 1, HSV_KEY_LAYER_LOWER},
      {63, 1, HSV_KEY_SPACE }
);

const rgblight_segment_t PROGMEM rgb_lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_KEY_LAYER_LOWER},
    {6, 6, HSV_KEY_LAYER_LOWER},
    {12, 6, HSV_KEY_LAYER_LOWER},
    {18, 6, HSV_KEY_LAYER_LOWER},

    {32, 4, HSV_KEY_TENKEY}, {36, 2, HSV_KEY_LAYER_LOWER},
    {38, 1, HSV_KEY_FUNC}, {37, 3, HSV_KEY_TENKEY}, {42, 2, HSV_KEY_LAYER_LOWER},
    {44, 1, HSV_KEY_FUNC}, {45, 3, HSV_KEY_TENKEY}, {48, 2, HSV_KEY_LAYER_LOWER},
    {50, 1, HSV_KEY_FUNC}, {51, 3, HSV_KEY_TENKEY}, {54, 2, HSV_KEY_LAYER_LOWER},
    {57, 4, HSV_KEY_TENKEY}, {61, 2, HSV_KEY_LAYER_LOWER}
);

const rgblight_segment_t PROGMEM rgb_high_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_KEY_LAYER_RAISE},
    {6, 5, HSV_KEY_LAYER_RAISE},
    {12, 6, HSV_KEY_LAYER_RAISE},

    {32, 6, HSV_KEY_LAYER_RAISE},
    {38, 4, HSV_KEY_LAYER_RAISE},
    {44, 3, HSV_KEY_LAYER_RAISE},
    {50, 3, HSV_KEY_LAYER_RAISE}
);

const rgblight_segment_t PROGMEM rgb_adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_KEY_FUNC },
    {6, 1, HSV_KEY_FUNC},
    {12, 1, HSV_KEY_FUNC},
    {18, 1, HSV_KEY_FUNC}, {24, 1, HSV_KEY_FUNC},
    {25, 3, HSV_KEY_FUNC}, {28, 1, HSV_KEY_LAYER_ADJUST },
      {29, 1, HSV_KEY_LAYER_RAISE }, {30, 1, HSV_KEY_LAYER_LOWER },
      {31, 1, HSV_KEY_SPACE },

    {32, 1, HSV_KEY_FUNC}, 
    {38, 1, HSV_KEY_FUNC}, 
    {44, 6, HSV_KEY_FUNC}, 
    {50, 1, HSV_KEY_SPACE}, {51, 1, HSV_KEY_ARROW }, {52, 4, HSV_KEY_FUNC },
    {57, 3, HSV_KEY_ARROW}, {60, 1, HSV_KEY_FUNC }, {61, 1, HSV_KEY_LAYER_RAISE }, {62, 1, HSV_KEY_LAYER_ADJUST } 
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    led_base_layer,
    rgb_lower_layer,
    rgb_high_layer,
    rgb_adjust_layer
);

void init_rgb_layers(void){
    rgblight_set_clipping_range(is_keyboard_master() ? 0 : 32, 32);
    rgblight_layers = rgb_layers;

    rgblight_set_layer_state(0, true);
}
#endif

typedef union {
  uint32_t raw;
  struct {
    bool swap_alt_gui:1;
  };
} user_config_t;
user_config_t user_config;

// サブキーボードに同期するデータ
typedef union {
  uint8_t raw;
  struct {
    bool swap_gui:1;
    bool mod_gui:1;
    bool caps_lock:1;
    bool num_lock:1;
    bool sc_lock:1;
  };
} key_state_r_t;
key_state_r_t key_state_r;

extern user_config_t user_config;

#ifdef OLED_ENABLE

static bool require_oled_update = true;

void oled_update(bool update_left){
    bool m = is_keyboard_master();
    if(m == update_left) {
        require_oled_update = true;
    }else if(m == true){
        transaction_rpc_send(USER_DATA_SYNC, 1, &key_state_r.raw);
    }
}
#else
#define oled_update(ul)
#endif

// GUI
void swap_alt_gui(bool swap) {
    key_state_r.swap_gui = swap;
    oled_update(false);

    if(user_config.swap_alt_gui != swap){
        user_config.swap_alt_gui = swap;
        keymap_config.swap_lalt_lgui = !swap;
        keymap_config.swap_ralt_rgui = !swap;

        eeconfig_update_user(user_config.raw);
    }
}

void eeconfig_init_user(void) {
    user_config.raw = 0x00;
    eeconfig_update_user(user_config.raw);
}

#ifdef OLED_ENABLE
void user_sync_a_slave_handler(uint8_t in_buflen, const void* in_data, uint8_t out_buflen, void* out_data) {
    const key_state_r_t *ks = (const key_state_r_t*)in_data;
    key_state_r.raw = ks->raw;
}
#endif

// キーボード初期化後に呼ばれる
void keyboard_post_init_user(void) {
    key_state_r.raw = 0x00;

    // 設定の読み込み
    user_config.raw = eeconfig_read_user();
    swap_alt_gui(user_config.swap_alt_gui);

#ifdef OLED_ENABLE
    // 通信同期
    transaction_register_rpc(USER_DATA_SYNC, user_sync_a_slave_handler);
#endif

#ifdef RGBLIGHT_ENABLE
    init_rgblight();
    rgblight_disable();
#endif

#ifdef RGBLIGHT_LAYERS
    init_rgb_layers();
#endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
    rgblight_set_layer_state(2, layer_state_cmp(state, _UPPER));
    rgblight_set_layer_state(3, layer_state_cmp(state, _CLIP));
#endif

#ifdef OLED_ENABLE
    oled_update(true);
#endif

    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_LSFT:
    case KC_RSFT:
    case KC_LALT:
    case KC_RALT:
    case KC_LCTL:
    case KC_RCTL:
        oled_update(true);
        break;
    case KC_LGUI:
    case KC_RGUI:
        key_state_r.mod_gui = record->event.pressed;
        oled_update(false);
        break;
    case MAC_WIN:
        if (record->event.pressed) swap_alt_gui(!user_config.swap_alt_gui);
        oled_update(false);
        break;
    }
    return true;
}

bool led_update_user(led_t led_state){
    key_state_r.caps_lock = led_state.caps_lock;
    key_state_r.num_lock = led_state.num_lock;
    key_state_r.sc_lock = led_state.scroll_lock;

    oled_update(false);

    return true;
}


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return rotation;
}

void draw_state_bitmap(int index, int dx, int dy){
    draw_bitmap(oled_pct_layer,
        OP_LAYER_BW, OP_LAYER_BH, OP_LAYER_STRIDE,
        index % OP_LAYER_BX, index / OP_LAYER_BX,
        dx, dy, BmpRotate90);
}

void draw_left_status(void){
    const int dy = 1;
    int dx = OLED_DISPLAY_WIDTH;

    int index = 0;
    if(layer_state_cmp(layer_state, _CLIP)){
        index = 3;
    }else if(layer_state_cmp(layer_state, _UPPER)){
        index = 2;
    }else if(layer_state_cmp(layer_state, _LOWER)){
        index = 1;
    }

    dx -= OP_LAYER_BH;
    draw_state_bitmap(index, dx, dy);

    int mods = get_mods();
    for(int i = 0; i < 3; i++){
        dx -= (OP_LAYER_BH + 1);

        bool on = false;
        switch(i){
        case 0: on = (mods & MOD_MASK_SHIFT) != 0; break;
        case 1: on = (mods & MOD_MASK_CTRL) != 0; break;
        case 2: on = (mods & MOD_MASK_ALT) != 0; break;
        }
        index = (8 + i * 2) + (on ? 1 : 0);

        draw_state_bitmap(index, dx, dy);
    }
}

void draw_right_status(void){
    const int dy = 1;
    int dx = OLED_DISPLAY_WIDTH;
    int index = (key_state_r.swap_gui ? 4 : 6) + (key_state_r.mod_gui ? 1 : 0);

    dx -= OP_LAYER_BH;
    draw_state_bitmap(index, dx, dy);

    for(int i = 0; i < 3; i++){
        dx -= (OP_LAYER_BH + 1);

        bool on = false;
        switch(i){
        case 0: on = key_state_r.caps_lock; break;
        case 1: on = key_state_r.num_lock; break;
        case 2: on = key_state_r.sc_lock; break;
        }
        index = (14 + i * 2) + (on ? 1 : 0);

        draw_state_bitmap(index, dx, dy);
    }
}

bool oled_task_user(void) {
    static uint8_t last_state = 0;

    if(last_state != key_state_r.raw){
        require_oled_update = true;
        last_state = key_state_r.raw;
    }

    if(require_oled_update == false) return false;
    require_oled_update = false;

    if(is_keyboard_master()){
        draw_left_status();
    }else{
        draw_right_status();
    }
	return false;
}
#endif
