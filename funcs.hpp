#pragma once
#ifndef FUNCS_H
#include "vars.hpp"
#include "include.hpp"
using namespace std;
void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

void ScreenSize(int x, int y) {

    COORD coord;
    coord.X = x;
    coord.Y = y;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = x - 1;
    Rect.Right = y - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);

}


#endif // !FUNCS_H
