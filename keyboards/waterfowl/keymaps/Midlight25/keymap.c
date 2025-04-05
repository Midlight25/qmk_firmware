/* Copyright 2022 CyanDuck Modified 2024 Midlight
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

#define HEH_ESC MT(MOD_LCTL | MOD_LALT | MOD_LGUI, KC_ESC)
#define MOD_HEH (MOD_LCTL | MOD_LALT | MOD_LGUI)

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _NAV,
    _SYM,
    _NUM,
    _SHORT,
    _MOUSE,
};

enum custom_keycodes {
    M_INFO = SAFE_RANGE,
    M_DETL,
    M_SRCH,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // clang-format off
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
 *          | ALL |   | ESC | ENTER | TAB  |            | BSPC| SPACE | DEL  |   | SRCH|
 *          `-----'   `--------------------'            `--------------------'   `-----'
 *                       1      2      3                   1      2      3
 *
 * L_Roller: Switch Virtual Desktops, L_Encoder: Volume Control
 * R_Roller: Arrow Keys, R_Encoder: Switch Tabs
 * Homerow Mods enabled
 * Ctrl+Alt+Win on L Cluster 1
 * To Shortcuts on L Cluster 2
 * To Num on L Cluster 3
 * To Symbol on R Cluster 1
 * To Nav on R Cluster 2
 * Alt+Shift+Ctrl on R Cluster 3
 * To Mouse on /
 */
[_QWERTY] = LAYOUT(
	KC_Q,				KC_W,				KC_E,				KC_R,				KC_T,			KC_Y,	    KC_U,				KC_I,				KC_O,				KC_P,
	LGUI_T(KC_A),       LALT_T(KC_S),	    LSFT_T(KC_D),	    LCTL_T(KC_F),	    KC_G,			KC_H,	    RCTL_T(KC_J),	    RSFT_T(KC_K),	    LALT_T(KC_L),	    RGUI_T(KC_SCLN),
	KC_Z,				KC_X,				KC_C,				KC_V,				KC_B,			KC_N,	    KC_M,				KC_COMM,			KC_DOT,				LT(_MOUSE, KC_SLSH),
	LWIN(KC_TAB),		HEH_ESC,			LT(_SHORT, KC_ENT),	LT(_NUM, KC_TAB),	KC_MUTE,		KC_CAPS,    LT(_SYM, KC_BSPC),	LT(_NAV, KC_SPACE),	MT(MOD_MEH, KC_DEL),LALT(KC_SPACE)
),

/* NAV
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |      |      |      |                      |  INS | Home | PgUp | PgDn |  End |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |  GUI |  Alt | SHFT | CTRL |      |                      | Left | Down |  Up  | Right|      |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      |      |      |      |  |     |    |     |  |   *  |   #  |   ^  |   $  |   ~  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |     |   |     |       |      |            |     |   ^   |      |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_NAV] =  LAYOUT(
	KC_NO,		KC_NO,			KC_NO,			KC_NO,		KC_NO,		KC_INS,		KC_HOME,	KC_PGUP,	KC_PGDN,		KC_END,
	KC_LGUI,	KC_LALT,		KC_LSFT,		KC_LCTL,	KC_NO,		KC_LEFT,	KC_DOWN,	KC_UP,		KC_RIGHT,		KC_NO,
	KC_NO,		KC_NO,			KC_NO,			KC_NO,		KC_NO,		KC_ASTR,	KC_HASH,	KC_CIRC,	KC_DLR,			KC_TILD,
	KC_NO,		KC_NO,			KC_NO,		    KC_NO,		KC_NO,		KC_NO,		KC_NO,		KC_TRNS,	KC_NO,	        KC_NO
),

/* SYM
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   !  |   #  |   [  |   ]  |   '  |                      |   `  |   \  |   *  |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   @  |   $  |   (  |   )  |   &  |                      |   ~  |   =  |   +  |   -  |   _  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   ^  |   %  |   {  |   }  |   |  |  |     |    |     |  |      |   "  |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |     |   |     |       |      |            |  ^  |       |      |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 * Homerow Mods enabled
 */
