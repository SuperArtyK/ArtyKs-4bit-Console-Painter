#pragma once
#ifndef FUNCS_H
#include "vars.hpp"
#include "include.hpp"
using namespace std;



void ScreenSize(int x, int y);
void setCursorPosition(int x, int y);
void startup(void);
void paintstart(void);
void logodraw(void);
void draw(short type);
void postproc(void);



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
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 1000, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 10;                   // Width of each character in the font
    cfi.dwFontSize.Y = 10;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

    SetConsoleTitleA(lname);

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}





void paintstart(void) {

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

    for (int i = 0; i < maxl; i++) {
        for (int a = 0; i < maxc; i++) {
            cout << " ";
        }
        cout << "\n";
    }
    line = column = 5;
    
    lastpos[0] = column;
    lastpos[1] = line;
    lastpos[2] = attrib;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attrib);
    setCursorPosition(column, line);
    cout << "B";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backgr);
    lastpos[0] = column;
    lastpos[1] = line;
    lastpos[2] = attrib;
    name = "ArtyK's 4bit Console Painter v1.0.2." + build + " | Mode: " + mode + " | X: " + to_string(column) + ", Y: " + to_string(line) + " | Color attribute: " + to_string(attrib) + " | Background: " + to_string(backgr) + " | Fontsize: " + to_string(fontsize);
    lname = name.c_str();
    SetConsoleTitleA(lname);


}



void logodraw(void) {
    for (int i = 0; i < sizeof(picture); i++) {
        switch (picture[i])
        {
        case ' ':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cout << " ";
            break;

        case '1':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[1]);
            cout << " ";
            break;

        case '2':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[2]);
            cout << " ";
            break;

        case '3':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[3]);
            cout << " ";
            break;

        case '4':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[4]);
            cout << " ";
            break;

        case '5':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[5]);
            cout << " ";
            break;

        case '6':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[6]);
            cout << " ";
            break;

        case '7':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[7]);
            cout << " ";
            break;

        case '8':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[8]);
            cout << " ";
            break;

        case '9':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[9]);
            cout << " ";
            break;

        case 'a':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[10]);
            cout << " ";
            break;

        case 'b':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[11]);
            cout << " ";
            break;

        case 'c':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[12]);
            cout << " ";
            break;

        case 'd':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[13]);
            cout << " ";
            break;

        case 'e':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[14]);
            cout << " ";
            break;

        case 'f':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color[15]);
            cout << " ";
            break;





        case '!':
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
            line++;
            setCursorPosition(column, line);
            break;



        default:
            break;
        }
    }


}



void draw(short type) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastpos[2]);
    setCursorPosition(lastpos[0], lastpos[1]);
    cout << " ";
    //type: 0 -- y+1, 1 -- x+1; 2 -- y-1; 3 -- x-1;
    switch (type)
    {

    case 0:
        line++;
        break;

    case 1:
        column++;
        break;

    case 2:
        line--;
        break;

    case 3:
        column--;
        break;




    default:
        break;
    }
    attrib = color[colornum];
    if (mode == "Erase") {
        attrib = backgr;
    }

}

void postproc(void) {
    if (line < 1) {
        line = 1;
    }
    if (column < 1) {
        column = 1;
    }




    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attrib);
    setCursorPosition(column, line);
    cout << "B";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backgr);
    lastpos[0] = column;
    lastpos[1] = line;
    lastpos[2] = attrib;
    name = "ArtyK's 4bit Console Painter v1.0.2." + build + " | Mode: " + mode + " | X: " + to_string(column) + ", Y: " + to_string(line) + " | Color attribute: " + to_string(attrib) + " | Background: " + to_string(backgr) + " | Fontsize: " + to_string(fontsize);
    lname = name.c_str();
    SetConsoleTitleA(lname);
}




















#endif // !FUNCS_H
