/* Copyright 2022  CyanDuck
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
	_NAV,
	_SYM,
    _NUM,
	_SHORT,
	_MOUSE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |                      |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  | MUTE|    | CAPS|  |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          | ALL |   | ESC | ENTER | TAB  |            |  BS | SPACE | DEL  |   | SRCH|
 *          `-----'   `--------------------'            `--------------------'   `-----'
 *                       1      2      3                   1      2      3
 *
 * L_Roller: Switch Virtual Desktops, L_Encoder: Volume Control
 * R_Roller: Arrow Keys, R_Encoder: Switch Tabs
 * Homerow Mods enabled
 * Alt+Shift+Ctrl on R Cluster 3
 * Alt+Ctrl+Win on L Cluster 1
 * To Nav on L Cluster 2
 * To Symbol on R Cluster 2
 * To Num on LC2 + RC2
 * To Mouse on H
 * To Shortcuts on R Cluster 1
 */
[_QWERTY] = LAYOUT(
	KC_Q,				KC_W,				KC_E,				KC_R,				KC_T,			KC_Y,	    KC_U,				KC_I,				KC_O,				KC_P,
	LGUI_T(KC_A),       LALT_T(KC_S),	    LSFT_T(KC_D),	    LCTL_T(KC_F),	    KC_G,			KC_H,	    RCTL_T(KC_J),	    RSFT_T(KC_K),	    LALT_T(KC_L),	    RGUI_T(KC_SCLN),
	KC_Z,				KC_X,				KC_C,				KC_V,				KC_B,			KC_N,	    KC_M,				KC_COMM,			KC_DOT,				KC_SLSH,
	LWIN(KC_TAB),		KC_ESC,				LT(_NAV, KC_ENT),	KC_TAB,				KC_MUTE,		KC_CAPS,    KC_BSPC,			KC_SPACE,			LT(2,KC_DEL),		LALT(KC_SPACE)
),

/* NAV
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |      |      |      |                      |  INS | Home | PgUp | PgDn |  End |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |  Win |  Alt | SHFT | CTRL |      |                      | Left | Down |  Up  | Right|      |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |      |      |      |  |     |    |     |  |   *  |   #  |   ^  |   $  |   ~  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |     |   |     |   ^   |      |            |     | toNum |      |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 * To Num on LC2 + RC2
 */
[_NAV] =  LAYOUT(
	KC_NO,		KC_NO,			KC_NO,			KC_NO,		KC_NO,		KC_INS,		KC_HOME,	KC_PGUP,	KC_PGDN,		KC_END,
	KC_LGUI,	KC_LALT,		KC_LSFT,		KC_LCTL,	KC_NO,		KC_LEFT,	KC_DOWN,	KC_UP,		KC_RIGHT,		KC_NO,
	KC_NO,		KC_NO,			KC_NO,			KC_NO,		KC_NO,		KC_ASTR,	KC_HASH,	KC_CIRC,	KC_DLR,			KC_TILD,
	KC_NO,		KC_NO,			KC_TRNS,		KC_NO,		KC_NO,		KC_NO,		KC_NO,		MO(_NUM),		KC_NO,		KC_NO
),

/* SYM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   !  |   #  |   &  |   [  |   ]  |                      |   `  |   \  |   *  |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   @  |   $  |   |  |   (  |   )  |                      |   ~  |   =  |   +  |   -  |   _  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   ^  |   %  |   '  |   {  |   }  |  |     |    |     |  |      |   "  |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |     |   | ESC | ENTER | TAB  |            |  BS | SPACE | DEL  |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 * Homerow Mods enabled
 */
