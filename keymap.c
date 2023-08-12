#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
uint8_t mod_state;
uint8_t oneshot_mod_state;
uint16_t last_keycode;


#define _COLEMAK 0
#define _QWERTY 1
#define _NUM 2
#define _NAV 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  NAV,
  NUM,
  ADJUST,
  //Remove OS Mods if they are stuck
  OS_CLR,
  KC_P000,
  KC_C000,
  O_BRACE,
  C_BRACE,
};

// Shortcut to make keymap more readable
#define KC_QWER TG(_QWERTY)

#define NUM_TAB LT(_NUM, KC_TAB)
#define NAV_ENT LT(_NAV, KC_ENT)

#define ADJUST MO(_ADJUST)

// Miscellaneous keyboard shortcuts in direct access
#define UNDO LCTL(KC_Z)
#define REDO LCTL(KC_Y)
#define C_A_DEL LCA(KC_DEL)

// One Shot Shifts
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)

// One Shot Others
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
#define OS_LGUI OSM(MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_5x6(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12  ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV  ,KC_Q    ,KC_W    ,KC_F    ,KC_P    ,KC_B    ,                                            KC_J    ,KC_L    ,KC_U    ,KC_Y    ,KC_SCLN ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS ,KC_A    ,KC_R    ,KC_S    ,KC_T    ,KC_G    ,                                            KC_M    ,KC_N    ,KC_E    ,KC_I    ,KC_O    ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     OS_LGUI ,KC_Z    ,KC_X    ,KC_C    ,KC_D    ,KC_V    ,                                            KC_K    ,KC_H    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_MINS ,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                                           └────────┴────────┼────────┼────────┼────────┴────────┘
                       DM_PLY1 ,DM_PLY2 ,                                                                                KC_HOME ,KC_END  ,
  //                  └────────┴────────┘                                                                               └────────┴────────┘
  //                                    ┌────────┬────────┐                                           ┌────────┬────────┐
                                         KC_SPC  ,OSL(_NUM),                                          OSL(_NAV),KC_BSPC ,
  //                                    ├────────┼────────┤                                           ├────────┼────────┤
                                         OS_LSFT ,KC_TAB  ,                                            KC_ENT  ,OS_RSFT ,
  //                                    ├────────┼────────┤                                           ├────────┼────────┤
                                         OS_LCTL ,OS_LALT ,                                            KC_ESC  ,KC_DEL
  //                                    └────────┴────────┘                                           └────────┴────────┘
  ),

  [_QWERTY] = LAYOUT_5x6(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T    ,                                            KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                                            KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                                            KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH ,_______ ,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                                           └────────┴────────┼────────┼────────┼────────┴────────┘
                       DM_REC1 ,DM_REC2 ,                                                                                _______ ,_______ ,
  //                  └────────┴────────┘                                                                               └────────┴────────┘
  //                                    ┌────────┬────────┐                                           ┌────────┬────────┐
                                         _______ ,_______ ,                                            _______ ,_______ ,
  //                                    ├────────┼────────┤                                           ├────────┼────────┤
                                         _______ ,_______ ,                                            _______ ,_______ ,
  //                                    ├────────┼────────┤                                           ├────────┼────────┤
                                         _______ ,_______ ,                                            _______ ,_______
  //                                    └────────┴────────┘                                           └────────┴────────┘
  ),

  [_NUM] = LAYOUT_5x6(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     ADJUST  ,KC_NUM  ,KC_PSCR ,KC_SCRL ,KC_PAUS ,KC_BRIU ,                                            KC_P000 ,KC_CIRC ,KC_AMPR ,KC_HASH ,KC_EXLM ,KC_QWER ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE ,O_BRACE ,C_BRACE ,KC_LCBR ,KC_RCBR ,KC_BRID ,                                            KC_C000 ,KC_7    ,KC_8    ,KC_9    ,KC_PERC ,KC_DLR  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_VOLU ,KC_LBRC ,KC_RBRC ,KC_LPRN ,KC_RPRN ,KC_INS  ,                                            KC_COMM ,KC_4    ,KC_5    ,KC_6    ,KC_PAST ,KC_PPLS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_VOLD ,C(KC_A) ,C(KC_X) ,C(KC_C) ,C(KC_V) ,LCA(KC_V),                                           KC_EQL  ,KC_1    ,KC_2    ,KC_3    ,KC_PSLS ,KC_PMNS ,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                                           └────────┴────────┼────────┼────────┼────────┴────────┘
                       DM_REC1 ,DM_REC2 ,                                                                                KC_0    ,KC_DOT  ,
  //                  └────────┴────────┘                                                                               └────────┴────────┘
  //                                    ┌────────┬────────┐                                           ┌────────┬────────┐
                                         _______ ,_______ ,                                            _______ ,_______ ,
  //                                    ├────────┼────────┤                                           ├────────┼────────┤
                                       C(KC_BSPC),_______ ,                                            _______ ,KC_CALC,
  //                                    ├────────┼────────┤                                           ├────────┼────────┤
                                         _______ ,_______ ,                                            _______ ,_______
  //                                    └────────┴────────┘                                           └────────┴────────┘
  ),

  [_NAV] = LAYOUT_5x6(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     ADJUST  ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,KC_QWER ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_LBRC ,KC_RBRC ,KC_UP   ,KC_APP  ,C_A_DEL ,                                            O_BRACE ,KC_RPRN ,KC_LPRN ,KC_RBRC ,KC_LBRC ,KC_PSCR ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_PGUP ,_______ ,KC_LEFT ,KC_DOWN ,KC_RIGHT,_______ ,                                            C_BRACE ,KC_RCTL ,KC_RSFT ,KC_RALT ,KC_RGUI ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_PGDN ,C(KC_A) ,C(KC_X) ,C(KC_C) ,C(KC_V),LCA(KC_V),                                            KC_CIRC ,KC_AMPR ,KC_HASH ,KC_AT   ,KC_EXLM ,_______ ,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                                           └────────┴────────┼────────┼────────┼────────┴────────┘
                    RCS(KC_TAB),C(KC_TAB),                                                                               _______ ,_______ ,
  //                  └────────┴────────┘                                                                               └────────┴────────┘
  //                                    ┌────────┬────────┐                                           ┌────────┬────────┐
                                         _______ ,_______ ,                                            _______ ,_______ ,
  //                                    ├────────┼────────┤                                           ├────────┼────────┤
                                       C(KC_BSPC),_______ ,                                            _______ ,_______ ,
  //                                    ├────────┼────────┤                                           ├────────┼────────┤
                                         _______ ,_______ ,                                            _______ ,_______
  //                                    └────────┴────────┘                                           └────────┴────────┘
  ),

  [_ADJUST] = LAYOUT_5x6(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     QK_BOOT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                                           ├────────┼────────┼────────┼────────┼────────┼────────┤
     QK_BOOT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,QK_BOOT ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //└────────┴────────┼────────┼────────┼────────┴────────┘                                           └────────┴────────┼────────┼────────┼────────┴────────┘
                       XXXXXXX ,XXXXXXX ,                                                                                XXXXXXX ,XXXXXXX ,
  //                  └────────┴────────┘                                                                               └────────┴────────┘
  //                                    ┌────────┬────────┐                                           ┌────────┬────────┐
                                         _______ ,_______ ,                                            _______ ,_______ ,
  //                                    ├────────┼────────┤                                           ├────────┼────────┤
                                         _______ ,_______ ,                                            _______ ,_______ ,
  //                                    ├────────┼────────┤                                           ├────────┼────────┤
                                         _______ ,_______ ,                                            _______ ,_______
  //                                    └────────┴────────┘                                           └────────┴────────┘
  ),
};

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
         keycode,
         record->event.key.row,
         record->event.key.col,
         get_highest_layer(layer_state),
         record->event.pressed,
         get_mods(),
         get_oneshot_mods(),
         record->tap.count
         );
#endif

    mod_state = get_mods();
    oneshot_mod_state = get_oneshot_mods();
    switch (keycode) {

    case KC_SPC:
        if (oneshot_mod_state & MOD_MASK_SHIFT) {
            if (record->event.pressed) {
                tap_code(KC_MINS); // The one-shot shift will convert it to an underscore
            }
            return false;
        }
        return true;

     case OS_CLR:
         if (record->event.pressed) {
             clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
         }
         return false;

    case KC_P000:
      if (record->event.pressed) {
          send_string("000");
          return false;
      }
      break;

    case KC_C000:
      if (record->event.pressed) {
          send_string(",000");
          return false;
      }
      break;

    case O_BRACE:
      if (record->event.pressed) {
          tap_code16(KC_LCBR);
          tap_code(KC_ENTER);
          return false;
      }
      break;

    case C_BRACE:
      if (record->event.pressed) {
          tap_code16(KC_RCBR);
          tap_code(KC_ENTER);
          return false;
      }
      break;

    }
    return true;
};