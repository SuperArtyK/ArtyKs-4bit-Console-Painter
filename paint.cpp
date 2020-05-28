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
    
    


    for (;;) {
        cngfont(2);//some random value that its not 0 or 1

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
                chngcolor(0);
                break;

            case '2':
                chngcolor(1);
                break;

            case '3':
                chngcolor(2);
                break;

            case '4':
                chngcolor(3);
                break;

            case '5':
                chngcolor(4);
                break;

            case '6':
                chngcolor(5);
                break;

            case '7':
                chngcolor(6);
                break;

            case '8':
                chngcolor(7);
                break;

            case '9':
                chngcolor(9);
                break;



            case '+':
                cngfont(0);
                break;

            case '=':
                cngfont(0);
                break;

            case '-':
                cngfont(1);
                break;

            case '_':
                cngfont(1);
                break;

            case 'r':
                resetpos();
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
