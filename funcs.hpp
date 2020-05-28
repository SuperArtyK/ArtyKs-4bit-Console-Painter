#pragma once
#ifndef FUNCS_H
#include "vars.hpp"
#include "include.hpp"
using namespace std;



void ScreenSize(int x, int y);
void setCursorPosition(int x, int y);


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

void startup(void) {

    name = "ArtyK's 4bit Console Painter v1.0.2." + build + " | PRESS ANY KEY TO CONTINUE . . .";
    lname = name.c_str();
    SetConsoleTitleA(lname);
    _getch();
    system("cls");

    

    cfi.dwFontSize.X = 8;                   // Width of each character in the font
    cfi.dwFontSize.Y = 8;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    MoveWindow(console, r.left, r.top, 1000, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);




    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backgr);
}






























#endif // !FUNCS_H
