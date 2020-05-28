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
void exitpaint(void);
void clearscr(void);
void erase(void);
void chngback(void);
void help(void);
void chngcolor(short col);
void cngfont(int type);
void resetpos(void);







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
    MoveWindow(console, 1, 1, 1200, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
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

    name = "ArtyK's 4bit Console Painter v1.0.3." + build + " | PRESS ANY KEY TO CONTINUE . . .";
    lname = name.c_str();
    SetConsoleTitleA(lname);
    _getch();
    system("cls");

    

    cfi.dwFontSize.X = 8;                   // Width of each character in the font
    cfi.dwFontSize.Y = 8;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    MoveWindow(console, 1, 1, 1200, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);

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
    name = "ArtyK's 4bit Console Painter v1.0.3." + build + " | Mode: " + mode + " | X: " + to_string(column) + ", Y: " + to_string(line) + " | Color attribute: " + to_string(attrib) + " | Background: " + to_string(backgr) + " | Fontsize: " + to_string(fontsize);
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
    int odd = fontsize % 2;
    int pos = fontsize % 6;
    double pos2 = fontsize / 6;
    if (fontsize > 6 && fontsize < 19 && pos == 0) {
        pos = 6 - ((pos2 - 1) * 2);
    }
    else {
        if (fontsize > 6 && fontsize > 19 && pos == 0) {
            pos = 1;
        }
    }
    if (odd == 0 && pos != 0) {
        pos = fontsize / 2;
    }
    short maxcol = round(1200 / fontsize) - 2 - pos;
    if (column > maxcol) {
        column = maxcol;
    }


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attrib);
    setCursorPosition(column, line);
    cout << "B";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backgr);
    lastpos[0] = column;
    lastpos[1] = line;
    lastpos[2] = attrib;
    name = "ArtyK's 4bit Console Painter v1.0.3." + build + " | Mode: " + mode + " | X: " + to_string(column) + ", Y: " + to_string(line) + " | Color attribute: " + to_string(attrib) + " | Background: " + to_string(backgr) + " | Fontsize: " + to_string(fontsize) + " | Maxcol: " + to_string(maxcol);
    lname = name.c_str();
    SetConsoleTitleA(lname);

}

void exitpaint(void) {

    system("cls");
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 14;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    MoveWindow(console, 1, 1, 1200, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << "Exiting";
    Sleep(100);
    cout << ".";
    Sleep(100);
    cout << " ";
    Sleep(100);
    cout << ".";
    Sleep(100);
    cout << " ";
    Sleep(100);
    cout << ".";
    Sleep(100);
    cout << " ";
    exit(0);

}

void clearscr(void) {
    system("cls");
    for (int i = 0; i < maxl; i++) {
        for (int a = 0; i < maxc; i++) {
            cout << " ";
        }
        cout << "\n";
    }
    attrib = backgr;
}

void erase(void) {
    if (mode == "Paint") {
        mode = "Erase";
        attribm = attrib;
        attrib = backgr;
    }
    else {
        mode = "Paint";
        attrib = attribm;
    }
}

void chngback(void) {
    if (backgr == 143) {
        backgr = 15;
    }
    else
    {
        backgr = 143;
    }

}

void help(void) {
    system("cls");
    cfi.dwFontSize.X = 0;                   // Width of each character in the font
    cfi.dwFontSize.Y = 14;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    MoveWindow(console, 1, 1, 1200, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << "Help menu:\nW/A/S/D -- controls of a brush\n'1' to '8' -- color pallete\n'9' -- change color pallete\nR - reset cursor position\nEnter -- clean screen\nEscape -- exit the ArtyK's Console Painter\n+/- -- zoom in, zoom out\n'b' -- change the background color to gray/black. refresh the screen after you press it, to make visual changes\n\nPress any key to continue. . .";
    _getch();
    system("cls");
    for (int i = 0; i < maxl; i++) {
        for (int a = 0; i < maxc; i++) {
            cout << " ";
        }
        cout << "\n";
    }
    attrib = backgr;
    cfi.dwFontSize.X = fontsize;                   // Width of each character in the font
    cfi.dwFontSize.Y = fontsize;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    MoveWindow(console, 1, 1, 1200, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
}


void chngcolor(short col) {

    if (col < 9) {
        if (mode == "Paint") {
            colornum = col + (pallete * 8);
            attrib = color[colornum];
            lastcol = col;
        }
    }
    else
    {
        if (mode == "Paint") {
            if (pallete == 1) {
                pallete = 0;
            }
            else
            {
                pallete = 1;
            }
            colornum = lastcol + (pallete * 8);
            attrib = color[colornum];
        }
    }
    

}

void cngfont(int type) {


    //0 -- increase, 1 -- decrease
    switch (type)
    {

    case 0:
        fontsize++;
        if (fontsize > 47) {
            fontsize = 47;
        }
        break;

    case 1:
        fontsize--;
        if (fontsize < 2) {
            fontsize = 2;
        }
        break;

    default:
        break;
    }
    cfi.dwFontSize.X = fontsize;                   // Width of each character in the font
    cfi.dwFontSize.Y = fontsize;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    MoveWindow(console, 1, 1, 1200, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);


}

void resetpos(void) {

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastpos[2]);
    setCursorPosition(lastpos[0], lastpos[1]);
    cout << " ";
    line = 1;
    column = 1;
    colornum = 0;
    pallete = 0;
}
















#endif // !FUNCS_H
