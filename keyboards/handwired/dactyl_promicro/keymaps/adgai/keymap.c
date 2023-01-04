#include QMK_KEYBOARD_H
 

#define _WORKMAN 0
#define _QWERTY 1
#define _LOWER 2
#define _RAISE 3

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define ALT_SHFT LALT(KC_LSFT)
#define ALT_MENU LALT_T(KC_MENU)
#define ENT LSFT_T(KC_ENT) 
#define SPC LALT_T(KC_SPC)
#define S_TAB S(KC_TAB)
#define CTRL LCTL_T(KC_DEL)
#define GUI LGUI_T(KC_BSPC)
#define L2_BSPC LCTL(KC_BSPC)
// home row mods
#define HA LALT_T(KC_A)
#define HI RALT_T(KC_A)

#define HS LGUI_T(KC_S)
#define HO RGUI_T(KC_O)

#define HH LSFT_T(KC_H)
#define HE RSFT_T(KC_E)

#define HT LCTRL_T(KC_H)
#define N  RCTRL_T(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_WORKMAN] = LAYOUT_6x6(
        KC_GRV , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_TAB, KC_Q  ,KC_D   , KC_R  , KC_W  , KC_B  ,                                        KC_J   , KC_F  , KC_U  , KC_P  , KC_SCLN  ,KC_MINS,
        KC_ESC, KC_A  ,KC_S   , KC_H  , KC_T  , KC_G  ,                                        KC_Y   , KC_N  , KC_E  , KC_O  ,KC_I,KC_QUOT,
        KC_LSFT, KC_Z ,KC_X   , KC_M  , KC_C  , KC_V  ,                                        KC_K   , KC_L  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
        KC_EQL,KC_QUOT,ALT_SHFT,KC_LEFT,KC_RGHT,KC_SPC ,                                       ENT , KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,TG(_QWERTY),
                                                OSL(_LOWER),KC_LSFT,GUI,       ENT,KC_LALT,TG(_RAISE) ,
                                                                CTRL,              SPC,
                                                                OSL(_RAISE) ,      TG(_LOWER)
    ),
    [_QWERTY] = LAYOUT_6x6(
        KC_GRV , KC_1  ,KC_2   , KC_3  , KC_4  , KC_5  ,                                        KC_6   , KC_7  , KC_8  , KC_9  , KC_0  ,KC_BSPC,
        KC_TAB, KC_Q  ,KC_W   , KC_E  , KC_R  , KC_T  ,                                        KC_Y   , KC_U  , KC_I  , KC_O  , KC_P  ,KC_MINS,
        KC_ESC, KC_A  ,KC_S   , KC_D  , KC_F  , KC_G  ,                                        KC_H   , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_QUOT,
        KC_LSFT, KC_Z ,KC_X   , KC_C  , KC_V  , KC_B  ,                                        KC_N   , KC_M  ,KC_COMM, KC_DOT,KC_SLSH,KC_RSFT,
        KC_EQL,KC_QUOT,ALT_SHFT,KC_LEFT,KC_RGHT,KC_SPC ,                                       ENT , KC_UP  ,KC_DOWN,KC_LBRC,KC_RBRC,_______,
                                                OSL(_LOWER),KC_LSFT,KC_LGUI,       ENT,KC_LALT,TG(_RAISE) ,
                                                                KC_LEFT_CTRL,        SPC,
                                                                OSL(_RAISE) ,        TG(_LOWER)
    ),
    [_LOWER] = LAYOUT_6x6(
        _______,KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,                                       KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,
        KC_COLN,KC_EXLM,KC_AT  ,KC_LBRC,KC_RBRC,KC_PIPE,                                       KC_EQL  ,KC_7  ,KC_8  ,KC_9  ,KC_ASTR,KC_F12 ,
        KC_UNDS,KC_HASH,KC_DLR ,KC_LPRN,KC_RPRN,KC_GRV ,                                       KC_BSLS,KC_4  ,KC_5  ,KC_6  ,KC_PLUS,KC_UNDS,
        _______,KC_PERC,KC_CIRC,KC_LCBR,KC_RCBR,KC_TILD,                                       KC_AMPR,KC_1  ,KC_2  ,KC_3  ,KC_0,KC_SLSH,
        QK_BOOT  ,_______,_______,_______,_______,_______,                                       _______,KC_MINS,KC_DOT,KC_0  ,KC_EQL,_______,
                                                _______,_______,_______,       KC_LGUI,_______,_______,
                                                                _______,       KC_BSPC,
                                                                _______,       _______
    ),
    [_RAISE] = LAYOUT_6x6(
        _______,_______,_______,_______,_______,_______,                                       _______,_______,_______,_______,_______,_______,
        _______,_______,KC_WH_U	,KC_MS_U,KC_WH_D	,_______,                                       _______,KC_TAB,KC_UP,S_TAB,_______,_______,
        _______,_______,KC_MS_L,KC_MS_D,KC_MS_R,_______,                                       KC_LEFT,KC_DOWN,KC_UP, KC_RIGHT,KC_MPLY,_______,
        _______,_______,_______,KC_BTN1,KC_BTN2,_______,                                       _______,_______,KC_MPRV,KC_MNXT,_______,_______,
        QK_BOOT  ,_______,_______,_______,_______,_______,                                       KC_WBAK,KC_VOLU,KC_VOLD,KC_MUTE,_______,_______,
                                                _______,_______,_______,       _______,_______,_______,
                                                                _______,       L2_BSPC,
                                                                _______,       _______
    ),

};