[_SYM] = LAYOUT(
	KC_EXLM,	KC_HASH,		KC_LBRC,		KC_RBRC,	KC_QUOT,		KC_GRV,		KC_BSLS,	KC_ASTR,	KC_NO,			KC_NO,
	KC_AT,  	KC_DLR, 		KC_LPRN,		KC_RPRN,	KC_AMPR,		KC_TILD,	KC_EQL,	    KC_PLUS,	KC_MINS,		KC_UNDS,
	KC_CIRC,	KC_PERC,		KC_LCBR,		KC_RCBR,	KC_PIPE,		KC_NO,		KC_DQT,		KC_NO,		KC_NO,			KC_NO,
	KC_NO,		KC_NO,			KC_NO,		    KC_NO,		KC_NO,		    KC_TRNS,	KC_NO,		KC_NO,	    KC_NO,	        KC_NO
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
 *          |     |   |O_HEH|       |   ^  |            | BKSP| Space |  MEH |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 * Homerow Mods enabled
 */
[_NUM] = LAYOUT(
	KC_F1,		KC_F2,			KC_F3,			KC_F4,		KC_F5,		KC_F6,		KC_F7,			KC_F8,			KC_F9,		KC_F10,
	KC_1,		KC_2,			KC_3,			KC_4,		KC_5,		KC_6,		KC_7,			KC_8,			KC_9,		KC_0,
	KC_F11,		KC_F12,			KC_F13,			KC_F15,		KC_NO,		KC_NO,		KC_F17,			KC_NO,			KC_NO,		KC_NO,
	KC_NO,		OSM(MOD_HEH),	KC_NO,			KC_TRNS,	KC_NO,		KC_BSPC,	KC_SPC,	        KC_MEH,	        KC_NO,	    KC_NO
),

/* Shortcuts
 *
 * ,----------------------------------.                      ,----------------------------------.
 * | Clear|      |Expand|      | Help |                      | Save | S+INS| Info |Detail|Search|
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |      | Scrn |  DEL | BKSP |      |                      | Prev | Play | Next |      |      |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      | ShrX | CAPW | Menu |      |  |     |    |     |  | Lock |      |      |      |      |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |     |   |     |   ^   |      |            |     |       |      |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
*/
[_SHORT] = LAYOUT(
	KC_F1,	KC_NO,		        KC_F13,			KC_NO,	    KC_F15,		KC_F17,	        LSFT_T(KC_INS),		M_INFO,		M_DETL,	    M_SRCH,
	KC_NO,	LSG_T(KC_S),	    KC_DEL,			KC_BSPC,	KC_NO,		KC_MPRV,	    KC_MPLY,	        KC_MNXT,	KC_NO,	    KC_NO,
	KC_NO,	LCTL_T(KC_PSCR),	CW_TOGG,		KC_MENU,    KC_NO,		LGUI_T(KC_L),   KC_NO,		        KC_NO,		KC_NO,	    KC_NO,
	KC_NO,	KC_NO,		        KC_TRNS,		KC_NO,	    KC_NO,	    KC_NO,	        KC_NO,		        KC_NO,		KC_NO,	    KC_NO
),

/* Mouse Layer
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |      |      |  MUp |      |      |                      |      |      |      |      |      |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |      | MLeft| MDown|MRight|      |                      |      | CTRL | SHFT | GUI  |      |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |      |      | LClk | RClk |      |  |     |    |     |  |      |      |      |      |   ^  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          | MClk|   |     | LClick| RClk |            |     |       |      |   |     |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 * L Roller: Control Mouse Wheel, L Encoder: Mouse Wheel
 */
[_MOUSE] = LAYOUT(
	KC_NO,  	KC_MS_WH_UP,	KC_MS_UP,		KC_MS_WH_DOWN,  KC_NO,		KC_NO,	    KC_NO,		KC_NO,		KC_NO,	    KC_NO,
	KC_NO,  	KC_MS_LEFT,		KC_MS_DOWN,     KC_MS_RIGHT,	KC_NO,		KC_NO,	    KC_LCTL,	KC_LSFT,	KC_LGUI,    KC_NO,
	KC_NO,  	KC_NO,		    KC_MS_BTN1,		KC_MS_BTN2,	    KC_NO,		KC_NO,	    KC_NO,		KC_NO,		KC_NO,	    KC_TRNS,
	KC_MS_BTN3, KC_NO,		    KC_MS_BTN1,	    KC_MS_BTN2,	    KC_NO,	    KC_NO,	    KC_NO,		KC_NO,		KC_NO,	    KC_NO
),
};
// clang-format on

#if defined(ENCODER_MAP_ENABLE)

// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = {   ENCODER_CCW_CW(LCTL(LWIN(KC_LEFT)), LCTL(LWIN(KC_RIGHT))),
                    ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
                    ENCODER_CCW_CW(KC_LEFT, KC_RIGHT),
                    ENCODER_CCW_CW(LCTL(KC_TAB), RCS(KC_TAB)) },
    [_NAV] = {},
    [_SYM] = {},
    [_NUM] = {},
    [_SHORT] = {},
    [_MOUSE] = {    ENCODER_CCW_CW(LSFT(KC_MS_WH_DOWN), LSFT(KC_MS_WH_UP)),
                    ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)}
};
// clang-format on

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_INFO:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_F7));
            }
            break;
        case M_DETL:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_F8));
            }
            break;
        case M_SRCH:
            if (record->event.pressed) {
                SEND_STRING(SS_TAP(X_HOME) SS_TAP(X_F9));
            }
            break;
    }
    return true;
}

#ifdef OLED_ENABLE
// TODO: Add Caps Lock Indicator
// TODO: Add MEH and HEH Indicators
bool oled_task_user(void) {
    // TODO: Do something cool with the left half.
    if (!is_keyboard_master()) {
        return true;
    }

    oled_clear();
    // Host Keyboard Layer Status
    oled_write_P(PSTR("LAYER:\n"), false);
    oled_write_P(PSTR("\n"), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("ALPHA\n\n\n\n"), false);
            break;
        case _MOUSE:
            oled_write_P(PSTR("MOUSE\n\n\n\n"), false);
            break;
        case _SHORT:
            oled_write_P(PSTR("SHORTCUTS\n\n\n\n"), false);
            break;
        case _NUM:
            oled_write_P(PSTR("Numbers\n\n\n\n"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Symbols\n\n\n\n"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Navigation\n\n\n\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    if (is_caps_word_on()) { // FIXME Caps Word indicator stays on after caps word turns off.
        oled_write_P(PSTR("CAPS WORD IS ON!\n\n"), false);
    }
    return false;
};

#endif
