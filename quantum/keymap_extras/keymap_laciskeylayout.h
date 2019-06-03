 /* Copyright 2016 Stephen Bösebeck
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
// Mapping the German OSX Macros to Lacis Keylayout
#ifndef KEYMAP_LACI
#define KEYMAP_LACI

#include "keymap_german_osx.h"

// Alt gr

// normal characters
#define LACI_X DE_OSX_Z
#define LACI_SMALLER DE_OSX_Y

#define LACI_N DE_OSX_A
#define LACI_KOMMA DE_OSX_B
#define LACI_G DE_OSX_C
#define LACI_E DE_OSX_D
#define LACI_S DE_OSX_E
#define LACI_I DE_OSX_F
#define LACI_Y DE_OSX_G
#define LACI_J DE_OSX_H
#define LACI_P DE_OSX_I
#define LACI_O DE_OSX_J
#define LACI_U DE_OSX_K
#define LACI_L DE_OSX_L
#define LACI_B DE_OSX_M
#define LACI_H DE_OSX_N
#define LACI_C DE_OSX_O
#define LACI_V DE_OSX_P
#define LACI_Q DE_OSX_Q
#define LACI_R DE_OSX_R
#define LACI_A DE_OSX_S
#define LACI_Z DE_OSX_T
#define LACI_T DE_OSX_U
#define LACI_M DE_OSX_V
#define LACI_K DE_OSX_W
#define LACI_D DE_OSX_X

#define LACI_7 DE_OSX_0
#define LACI_8 DE_OSX_1
#define LACI_6 DE_OSX_2
#define LACI_4 DE_OSX_3
#define LACI_2 DE_OSX_4
#define LACI_0 DE_OSX_5
#define LACI_EQUALS DE_OSX_6
#define LACI_1 DE_OSX_7
#define LACI_3 DE_OSX_8
#define LACI_5 DE_OSX_9

#define LACI_MINUS DE_OSX_DOT
#define LACI_DOT DE_OSX_COMM

#define LACI_9 DE_OSX_SS
#define LACI_W DE_OSX_AE
#define LACI_LBRACE DE_OSX_UE
#define LACI_F DE_OSX_OE

#define LACI_QUESTION DE_OSX_CIRC // accent circumflex ^ and ring °
#define LACI_AT DE_OSX_ACUT // accent acute ´ and grave `
#define LACI_RBRACE DE_OSX_PLUS // + and * and ~
#define LACI_APOSTROPHE DE_OSX_HASH // # and '
#define LACI_SLASH DE_OSX_LESS // < and > and |
#define LACI_PLUS DE_OSX_MINS // - and _

// modifiers
#define LACI_LCMD KC_LALT
#define LACI_RCMD KC_RALT
#define LACI_LALT KC_LGUI
#define LACI_RALT KC_RGUI
#define LACI_MOD_LCMD MOD_LALT
#define LACI_MOD_RCMD MOD_RALT
#define LACI_MOD_LALT MOD_LGUI
#define LACI_MOD_RALT MOD_RGUI

// shifted characters
//#define DE_OSX_RING LSFT(DE_OSX_CIRC) // °
//#define DE_OSX_EXLM LSFT(KC_1) // !
/* #define DE_OSX_DQOT LSFT(KC_2) // "
#define DE_OSX_PARA LSFT(KC_3) // §
#define DE_OSX_DLR  LSFT(KC_4) // $
#define DE_OSX_PERC LSFT(KC_5) // %
#define DE_OSX_AMPR LSFT(KC_6) // &
#define DE_OSX_SLSH LSFT(KC_7) // /
#define DE_OSX_LPRN LSFT(KC_8) // (
#define DE_OSX_RPRN LSFT(KC_9) // )
#define DE_OSX_EQL  LSFT(KC_0) // =
#define DE_OSX_QST  LSFT(DE_OSX_SS) // ?
#define DE_OSX_GRV  LSFT(DE_OSX_ACUT) // `
#define DE_OSX_ASTR LSFT(DE_OSX_PLUS) // *
#define DE_OSX_QUOT LSFT(DE_OSX_HASH) // '
#define DE_OSX_MORE LSFT(DE_OSX_LESS) // >
#define DE_OSX_COLN LSFT(KC_DOT) // :
#define DE_OSX_SCLN LSFT(KC_COMM) // ;
#define DE_OSX_UNDS LSFT(DE_OSX_MINS) // _

// Alt-ed characters
//#define DE_OSX_SQ2 LALT(KC_2) // ²
//#define DE_OSX_SQ3 LALT(KC_3) // ³
#define DE_OSX_LCBR LALT(KC_8) // {
#define DE_OSX_LBRC LALT(KC_5) // [
#define DE_OSX_RBRC LALT(KC_6) // ]
#define DE_OSX_RCBR LALT(KC_9) // }
#define DE_OSX_BSLS LALT(LSFT(KC_7)) // backslash
#define DE_OSX_AT  LALT(DE_OSX_L) // @
#define DE_OSX_EURO LALT(KC_E) // €
#define DE_OSX_TILD LALT(DE_OSX_N) // ~
#define DE_OSX_PIPE LALT(DE_OSX_7) // */

#endif
