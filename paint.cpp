// paint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "funcs.hpp"
#include "vars.hpp"
#include "include.hpp"
using namespace std;
int main()
{

    
    
    //setCursorPosition(column, line);
    
    paintstart();


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
                MoveWindow(console, r.left, r.top, 1000, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
                break;

            case '=':
                fontsize++;
                cfi.dwFontSize.X = fontsize;                   // Width of each character in the font
                cfi.dwFontSize.Y = fontsize;
                SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
                MoveWindow(console, r.left, r.top, 1000, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
                break;

            case '-':
                fontsize--;
                if (fontsize < 2) {
                    fontsize = 2;
                }
                cfi.dwFontSize.X = fontsize;                   // Width of each character in the font
                cfi.dwFontSize.Y = fontsize;
                SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
                MoveWindow(console, r.left, r.top, 1000, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
                break;

            case '_':
                fontsize--;
                if (fontsize < 2) {
                    fontsize = 2;
                }
                cfi.dwFontSize.X = fontsize;                   // Width of each character in the font
                cfi.dwFontSize.Y = fontsize;
                SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
                MoveWindow(console, r.left, r.top, 1000, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
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
                MoveWindow(console, r.left, r.top, 1000, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
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
                MoveWindow(console, r.left, r.top, 1000, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
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
                MoveWindow(console, r.left, r.top, 1000, 1000, TRUE); ScreenSize(SHRT_MAX, SHRT_MAX);
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
        name = "ArtyK's 4bit Console Painter v1.0.2." + build + " | Mode: " + mode + " | X: " + to_string(column) + ", Y: " + to_string(line) + " | Color attribute: " + to_string(attrib) + " | Background: " + to_string(backgr) + " | Fontsize: " + to_string(fontsize);
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
