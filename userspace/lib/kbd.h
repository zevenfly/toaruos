#pragma once

#define KBD_NORMAL 0
#define KBD_ESC_A  1
#define KBD_ESC_B  2
#define KBD_FUNC   3
#define KBD_ESC_O  4
#define KBD_ESC_EXT 5

#define KEY_NONE        0
#define KEY_BACKSPACE   8
#define KEY_CTRL_A      1
#define KEY_CTRL_B      2
#define KEY_CTRL_C      3
#define KEY_CTRL_D      4
#define KEY_CTRL_E      5
#define KEY_CTRL_F      6
#define KEY_CTRL_G      7
#define KEY_CTRL_H      8
#define KEY_CTRL_I      9
#define KEY_CTRL_J      10
#define KEY_CTRL_K      11
#define KEY_CTRL_L      12
#define KEY_CTRL_M      13
#define KEY_CTRL_N      14
#define KEY_CTRL_O      15
#define KEY_CTRL_P      16
#define KEY_CTRL_Q      17
#define KEY_CTRL_R      18
#define KEY_CTRL_S      19
#define KEY_CTRL_T      20
#define KEY_CTRL_U      21
#define KEY_CTRL_V      22
#define KEY_CTRL_W      23
#define KEY_CTRL_X      24
#define KEY_CTRL_Y      25
#define KEY_CTRL_Z      26
#define KEY_ESCAPE      27
#define KEY_NORMAL_MAX  256
#define KEY_ARROW_UP    257
#define KEY_ARROW_DOWN  258
#define KEY_ARROW_RIGHT 259
#define KEY_ARROW_LEFT  260
#define KEY_BAD_STATE   -1

#define KEY_CTRL_ARROW_UP    261
#define KEY_CTRL_ARROW_DOWN  262
#define KEY_CTRL_ARROW_RIGHT 263
#define KEY_CTRL_ARROW_LEFT  264

#define KEY_SHIFT_ARROW_UP    265
#define KEY_SHIFT_ARROW_DOWN  266
#define KEY_SHIFT_ARROW_RIGHT 267
#define KEY_SHIFT_ARROW_LEFT  268

#define KEY_LEFT_CTRL   1001
#define KEY_LEFT_SHIFT  1002
#define KEY_LEFT_ALT    1003
#define KEY_LEFT_SUPER  1004

#define KEY_RIGHT_CTRL  1011
#define KEY_RIGHT_SHIFT 1012
#define KEY_RIGHT_ALT   1013
#define KEY_RIGHT_SUPER 1014

#define KEY_F1          2001
#define KEY_F2          2002
#define KEY_F3          2003
#define KEY_F4          2004
#define KEY_F5          2005
#define KEY_F6          2006
#define KEY_F7          2007
#define KEY_F8          2008
#define KEY_F9          2009
#define KEY_F10         2010
#define KEY_F11         2011
#define KEY_F12         2012

#define KEY_PAGE_DOWN   2013
#define KEY_PAGE_UP     2014

#define KEY_HOME        2015
#define KEY_END         2016
#define KEY_DEL         2017
#define KEY_INSERT      2018

#define KEY_SCANCODE_F1  0x3b
#define KEY_SCANCODE_F2  0x3c
#define KEY_SCANCODE_F3  0x3d
#define KEY_SCANCODE_F4  0x3e
#define KEY_SCANCODE_F5  0x3f
#define KEY_SCANCODE_F6  0x40
#define KEY_SCANCODE_F7  0x41
#define KEY_SCANCODE_F8  0x42
#define KEY_SCANCODE_F9  0x43
#define KEY_SCANCODE_F10 0x44
#define KEY_SCANCODE_F11 0x57
#define KEY_SCANCODE_F12 0x58

#define KEY_MOD_LEFT_CTRL   0x01
#define KEY_MOD_LEFT_SHIFT  0x02
#define KEY_MOD_LEFT_ALT    0x04
#define KEY_MOD_LEFT_SUPER  0x08

#define KEY_MOD_RIGHT_CTRL  0x10
#define KEY_MOD_RIGHT_SHIFT 0x20
#define KEY_MOD_RIGHT_ALT   0x40
#define KEY_MOD_RIGHT_SUPER 0x80

#define KEY_ACTION_DOWN     0x01
#define KEY_ACTION_UP       0x02

typedef unsigned int  kbd_key_t;
typedef unsigned int  kbd_mod_t;
typedef unsigned char kbd_act_t;

typedef struct {
	kbd_key_t keycode;
	kbd_mod_t modifiers;
	kbd_act_t action;

	unsigned char key; /* Key as a raw code, ready for reading, or \0 if it's not a good down strike / was a modifier change / etc/. */
} key_event_t;

typedef struct {
	int kbd_state;
	int kbd_s_state;

	int k_ctrl;
	int k_shift;
	int k_alt;
	int k_super;

	int kl_ctrl;
	int kl_shift;
	int kl_alt;
	int kl_super;

	int kr_ctrl;
	int kr_shift;
	int kr_alt;
	int kr_super;

	int kbd_esc_buf;
} key_event_state_t;

kbd_key_t kbd_key(key_event_state_t * state, unsigned char c);
int kbd_scancode(key_event_state_t * state, unsigned char c, key_event_t * event);