[_SYM] = LAYOUT(
	KC_PERC,	KC_AT,			KC_LBRC,		KC_RBRC,	KC_BSLS,		KC_NO,		KC_NO,		KC_CIRC,	KC_NO,			KC_NO,
	KC_HASH,	KC_EXLM,		KC_LPRN,		KC_RPRN,	KC_PIPE,		KC_UNDS,	KC_QUOT,	KC_DQT,		KC_TILD,		KC_GRV,
	KC_DLR,		KC_NO,			KC_LCBR,		KC_RCBR,	KC_AMPR,		KC_NO,		KC_NO,		KC_NO,		KC_NO,			KC_NO,
	KC_1,		LT(3,KC_DEL),	LT(1,KC_SPC),	KC_TAB,		KC_CAPS,		KC_NUM,		KC_ESC,		KC_BSPC,	LT(2,KC_ENT),	KC_4
),


/* NUM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |                      |  F6  |  F7  |  F8  |  F9  |  F10 |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   1  |   2  |   3  |   4  |   5  |                      |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |  F11 |  F12 |  F13 |      |  F15 |  |     |    |     |  |  F17 |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |     |   | ESC | ENTER | TAB  |            |  BS | SPACE | DEL  |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 * Homerow Mods enabled
 */
[_NUM] = LAYOUT(
	KC_NO,		KC_PGUP,		KC_UP,			KC_PGDN,	KC_NO,				KC_SLSH,	KC_7,	KC_8,		KC_9,			KC_MINS,
	KC_HOME,	KC_LEFT,		KC_DOWN,		KC_RGHT,	KC_END,				KC_EQL,		KC_4,	KC_5,		KC_6,			KC_PLUS,
	KC_NO,		KC_NO,			KC_INS,			KC_NO,		KC_NO,				KC_0,		KC_1,	KC_2,		KC_3,			KC_ASTR,
	KC_1,		LT(3,KC_DEL),	LT(1,KC_SPC),	KC_TAB,		KC_CAPS,			KC_NUM,		KC_ESC,	KC_BSPC,	LT(2,KC_ENT),	KC_4
),


/* Shortcuts
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |Expand|      | Help |                      | Save | S+INS| Info |Detail|Search|
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |      | Scrn | CAPW |      |      |                      | Back | Play | Next |      |      |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      | ShrX | CAPS | Menu |      |  |     |    |     |  | Lock |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |     |   | ESC | ENTER | TAB  |            |  BS | SPACE | DEL  |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
*/
[_SHORT] = LAYOUT(
	KC_NO,	KC_NO,			KC_NO,			KC_NO,	KC_NO,			KC_NO,	KC_F7,	KC_F8,		KC_F9,			KC_F11,
	KC_NO,	KC_NO,			KC_NO,			KC_NO,	KC_NO,			KC_NO,	KC_F4,	KC_F5,		KC_F6,			KC_F12,
	KC_NO,	KC_NO,			KC_NO,			KC_NO,	KC_NO,			KC_F10,	KC_F1,	KC_F2,		KC_F3,			KC_F13,
	KC_1,	LT(3,KC_DEL),	LT(1,KC_SPC),	KC_TAB,	KC_CAPS,		KC_NUM,	KC_ESC,	KC_BSPC,	LT(2,KC_ENT),	KC_4
),

/* Mouse Layer
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |  MUp |      |      |                      |      |      |      |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |      | MLeft| MDown|MRight|      |                      |      |      |      |      |      |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |      | RClk |      |  |     |    |     |  |      |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          | MClk|   |     | LClick| RClk |            |     |       |      |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 * L Roller: Control Mouse Wheel, L Encoder: Mouse Wheel
 */
};

#if defined(ENCODER_MAP_ENABLE)

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = {   ENCODER_CCW_CW(LCTL(LWIN(KC_LEFT)), LCTL(LWIN(KC_RIGHT))),
                    ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
                    ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
                    ENCODER_CCW_CW(LCTL(KC_TAB), RCS(KC_TAB)) },
    [_NAV] = {},
    [_SYM] = {},
    [_NUM] = {},
    [_SHORT] = {},
    /* [_MOUSE] = {    ENCODER_CCW_CW(LSFT(KC_MS_WH_DOWN), LSFT(KC_MS_WH_UP)),
                    ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)} */
};

#endif
