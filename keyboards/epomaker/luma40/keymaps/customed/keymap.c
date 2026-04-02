/* Copyright 2025 Carlos Eduardo de Paula <carlosedp@gmail.com>
 * Copyright 2025 EPOMAKER <https://github.com/Epomaker>
 * Copyright 2023 LiWenLiu <https://github.com/LiuLiuQMK>
 * Copyright 2021 QMK <https://github.com/qmk/qmk_firmware>
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

#include QMK_KEYBOARD_H
#include "rdmctmzt_common.h"
#include "process_combo.h"

enum layers {
    BASE = 0,
    MEDIA,
    NAV,
    MOUSE,
    SYM,
    NUM,
    FUN
};

enum custom_keycodes {
    BOOTKEY1 = SAFE_RANGE,
    BOOTKEY2,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_tkl_ansi(
        KC_Q,    KC_W,    KC_E,      KC_R,    KC_T,    BOOTKEY1, BOOTKEY2, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,      KC_F,    KC_G,    XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,      KC_V,    KC_B,    XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
        XXXXXXX, XXXXXXX, LT(MEDIA,  KC_ESC), LT(NAV, KC_SPC), LT(MOUSE, KC_TAB), XXXXXXX, LT(SYM, KC_ENT), LT(NUM, KC_BSPC), LT(FUN, KC_DEL), XXXXXXX, XXXXXXX
    ),

    [NAV] = LAYOUT_tkl_ansi(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, G(S(KC_Z)), G(KC_V), G(KC_C), G(KC_X), G(KC_Z),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  KC_HOME, KC_PGDN, KC_PGUP, KC_END,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [MOUSE] = LAYOUT_tkl_ansi(
        XXXXXXX, XXXXXXX, XXXXXXX, MS_ACL0, MS_ACL2, XXXXXXX, XXXXXXX, G(S(KC_Z)), G(KC_V), G(KC_C), G(KC_X), G(KC_Z),
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN1, XXXXXXX, XXXXXXX, XXXXXXX, MS_LEFT, MS_DOWN, MS_UP,   MS_RGHT,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MS_BTN2, XXXXXXX, XXXXXXX, XXXXXXX, MS_WHLL, MS_WHLD, MS_WHLU, MS_WHLR,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          MS_BTN2, MS_BTN1, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [NUM] = LAYOUT_tkl_ansi(
        XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_4,    KC_5,    KC_6,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_1,    KC_2,    KC_3,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_0,    XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [SYM] = LAYOUT_tkl_ansi(
        XXXXXXX, KC_AMPR, KC_ASTR, KC_LPRN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_DLR,  KC_PERC, KC_CIRC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_EXLM, KC_AT,   KC_HASH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_RPRN, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [FUN] = LAYOUT_tkl_ansi(
        KC_F12,  KC_F7,   KC_F8,   KC_F9,   KC_PSCR, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_SCRL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_F10,  KC_F1,   KC_F2,   KC_F3,   KC_PAUS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [MEDIA] = LAYOUT_tkl_ansi(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BAT,
        RM_TOGG, RM_HUED, RM_HUEU, RM_NEXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
        RM_SATD, RM_SATU, RM_VALD, RM_VALU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, MD_BLE1, MD_BLE2, MD_BLE3, MD_24G,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          KC_MUTE, KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX
    )
};
// clang-format on
const uint16_t PROGMEM dfu_combo[] = {BOOTKEY1, BOOTKEY2, COMBO_END};

enum combo_events {
    DFU_COMBO,
};

combo_t key_combos[] = {
    [DFU_COMBO] = COMBO(dfu_combo, QK_BOOT),
};

bool get_combo_must_hold(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case DFU_COMBO:
            return true;
        default:
            return false;
    }
}

uint16_t get_combo_term(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        case DFU_COMBO:
            return 2000;
        default:
            return COMBO_TERM;
    }
}
