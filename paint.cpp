// paint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "funcs.hpp"
#include "vars.hpp"
#include "include.hpp"
using namespace std;
int main()
{

    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, 1200, 1200, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 10;                   // Width of each character in the font
    cfi.dwFontSize.Y = 10;                  // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
    string name = "ArtyK's 4bit Console Painter v1.0.2." + build;
    LPCSTR lname = name.c_str();
    SetConsoleTitleA(lname);
    int line = 5, column = 5,x;
    char cx;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
    //setCursorPosition(column, line);
    MoveWindow(console, r.left, r.top, 1200, 1200, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
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
    name = "ArtyK's 4bit Console Painter v1.0.2." + build + " | PRESS ANY KEY TO CONTINUE . . .";
    lname = name.c_str();
    SetConsoleTitleA(lname);
    _getch();
    system("cls");

    int maxl = 64, maxc = 64;

    cfi.dwFontSize.X = 6;                   // Width of each character in the font
    cfi.dwFontSize.Y = 6;
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);


    ScreenSize(SHRT_MAX, SHRT_MAX);


    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backgr);
    for (int i = 0; i < maxl; i++) {
        for (int a = 0; i < maxc; i++) {
            cout << " ";
        }
        cout << "\n";
    }
    line = column = 5;
    short attrib = 15;
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
    name = "ArtyK's 4bit Console Painter v1.0.2." + build + " | Mode: " + mode + " | X: " + to_string(column) + ", Y: " + to_string(line) + " | Color attribute: " + to_string(attrib);
    lname = name.c_str();
    SetConsoleTitleA(lname);


    for (;;) {
        cfi.dwFontSize.X = fontsize;                   // Width of each character in the font
        cfi.dwFontSize.Y = fontsize;
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

        if (_kbhit()) {
            switch (_getch())
            {
            case 's':

                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastpos[2]);
                setCursorPosition(lastpos[0], lastpos[1]);
                cout << " ";
                line++;
                attrib = color[colornum];
                if (mode == "Erase") {
                    attrib = backgr;
                }
                break;

            case 'd':
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastpos[2]);
                setCursorPosition(lastpos[0], lastpos[1]);
                cout << " ";
                column++;
                attrib = color[colornum];
                if (mode == "Erase") {
                    attrib = backgr;
                }
                break;

            case 'w':
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastpos[2]);
                setCursorPosition(lastpos[0], lastpos[1]);
                cout << " ";
                line--;
                attrib = color[colornum];
                if (mode == "Erase") {
                    attrib = backgr;
                }
                break;

            case 'a':
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastpos[2]);
                setCursorPosition(lastpos[0], lastpos[1]);
                cout << " ";
                column--;
                attrib = color[colornum];
                if (mode == "Erase") {
                    attrib = backgr;
                }
                break;

            case '1':
                if (mode == "Paint") {
                    colornum = 0 + (pallete * 8);
                    attrib = color[colornum];
                }
                break;

            case '2':
                if (mode == "Paint") {
                    colornum = 1 + (pallete * 8);
                    attrib = color[colornum];
                }
                break;

            case '3':
                if (mode == "Paint") {
                    colornum = 2 + (pallete * 8);
                    attrib = color[colornum];
                }
                break;

            case '4':
                if (mode == "Paint") {
                    colornum = 3 + (pallete * 8);
                    attrib = color[colornum];
                }
                break;

            case '5':
                if (mode == "Paint") {
                    colornum = 4 + (pallete * 8);
                    attrib = color[colornum];
                }
                break;

            case '6':
                if (mode == "Paint") {
                    colornum = 5 + (pallete * 8);
                    attrib = color[colornum];
                }
                break;

            case '7':
                if (mode == "Paint") {
                    colornum = 6 + (pallete * 8);
                    attrib = color[colornum];
                }
                break;

            case '8':
                if (mode == "Paint") {
                    colornum = 7 + (pallete * 8);
                    attrib = color[colornum];
                }
                break;

            case '9':
                if (mode == "Paint") {
                    if (pallete == 1) {
                        pallete = 0;
                    }
                    else
                    {
                        pallete = 1;
                    }
                    colornum = 7 + (pallete * 8);
                    attrib = color[colornum];
                }
                break;



            case '+':
                fontsize++;
                cfi.dwFontSize.X = fontsize;                   // Width of each character in the font
                cfi.dwFontSize.Y = fontsize;
                SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
                MoveWindow(console, r.left, r.top, 1200, 1200, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
                break;

            case '=':
                fontsize++;
                cfi.dwFontSize.X = fontsize;                   // Width of each character in the font
                cfi.dwFontSize.Y = fontsize;
                SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
                MoveWindow(console, r.left, r.top, 1200, 1200, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
                break;

            case '-':
                fontsize--;
                if (fontsize < 2) {
                    fontsize = 2;
                }
                cfi.dwFontSize.X = fontsize;                   // Width of each character in the font
                cfi.dwFontSize.Y = fontsize;
                SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
                MoveWindow(console, r.left, r.top, 1200, 1200, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
                break;

            case '_':
                fontsize--;
                if (fontsize < 2) {
                    fontsize = 2;
                }
                cfi.dwFontSize.X = fontsize;                   // Width of each character in the font
                cfi.dwFontSize.Y = fontsize;
                SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
                MoveWindow(console, r.left, r.top, 1200, 1200, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
                break;

            case 'r':
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), lastpos[2]);
                setCursorPosition(lastpos[0], lastpos[1]);
                cout << " ";
                line = 5;
                column = 5;
                colornum = 0;
                pallete = 0;
                break;

            case 'h':
                system("cls");
                cfi.dwFontSize.X = 0;                   // Width of each character in the font
                cfi.dwFontSize.Y = 14;
                SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
                MoveWindow(console, r.left, r.top, 1200, 1200, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
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
                MoveWindow(console, r.left, r.top, 1200, 1200, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
                break;

            case 'b':

                if (backgr == 143) {
                    backgr = 15;
                }
                else
                {
                    backgr = 143;
                }

                break;


            case 10:
                system("cls");
                for (int i = 0; i < maxl; i++) {
                    for (int a = 0; i < maxc; i++) {
                        cout << " ";
                    }
                    cout << "\n";
                }
                attrib = backgr;
                break;

            case '0':

                if (mode == "Paint") {
                    mode = "Erase";
                    attribm = attrib;
                    attrib = backgr;
                }
                else {
                    mode = "Paint";
                    attrib = attribm;
                }

                break;

            case 13:
                system("cls");
                for (int i = 0; i < maxl; i++) {
                    for (int a = 0; i < maxc; i++) {
                        cout << " ";
                    }
                    cout << "\n";
                }
                attrib = backgr;
                break;

            case 27:
                system("cls");
                cfi.dwFontSize.X = 0;                   // Width of each character in the font
                cfi.dwFontSize.Y = 14;
                SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
                MoveWindow(console, r.left, r.top, 1200, 1200, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
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
                break;


            default:
                break;
            }
        }



         
        
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
        name = "ArtyK's 4bit Console Painter v1.0.2." + build + " | Mode: " + mode + " | X: " + to_string(column) + ", Y: " + to_string(line) + " | Color attribute: " + to_string(attrib) + " | Background: " + to_string(backgr);
        lname = name.c_str();
        SetConsoleTitleA(lname);
    }



    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
