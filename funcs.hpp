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

void gettextstring() {

}


#endif // !FUNCS_H
