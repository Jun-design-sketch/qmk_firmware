// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

/* -------------------------------------------------------------------------- */
/* Miryoku mouse compatibility shim (QMK ≥ 0.22, QK_MOUSE_* / MS_* aliases)   */
/* - Keeps legacy KC_MS_*, KC_WH_*, KC_BTN* names used by Miryoku layers      */
/* - Maps them to current QMK mouse keycodes                                  */
/* - Only defines when not already defined to avoid redefinition warnings     */
/* -------------------------------------------------------------------------- */

/* Cursor (pointer) */
#ifndef KC_MS_L
#  ifdef MS_LEFT
#    define KC_MS_L MS_LEFT
#    define KC_MS_R MS_RGHT
#    define KC_MS_U MS_UP
#    define KC_MS_D MS_DOWN
#  else
#    define KC_MS_L QK_MOUSE_CURSOR_LEFT
#    define KC_MS_R QK_MOUSE_CURSOR_RIGHT
#    define KC_MS_U QK_MOUSE_CURSOR_UP
#    define KC_MS_D QK_MOUSE_CURSOR_DOWN
#  endif
#endif

/* Wheel (scroll) */
#ifndef KC_WH_L
#  ifdef MS_WHLL
#    define KC_WH_L MS_WHLL
#    define KC_WH_R MS_WHLR
#    define KC_WH_U MS_WHLU
#    define KC_WH_D MS_WHLD
#  else
#    define KC_WH_L QK_MOUSE_WHEEL_LEFT
#    define KC_WH_R QK_MOUSE_WHEEL_RIGHT
#    define KC_WH_U QK_MOUSE_WHEEL_UP
#    define KC_WH_D QK_MOUSE_WHEEL_DOWN
#  endif
#endif

/* Buttons */
#ifndef KC_BTN1
#  ifdef MS_BTN1
#    define KC_BTN1 MS_BTN1
#    define KC_BTN2 MS_BTN2
#    define KC_BTN3 MS_BTN3
#    define KC_BTN4 MS_BTN4
#    define KC_BTN5 MS_BTN5
#    define KC_BTN6 MS_BTN6
#    define KC_BTN7 MS_BTN7
#    define KC_BTN8 MS_BTN8
#  else
#    define KC_BTN1 QK_MOUSE_BUTTON_1
#    define KC_BTN2 QK_MOUSE_BUTTON_2
#    define KC_BTN3 QK_MOUSE_BUTTON_3
#    define KC_BTN4 QK_MOUSE_BUTTON_4
#    define KC_BTN5 QK_MOUSE_BUTTON_5
#    define KC_BTN6 QK_MOUSE_BUTTON_6
#    define KC_BTN7 QK_MOUSE_BUTTON_7
#    define KC_BTN8 QK_MOUSE_BUTTON_8
#  endif
#endif

/* (Optional) Acceleration presets — use if your keymap references KC_ACL* */
#ifndef KC_ACL0
#  ifdef MS_ACL0
#    define KC_ACL0 MS_ACL0
#    define KC_ACL1 MS_ACL1
#    define KC_ACL2 MS_ACL2
#  else
#    define KC_ACL0 QK_MOUSE_ACCELERATION_0
#    define KC_ACL1 QK_MOUSE_ACCELERATION_1
#    define KC_ACL2 QK_MOUSE_ACCELERATION_2
#  endif
#endif

/* ---- Legacy RGB_* keycodes -> New QMK keycodes shim ---- */
/* Put this near the top of manna-harbour_miryoku.h */

#if defined(RGBLIGHT_ENABLE)
/* Underglow(언더글로우) 사용 시: RGB_*를 UG_*로 매핑 */
#  undef RGB_TOG
#  undef RGB_MOD
#  undef RGB_HUI
#  undef RGB_HUD
#  undef RGB_SAI
#  undef RGB_SAD
#  undef RGB_VAI
#  undef RGB_VAD
#  undef RGB_SPI
#  undef RGB_SPD

