#ifndef CONSOLE_UTILS_H_INCLUDED
#define CONSOLE_UTILS_H_INCLUDED

#include <string>

#define WHITE 0
#define RED 31
#define GREEN 32
#define YELLOW 33
#define BLUE 34

void gotoxy(int row, int col);

void setColor(int color);

void resetColor();

void print(std::string text, int row, int col, int color);

void clearScreen();

void delay(int seconds);

#endif // CONSOLE_UTILS_H_INCLUDED
