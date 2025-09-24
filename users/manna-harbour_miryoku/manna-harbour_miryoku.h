// Copyright 2022 Manna Harbour
// https://github.com/manna-harbour/miryoku

// This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 2 of the License, or (at your option) any later version. This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details. You should have received a copy of the GNU General Public License along with this program. If not, see <http://www.gnu.org/licenses/>.

#pragma once

// --- Miryoku mouse/wheel/button + RGB: KC-전용 fallback ---
// 있는 키코드만 쓰고, 없으면 KC_NO로 죽여서 컴파일 에러를 막습니다.

// 마우스 커서 이동
#ifndef KC_MS_L
#  ifdef KC_MS_LEFT
#    define KC_MS_L KC_MS_LEFT
#    define KC_MS_R KC_MS_RIGHT
#    define KC_MS_U KC_MS_UP
#    define KC_MS_D KC_MS_DOWN
#  else
#    define KC_MS_L KC_NO
#    define KC_MS_R KC_NO
#    define KC_MS_U KC_NO
#    define KC_MS_D KC_NO
#  endif
#endif

// 스크롤(휠)
#ifndef KC_WH_L
#  ifdef KC_WH_LEFT
#    define KC_WH_L KC_WH_LEFT
#    define KC_WH_R KC_WH_RIGHT
#    define KC_WH_U KC_WH_UP
#    define KC_WH_D KC_WH_DOWN
#  else
#    define KC_WH_L KC_NO
#    define KC_WH_R KC_NO
#    define KC_WH_U KC_NO
#    define KC_WH_D KC_NO
#  endif
#endif

// 마우스 버튼
#ifndef KC_BTN1
#  ifdef KC_MS_BTN1
#    define KC_BTN1 KC_MS_BTN1
#    define KC_BTN2 KC_MS_BTN2
#    define KC_BTN3 KC_MS_BTN3
#  elif defined(KC_BTN1) // 일부 보드에선 이미 정의
    /* 그대로 둠 */
#  else
#    define KC_BTN1 KC_NO
#    define KC_BTN2 KC_NO
#    define KC_BTN3 KC_NO
#  endif
#endif

// RGB(없으면 무시)
#ifndef RGB_TOG
#  define RGB_TOG KC_NO
#  define RGB_MOD KC_NO
#  define RGB_HUI KC_NO
#  define RGB_SAI KC_NO
#  define RGB_VAI KC_NO
#endif

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
