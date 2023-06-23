#include "keycodes.h"
#include "keymap_us.h"
#include "quantum_keycodes.h"
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
#define CS_TAB LCTL(LSFT(KC_TAB))
#define C_TAB LCTL(KC_TAB)
#define CTRL LCTL_T(KC_ESC)
#define GUI LGUI_T(KC_BSPC)
#define L2_BSPC LCTL(KC_BSPC)
#define S_GUI LSFT(KC_LGUI)
// home row mods
#define HA LALT_T(KC_A)
#define HI RALT_T(KC_A)

#define HS LGUI_T(KC_S)
#define HO RGUI_T(KC_O)

#define HH LSFT_T(KC_H)
#define HE RSFT_T(KC_E)

#define HT LCTRL_T(KC_H)
#define N  RCTRL_T(KC_E)

#define SF2 LCTL(LALT(KC_F2))
#define SF7 LCTL(LALT(KC_F7))
#define SCROT LWIN(LSFT(KC_S))

// Repeat key, stolen from https://gist.github.com/NotGate/3e3d8ab81300a86522b2c2549f99b131
enum custom_keycodes {
    // it can be called REP if you want but "REPEAT" is clearer and still fits under the 8 char "limit"
    REPEAT = SAFE_RANGE,
};

// combos
const uint16_t PROGMEM test_combo1[] = {CTRL, SPC, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_BSPC, KC_N, COMBO_END};
const uint16_t PROGMEM test_combo3[] = {KC_BSPC, KC_E, COMBO_END};
const uint16_t PROGMEM test_combo4[] = {KC_BSPC, KC_O, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(test_combo1, KC_TAB),
    COMBO(test_combo2, LCTL(KC_TAB)), // keycodes with modifiers are possible too!
    COMBO(test_combo3, LCTL(LSFT(KC_TAB))), // keycodes with modifiers are possible too!
    COMBO(test_combo4, LSFT(KC_TAB)), // keycodes with modifiers are possible too!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬─────┬──────┬──────┬────────┬────────────┐                                           ┌─────────────┬────────────┬─────┬────┬──────┬──────┐
//    │  `   │  1  │  2   │  3   │   4    │     5      │                                           │      6      │     7      │  8  │ 9  │  0   │ bspc │
//    ├──────┼─────┼──────┼──────┼────────┼────────────┤                                           ├─────────────┼────────────┼─────┼────┼──────┼──────┤
//    │ tab  │  q  │  d   │  r   │   w    │     b      │                                           │      j      │     f      │  u  │ p  │  ;   │  -   │
//    ├──────┼─────┼──────┼──────┼────────┼────────────┤                                           ├─────────────┼────────────┼─────┼────┼──────┼──────┤
//    │ esc  │  a  │  s   │  h   │   t    │     g      │                                           │      y      │     n      │  e  │ o  │  i   │ "'"  │
//    ├──────┼─────┼──────┼──────┼────────┼────────────┤                                           ├─────────────┼────────────┼─────┼────┼──────┼──────┤
//    │ lsft │  z  │  x   │  m   │   c    │     v      │                                           │      k      │     l      │  ,  │ .  │  /   │ rsft │
//    ├──────┼─────┼──────┼──────┼────────┼────────────┘                                           └─────────────┼────────────┼─────┼────┼──────┼──────┤
//    │  =   │ "'" │ bspc │ left │  rght  │                                                                      │    spc     │ ENT │ up │ down │  [   │
//    └──────┴─────┴──────┴──────┴────────┼────────────┬─────────────┐               ┌─────────────┬─────────────┼────────────┴─────┴────┴──────┴──────┘
//                                        │     ]      │ TG(_QWERTY) │               │ OSL(_LOWER) │    lsft     │
//                                        └────────────┼─────────────┤               ├─────────────┼─────────────┘
//                                                     │     GUI     │               │     ENT     │
//                               ┌────────┬────────────┼─────────────┤               ├─────────────┼─────────────┬────────────┐
//                               │ REPEAT │ TG(_RAISE) │    CTRL     │               │     SPC     │ TG(_QWERTY) │ TG(_LOWER) │
//                               └────────┴────────────┴─────────────┘               └─────────────┴─────────────┴────────────┘
[_WORKMAN] = LAYOUT_6x6(
  KC_GRV  , KC_1    , KC_2    , KC_3    , KC_4    , KC_5       ,                                             KC_6        , KC_7       , KC_8    , KC_9   , KC_0    , KC_BSPC,
  KC_TAB  , KC_Q    , KC_D    , KC_R    , KC_W    , KC_B       ,                                             KC_J        , KC_F       , KC_U    , KC_P   , KC_SCLN , KC_MINS,
  KC_ESC  , KC_A    , KC_S    , KC_H    , KC_T    , KC_G       ,                                             KC_Y        , KC_N       , KC_E    , KC_O   , KC_I    , KC_QUOT,
  KC_LSFT , KC_Z    , KC_X    , KC_M    , KC_C    , KC_V       ,                                             KC_K        , KC_L       , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT,
  KC_EQL  , KC_QUOT , KC_BSPC , KC_LEFT , KC_RGHT ,                                                                        KC_SPC     , ENT     , KC_UP  , KC_DOWN , KC_LBRC,
                                                    KC_RBRC    , TG(_QWERTY) ,                 OSL(_LOWER) , KC_LSFT                                                        ,
                                                                 GUI         ,                 ENT                                                                          ,
                                          REPEAT  , TG(_RAISE) , CTRL        ,                 SPC         , TG(_QWERTY) , TG(_LOWER)
),

//    ┌──────┬─────┬──────────┬──────┬────────┬────────────┐                                            ┌─────────────┬────────────┬─────┬────┬──────┬──────┐
//    │  =   │  1  │    2     │  3   │   4    │     5      │                                            │      6      │     7      │  8  │ 9  │  0   │ bspc │
//    ├──────┼─────┼──────────┼──────┼────────┼────────────┤                                            ├─────────────┼────────────┼─────┼────┼──────┼──────┤
//    │ del  │  q  │    w     │  e   │   r    │     t      │                                            │      y      │     u      │  i  │ o  │  p   │  -   │
//    ├──────┼─────┼──────────┼──────┼────────┼────────────┤                                            ├─────────────┼────────────┼─────┼────┼──────┼──────┤
//    │ bspc │  a  │    s     │  d   │   f    │     g      │                                            │      h      │     j      │  k  │ l  │  ;   │ "'"  │
//    ├──────┼─────┼──────────┼──────┼────────┼────────────┤                                            ├─────────────┼────────────┼─────┼────┼──────┼──────┤
//    │ lsft │  z  │    x     │  c   │   v    │     b      │                                            │      n      │     m      │  ,  │ .  │  /   │ rsft │
//    ├──────┼─────┼──────────┼──────┼────────┼────────────┘                                            └─────────────┼────────────┼─────┼────┼──────┼──────┤
//    │  `   │ "'" │ ALT_SHFT │ left │  rght  │                                                                       │    spc     │ ent │ up │ down │  [   │
//    └──────┴─────┴──────────┴──────┴────────┼────────────┬──────────────┐               ┌─────────────┬─────────────┼────────────┴─────┴────┴──────┴──────┘
//                                            │     ]      │ TG(_WORKMAN) │               │ OSL(_LOWER) │    lsft     │
//                                            └────────────┼──────────────┤               ├─────────────┼─────────────┘
//                                                         │     GUI      │               │     ENT     │
//                                   ┌────────┬────────────┼──────────────┤               ├─────────────┼─────────────┬────────────┐
//                                   │ REPEAT │ TG(_RAISE) │     CTRL     │               │     SPC     │ TG(_QWERTY) │ TG(_LOWER) │
//                                   └────────┴────────────┴──────────────┘               └─────────────┴─────────────┴────────────┘
[_QWERTY] = LAYOUT_6x6(
  KC_EQL  , KC_1    , KC_2     , KC_3    , KC_4    , KC_5       ,                                              KC_6        , KC_7       , KC_8    , KC_9   , KC_0    , KC_BSPC,
  KC_DEL  , KC_Q    , KC_W     , KC_E    , KC_R    , KC_T       ,                                              KC_Y        , KC_U       , KC_I    , KC_O   , KC_P    , KC_MINS,
  KC_BSPC , KC_A    , KC_S     , KC_D    , KC_F    , KC_G       ,                                              KC_H        , KC_J       , KC_K    , KC_L   , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z    , KC_X     , KC_C    , KC_V    , KC_B       ,                                              KC_N        , KC_M       , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT,
  KC_GRV  , KC_QUOT , ALT_SHFT , KC_LEFT , KC_RGHT ,                                                                         KC_SPC     , KC_ENT  , KC_UP  , KC_DOWN , KC_LBRC,
                                                     KC_RBRC    , TG(_WORKMAN) ,                 OSL(_LOWER) , KC_LSFT                                                        ,
                                                                  GUI          ,                 ENT                                                                          ,
                                           REPEAT  , TG(_RAISE) , CTRL         ,                 SPC         , TG(_QWERTY) , TG(_LOWER)
),

//    ┌─────────┬──────┬───────┬─────┬───────┬───────┐                            ┌─────┬─────┬─────┬────┬─────┬─────┐
//    │         │  f1  │  f2   │ f3  │  f4   │  f5   │                            │ f6  │ f7  │ f8  │ f9 │ f10 │ f11 │
//    ├─────────┼──────┼───────┼─────┼───────┼───────┤                            ├─────┼─────┼─────┼────┼─────┼─────┤
//    │    :    │  !   │   @   │  [  │   ]   │   |   │                            │  =  │  7  │  8  │ 9  │  *  │ f12 │
//    ├─────────┼──────┼───────┼─────┼───────┼───────┤                            ├─────┼─────┼─────┼────┼─────┼─────┤
//    │    _    │ '--' │   $   │  (  │   )   │   `   │                            │ '\' │  4  │  5  │ 6  │  +  │  _  │
//    ├─────────┼──────┼───────┼─────┼───────┼───────┤                            ├─────┼─────┼─────┼────┼─────┼─────┤
//    │         │  %   │   ^   │  {  │   }   │   ~   │                            │  &  │  1  │  2  │ 3  │  0  │  /  │
//    ├─────────┼──────┼───────┼─────┼───────┼───────┘                            └─────┼─────┼─────┼────┼─────┼─────┤
//    │ QK_BOOT │      │ C_TAB │ tab │ S_TAB │                                          │     │     │ -  │  _  │  0  │
//    └─────────┴──────┴───────┴─────┴───────┼───────┬─────┐               ┌──────┬─────┼─────┴─────┴────┴─────┴─────┘
//                                           │   =   │     │               │      │     │
//                                           └───────┼─────┤               ├──────┼─────┘
//                                                   │     │               │ lgui │
//                                   ┌───────┬───────┼─────┤               ├──────┼─────┬─────┐
//                                   │ lctl  │ S_GUI │     │               │ bspc │     │     │
//                                   └───────┴───────┴─────┘               └──────┴─────┴─────┘
[_LOWER] = LAYOUT_6x6(
  _______ , KC_F1   , KC_F2   , KC_F3   , KC_F4   , KC_F5   ,                                     KC_F6   , KC_F7   , KC_F8   , KC_F9   , KC_F10  , KC_F11 ,
  KC_COLN , KC_EXLM , KC_AT   , KC_LBRC , KC_RBRC , KC_PIPE ,                                     KC_EQL  , KC_7    , KC_8    , KC_9    , KC_ASTR , KC_F12 ,
  KC_UNDS , KC_HASH , KC_DLR  , KC_LPRN , KC_RPRN , KC_GRV  ,                                     KC_BSLS , KC_4    , KC_5    , KC_6    , KC_PLUS , KC_UNDS,
  _______ , KC_PERC , KC_CIRC , KC_LCBR , KC_RCBR , KC_TILD ,                                     KC_AMPR , KC_1    , KC_2    , KC_3    , KC_0    , KC_SLSH,
  QK_BOOT , _______ , C_TAB   , KC_TAB  , S_TAB   ,                                                         _______ , _______ , KC_MINS , KC_UNDS , KC_0   ,
                                                    KC_EQL  , _______ ,                 _______ , _______                                                  ,
                                                              _______ ,                 KC_LGUI                                                            ,
                                          KC_LCTL , S_GUI   , _______ ,                 KC_BSPC , _______ , _______
),

//    ┌─────────┬─────┬──────┬──────┬──────┬─────┐                               ┌─────┬──────┬──────────┬───────┬────────┬──────┐
//    │   SF2   │ SF7 │      │      │      │     │                               │     │      │          │       │        │      │
//    ├─────────┼─────┼──────┼──────┼──────┼─────┤                               ├─────┼──────┼──────────┼───────┼────────┼──────┤
//    │         │     │ wh_u │ ms_u │ wh_d │     │                               │     │ tab  │    up    │ S_TAB │ C_TAB  │      │
//    ├─────────┼─────┼──────┼──────┼──────┼─────┤                               ├─────┼──────┼──────────┼───────┼────────┼──────┤
//    │  SCROT  │     │ ms_l │ ms_d │ ms_r │     │                               │     │ left │   down   │ rght  │ CS_TAB │      │
//    ├─────────┼─────┼──────┼──────┼──────┼─────┤                               ├─────┼──────┼──────────┼───────┼────────┼──────┤
//    │         │     │ btn3 │ btn1 │ btn2 │     │                               │     │      │   mprv   │ mnxt  │        │      │
//    ├─────────┼─────┼──────┼──────┼──────┼─────┘                               └─────┼──────┼──────────┼───────┼────────┼──────┤
//    │ QK_BOOT │     │      │      │      │                                           │      │ www_back │ volu  │  vold  │ mute │
//    └─────────┴─────┴──────┴──────┴──────┼─────┬─────┐               ┌─────────┬─────┼──────┴──────────┴───────┴────────┴──────┘
//                                         │     │     │               │         │     │
//                                         └─────┼─────┤               ├─────────┼─────┘
//                                               │     │               │         │
//                                  ┌──────┬─────┼─────┤               ├─────────┼─────┬──────┐
//                                  │      │     │     │               │ L2_BSPC │     │      │
//                                  └──────┴─────┴─────┘               └─────────┴─────┴──────┘
[_RAISE] = LAYOUT_6x6(
  SF2     , SF7     , _______ , _______ , _______ , _______ ,                                     _______ , _______ , _______ , _______  , _______ , _______,
  _______ , _______ , KC_WH_U , KC_MS_U , KC_WH_D , _______ ,                                     _______ , KC_TAB  , KC_UP   , S_TAB    , C_TAB   , _______,
  SCROT   , _______ , KC_MS_L , KC_MS_D , KC_MS_R , _______ ,                                     _______ , KC_LEFT , KC_DOWN , KC_RIGHT , CS_TAB  , _______,
  _______ , _______ , KC_BTN3 , KC_BTN1 , KC_BTN2 , _______ ,                                     _______ , _______ , KC_MPRV , KC_MNXT  , _______ , _______,
  QK_BOOT , _______ , _______ , _______ , _______ ,                                                         _______ , KC_WBAK , KC_VOLU  , KC_VOLD , KC_MUTE,
                                                    _______ , _______ ,                 _______ , _______                                                   ,
                                                              _______ ,                 _______                                                             ,
                                          _______ , _______ , _______ ,                 L2_BSPC , _______ , _______
)
};

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;

// Initialize variables holding the bitfield
// representation of active modifiers.
uint8_t mod_state;
uint8_t oneshot_mod_state;

void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    if (keycode != REPEAT) {
        // Early return when holding down a pure layer key
        // to retain modifiers
        switch (keycode) {
            case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            case QK_TO ... QK_TO_MAX:
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
                return;
        }
        last_modifier = oneshot_mod_state > mod_state ? oneshot_mod_state : mod_state;
        switch (keycode) {
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                if (record->event.pressed) {
                    last_keycode = GET_TAP_KC(keycode);
                }
                break;
            default:
                if (record->event.pressed) {
                    last_keycode = keycode;
                }
                break;
        }
    } else { // keycode == REPEAT
        if (record->event.pressed) {
            register_mods(last_modifier);
            register_code16(last_keycode);
        } else {
            unregister_code16(last_keycode);
            unregister_mods(last_modifier);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_repeat_key(keycode, record);
    // It's important to update the mod variables *after* calling process_repeat_key, or else
    // only a single modifier from the previous key is repeated (e.g. Ctrl+Shift+T then Repeat produces Shift+T)
    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    return true;
};
