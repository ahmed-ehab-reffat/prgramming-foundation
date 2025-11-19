#ifndef KEYBOARD_READ_H_INCLUDED
#define KEYBOARD_READ_H_INCLUDED

#define UP 'A'
#define DOWN 'B'
#define RIGHT 'C'
#define LEFT 'D'
#define HOME 'H'
#define END 'F'
#define ENTER '\n'
#define ESC '\033'

void enableRawMode();

void disableRawMode();

int kbhitBlock();

int kbhitNonblock();

int getKey();

#endif // KEYBOARD_READ_H_INCLUDED
