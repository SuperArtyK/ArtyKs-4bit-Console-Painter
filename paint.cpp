// paint.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "funcs.hpp"
#include "vars.hpp"
#include "include.hpp"
using namespace std;
int main()
{

    
    startup();
    //setCursorPosition(column, line);
    logodraw();
    paintstart();
    
    line = 1;
    column = 1;


    for (;;) {
        cfi.dwFontSize.X = fontsize;                   // Width of each character in the font
        cfi.dwFontSize.Y = fontsize;
        SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

        if (_kbhit()) {
            switch (_getch())
            {
            case 's':

                draw(0);
                break;

            case 'd':
                draw(1);
                break;

            case 'w':
                draw(2);
                break;

            case 'a':
                draw(3);
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
                line = 1;
                column = 1;
                colornum = 0;
                pallete = 0;
                break;

            case 'h':
                help();
                break;

            case 'b':

                chngback();
                break;

            case '0':

                erase();

                break;

            case 10:
                clearscr();
                break;

            

            case 13:
                clearscr();
                break;

            case 27:
                exitpaint();
                break;


            default:
                break;
            }
        }



         
        
        postproc();
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
