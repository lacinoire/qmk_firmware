// To work this needs the current version of lacis_keylayout

#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_laciskeylayout.h"
#include "rgblight_list.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

//define modifiers
#define MODS_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MODS_CTRL_MASK  (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTL))
#define MODS_ALT_MASK  (MOD_BIT(LACI_LALT)|MOD_BIT(LACI_RALT))
#define MODS_CMD_MASK  (MOD_BIT(LACI_LCMD)|MOD_BIT(LACI_RCMD))

//Tap Dance Declarations
enum {
  TD_ESC_CAPS = 0
};

//In Layer declaration, add tap dance item in place of a key code
//TD(TD_ESC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ?    |   8  |   6  |   4  |   2  |   0  | ESC  |           |   =  |   1  |   3  |   5  |   7  |   9  |   @    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   (    |   Q  |   K  |   S  |   R  |   Z  |  Alt |           |  V+  |   X  |   T  |   P  |   C  |   V  |   )    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   ?    |   N  |   A  |   E  |   I  |   Y  |------|           |------|   J  |   O  |   U  |   L  |   F  |   W    |
 * |--------+------+------+------+------+------| Shift|           |  V-  |------+------+------+------+------+--------|
 * |   /    |   <  |   D  |   G  |   M  |   ,  |      |           |      |   +  |   H  |   B  |   .  |   -  | '      |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | SYMB |  B-  |  B+  | Redo | Undo |                                       | Left |  Up  | Down | Right| MDIA |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Del  |  Cut |       | Prev | Alfr |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Copy |       | Next |      |      |
 *                                 | Enter| Tab  |------|       |------|Backsp|Space |
 *                                 |      |      | Paste|       | Pause|      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        SH_TT,      LACI_8,             LACI_6,                    LACI_4, LACI_2, LACI_0,    TD(TD_ESC_CAPS),
        LACI_LBRACE,        LACI_Q,             LACI_K,                    MT(MOD_LCTL, LACI_S),      LACI_R,               LACI_Z,     LACI_LALT,
        LACI_QUESTION,      LACI_N,             MT(LACI_MOD_LCMD, LACI_A), MT(LACI_MOD_LALT, LACI_E), MT(MOD_LSFT, LACI_I), LACI_Y,
        LACI_SLASH,         LACI_SMALLER,       LACI_D,                    LACI_G,                    LACI_M,               LACI_KOMMA, KC_LSHIFT,
        MO(SYMB),           KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP,          LSFT(LALT(LACI_Z)),        LALT(LACI_Z),

                                                        LALT(LACI_X), LALT(LACI_A),
                                                                   LALT(LACI_C),
                                              KC_ENTER, KC_TAB,   LALT(LACI_V),
        // right hand
            LACI_EQUALS,    LACI_1,    LACI_3,               LACI_5,                    LACI_7,                    LACI_9,     LACI_AT,
            KC__VOLUP,      LACI_X,    LACI_T,               MT(MOD_RCTL, LACI_P),      LACI_C,                    LACI_V,     LACI_RBRACE,
                            LACI_J,    MT(MOD_RSFT, LACI_O), MT(LACI_MOD_RALT, LACI_U), MT(LACI_MOD_RCMD, LACI_L), LACI_F,     LACI_W,
            KC__VOLDOWN,    LACI_PLUS, LACI_H,               LACI_B,                    LACI_DOT,                  LACI_MINUS, LACI_APOSTROPHE,
                                       KC_LEFT,              KC_UP,                     KC_DOWN,                   KC_RIGHT,   MO(MDIA),

            KC_MEDIA_REWIND,       LGUI(KC_SPACE),
            KC_MEDIA_FAST_FORWARD,
            KC_MEDIA_PLAY_PAUSE,   KC_BSPACE,   KC_SPACE
    ),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left handi
       VRSN,   KC_F8,  KC_F6,  KC_F4,  KC_F2,  KC_F10,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
          EPRM,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       RGB_MOD,KC_TRNS,
                                               KC_TRNS,
                               RGB_VAD,RGB_VAI,KC_TRNS,
       // right hand
       KC_TRNS, KC_F1,   KC_F3,  KC_F5,   KC_F7,   KC_F9,  KC_F11,
       KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_F12,
                KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_1,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
                         KC_TRNS,KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,
       RGB_TOG, RGB_SLD,
       KC_TRNS,
       KC_TRNS, RGB_HUD, RGB_HUI
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
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
                          KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_WBAK
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    ergodox_right_led_3_on();
    #ifdef RGBLIGHT_ENABLE
      rgblight_init();
    #endif
    #ifdef RGBLIGHT_COLOR_LAYER_0
      rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
    #endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  uint8_t modifiers = get_mods();
  uint8_t one_shot = get_oneshot_mods();

  // Since we're not using the LEDs here for layer indication anymore,
  // then lets use them for modifier indicators.  Shame we don't have 4...
  // Also, no "else", since we want to know each, independently.
  if ( ( modifiers | one_shot ) & MODS_SHIFT_MASK) {
      rgblight_sethsv_range(HSV_CYAN, 11, 15);
  } else {
    #ifdef RGBLIGHT_COLOR_LAYER_0
      rgblight_setrgb_range(RGBLIGHT_COLOR_LAYER_0, 11, 15);
    #endif
  }
  if ( ( modifiers | one_shot ) & MODS_ALT_MASK) {
      rgblight_sethsv_range(HSV_BLUE, 7, 11);
  } else {
    #ifdef RGBLIGHT_COLOR_LAYER_0
      rgblight_setrgb_range(RGBLIGHT_COLOR_LAYER_0, 7, 11);
    #endif
  }
  if ( ( modifiers | one_shot ) & MODS_CMD_MASK) {
      rgblight_sethsv_range(HSV_PURPLE, 3, 7);
  } else {
    #ifdef RGBLIGHT_COLOR_LAYER_0
      rgblight_setrgb_range(RGBLIGHT_COLOR_LAYER_0, 3, 7);
    #endif
  }
  if ( ( modifiers | one_shot ) & MODS_CTRL_MASK) {
      rgblight_sethsv_range(HSV_MAGENTA, 0, 3);
  } else {
    #ifdef RGBLIGHT_COLOR_LAYER_0
      rgblight_setrgb_range(RGBLIGHT_COLOR_LAYER_0, 0, 3);
    #endif
  }

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on(); // todo fix for more layers
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_ESC_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_F24)
// Other declarations would go here, separated by commas, if you have them
};