#  define RGB_TOG QK_UNDERGLOW_TOGGLE
#  define RGB_MOD QK_UNDERGLOW_MODE_NEXT         /* 예전 ‘모드 전환’ */
#  define RGB_HUI QK_UNDERGLOW_HUE_UP
#  define RGB_HUD QK_UNDERGLOW_HUE_DOWN
#  define RGB_SAI QK_UNDERGLOW_SATURATION_UP
#  define RGB_SAD QK_UNDERGLOW_SATURATION_DOWN
#  define RGB_VAI QK_UNDERGLOW_VALUE_UP          /* 밝기 ↑ */
#  define RGB_VAD QK_UNDERGLOW_VALUE_DOWN        /* 밝기 ↓ */
#  define RGB_SPI QK_UNDERGLOW_SPEED_UP
#  define RGB_SPD QK_UNDERGLOW_SPEED_DOWN

#elif defined(RGB_MATRIX_ENABLE)
/* RGB Matrix 사용 시: RGB_*를 RM_*로 매핑 */
#  undef RGB_TOG
#  undef RGB_MOD
#  undef RGB_HUI
#  undef RGB_HUD
#  undef RGB_SAI
#  undef RGB_SAD
#  undef RGB_VAI
#  undef RGB_VAD
#  undef RGB_SPI
#  undef RGB_SPD

#  define RGB_TOG QK_RGB_MATRIX_TOGGLE
#  define RGB_MOD QK_RGB_MATRIX_MODE_NEXT
#  define RGB_HUI QK_RGB_MATRIX_HUE_UP
#  define RGB_HUD QK_RGB_MATRIX_HUE_DOWN
#  define RGB_SAI QK_RGB_MATRIX_SATURATION_UP
#  define RGB_SAD QK_RGB_MATRIX_SATURATION_DOWN
#  define RGB_VAI QK_RGB_MATRIX_VALUE_UP
#  define RGB_VAD QK_RGB_MATRIX_VALUE_DOWN
#  define RGB_SPI QK_RGB_MATRIX_SPEED_UP
#  define RGB_SPD QK_RGB_MATRIX_SPEED_DOWN

#else
/* 둘 다 꺼진 보드에서도 컴파일만 되게 하기 */
#  undef RGB_TOG
#  undef RGB_MOD
#  undef RGB_HUI
#  undef RGB_HUD
#  undef RGB_SAI
#  undef RGB_SAD
#  undef RGB_VAI
#  undef RGB_VAD
#  undef RGB_SPI
#  undef RGB_SPD

#  define RGB_TOG KC_NO
#  define RGB_MOD KC_NO
#  define RGB_HUI KC_NO
#  define RGB_HUD KC_NO
#  define RGB_SAI KC_NO
#  define RGB_SAD KC_NO
#  define RGB_VAI KC_NO
#  define RGB_VAD KC_NO
#  define RGB_SPI KC_NO
#  define RGB_SPD KC_NO
#endif

/* 주의: 아래의 예전 RGB_MODE_* 계열은 QMK 최신에선 제거됨
   -> 해당 키코드를 쓰던 자리는 UG_NEXT/RM_NEXT 로 교체하거나, KC_NO로 막으세요. */


#include "miryoku_babel/miryoku_layer_selection.h"
#include "miryoku_babel/miryoku_layer_list.h"

enum miryoku_layers {
#define MIRYOKU_X(LAYER, STRING) U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

#define U_MACRO_VA_ARGS(macro, ...) macro(__VA_ARGS__)

#if !defined (MIRYOKU_MAPPING)
  #define MIRYOKU_MAPPING LAYOUT_miryoku
#endif

#define U_NP KC_NO // key is not present
#define U_NA KC_NO // present but not available for use
#define U_NU KC_NO // available but not used

#if defined (MIRYOKU_CLIPBOARD_FUN)
  #define U_RDO KC_AGIN
  #define U_PST KC_PSTE
  #define U_CPY KC_COPY
  #define U_CUT KC_CUT
  #define U_UND KC_UNDO
#elif defined (MIRYOKU_CLIPBOARD_MAC)
  #define U_RDO SCMD(KC_Z)
  #define U_PST LCMD(KC_V)
  #define U_CPY LCMD(KC_C)
  #define U_CUT LCMD(KC_X)
  #define U_UND LCMD(KC_Z)
#elif defined (MIRYOKU_CLIPBOARD_WIN)
  #define U_RDO C(KC_Y)
  #define U_PST C(KC_V)
  #define U_CPY C(KC_C)
  #define U_CUT C(KC_X)
  #define U_UND C(KC_Z)
#else
  #define U_RDO KC_AGIN
  #define U_PST S(KC_INS)
  #define U_CPY C(KC_INS)
  #define U_CUT S(KC_DEL)
  #define U_UND KC_UNDO
#endif
