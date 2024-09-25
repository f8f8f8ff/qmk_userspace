#include "leader.h"
#include "quantum.h"

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_W, KC_Q)) {
        SEND_STRING(SS_LALT(SS_TAP(X_F4)));
    }
    // SHAREX
    // capture screen
    else if (leader_sequence_two_keys(KC_S, KC_S) ) {
        SEND_STRING(SS_TAP(X_PSCR));
    }
    // capture region
    else if (leader_sequence_two_keys(KC_S, KC_R) ) {
        SEND_STRING(SS_LCTL(SS_TAP(X_PSCR)));
    }
    // capture active window
    else if (leader_sequence_two_keys(KC_S, KC_W) ) {
        SEND_STRING(SS_LALT(SS_TAP(X_PSCR)));
    }
    // start / stop screen recording
    else if (leader_sequence_two_keys(KC_S, KC_V) ) {
        SEND_STRING(SS_LSFT(SS_TAP(X_PSCR)));
    }
    // start / stop gif recording
    else if (leader_sequence_two_keys(KC_S, KC_G) ) {
        SEND_STRING(SS_LCTL(SS_LSFT(SS_TAP(X_PSCR))));
    }
    // ctrl alt delete
    else if (leader_sequence_three_keys(KC_C, KC_A, KC_D) ) {
        SEND_STRING(SS_LCTL(SS_LALT(SS_TAP(X_DEL))));
    }
    // powertoys color picker
    else if (leader_sequence_two_keys(KC_C, KC_P) ) {
        SEND_STRING(SS_LGUI(SS_LSFT("c")));
    }
    // calculator
    else if (leader_sequence_one_key(KC_C) ) {
        SEND_STRING(SS_TAP(X_CALC));
    }
    // pause / volume mixer
    else if (leader_sequence_one_key(KC_V) ) {
        SEND_STRING(SS_TAP(X_PAUSE));
    }
    // open music player
    else if (leader_sequence_one_key(KC_M) ) {
        SEND_STRING(SS_TAP(X_MSEL));
    }
    // audio mute
    else if (leader_sequence_two_keys(KC_M, KC_U) ) {
        SEND_STRING(SS_TAP(X_MUTE));
    }
    // system sleep
    else if (leader_sequence_two_keys(KC_C, KC_S) ) {
        SEND_STRING(SS_TAP(X_SYSTEM_SLEEP));
    }
    // escape (for emergencies....)
    else if (leader_sequence_three_keys(KC_E, KC_S, KC_C) ) {
        SEND_STRING(SS_TAP(X_ESC));
    }
    // capslock
    else if (leader_sequence_two_keys(KC_C, KC_L) ) {
        SEND_STRING(SS_TAP(X_CAPS));
    }
}
