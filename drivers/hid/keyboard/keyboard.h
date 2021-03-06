#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <stdbool.h>

#define MAX_CALLBACK_COUNT 256

// TODO: Switch to #define instead of enum, so that we can define
// bits individually and restrict to required length (8 bits)
// currently it's int always
enum keyboard_key {
    KEY_1 = 0, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0,
    
    KEY_Q, KEY_W, KEY_E, KEY_R, KEY_T,
    KEY_Y, KEY_U, KEY_I, KEY_O, KEY_P, KEY_A, KEY_S, KEY_D,
    KEY_F, KEY_G, KEY_H, KEY_J, KEY_K, KEY_L, KEY_Z, KEY_X,
    KEY_C, KEY_V, KEY_B, KEY_N, KEY_M,

    KEY_F1, KEY_F2, KEY_F3,
    KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11,
    KEY_F12,

    KEY_COMMA, KEY_DOT, KEY_SLASH,
    KEY_BACKSLASH, KEY_APOSTROPHE, KEY_SEMICOLON, KEY_MINUS, KEY_EQUALS,
    KEY_BACKSPACE, KEY_SPACE, KEY_ENTER, KEY_TAB, KEY_ESC,
    
    KEY_LSHIFT, KEY_RSHIFT, KEY_ALT, KEY_ALTGR, KEY_LCTRL,
    KEY_RCTRL, KEY_BACKTICK, KEY_RSQ_BRACKET, KEY_LSQ_BRACKET,
    KEY_CAPSLOCK, KEY_NUMLOCK, KEY_SCROLLLOCK,
    
    KEY_0_KP, KEY_1_KP, KEY_2_KP, KEY_3_KP, KEY_4_KP, KEY_5_KP, KEY_6_KP,
    KEY_7_KP, KEY_8_KP, KEY_9_KP,
    KEY_MINUS_KP, KEY_TIMES_KP, KEY_PLUS_KP, KEY_DOT_KP,

    KEY_UNUSED
};

struct keyboard_event {
    enum keyboard_key key;
    bool released; // true if released event
    char ascii;
    bool printable;
    // TODO: Add more useful fields
    // some people have ctrl_pressed, shift_pressed, and stuff here
};

void keyboard_init();
void keyboard_irq_handler();

void keyboard_add_callback(void (*callback)(struct keyboard_event));

// TODO: This should only be callable for functions in keyboard folder
void keyboard_fire_event(enum keyboard_key kbdkey, bool released);

#endif
