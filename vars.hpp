#pragma once
#ifndef VARS_H
#include "include.hpp"
using namespace std;



string mode = "Paint";
short attrib = 15;
bool pallete = 0;
short colornum = 0;
short lastpos[3];
short attribm = 112;
short color[]{

	15 ,
30 ,
44 ,
62 ,
74 ,
91 ,
107,
112,
143,
158,
172,
185,
202,
219,
233,
240,
};

short backgr = color[0];



CONSOLE_FONT_INFOEX cfi;
HWND console = GetConsoleWindow();
RECT r;


short cx;
short fontsize = 8;
int line = 5, column = 5, x;
int maxl = 64, maxc = 64;
string build = "832";
char text[1048576];
string spicture = "";
char picture[] = "! bbbbb  bbbbbb  bbbbbbbb bb    bb aa   aa  c   eeeeeee     dd   dd cccccc  aa 99999999!bb   bb bb   bb    bb     bb  bb  aa  aa   c   ee          dd   dd cc   cc aa    99   !bbbbbbb bbbbbb     bb      bbbb   aaaaa        eeeeeee     ddddddd cccccc  aa    99   !bb   bb bb   bb    bb       bb    aa  aa            ee          dd cc   cc aa    99   !bb   bb bb   bb    bb       bb    aa   aa      eeeeeee          dd cccccc  aa    99   !! 333333  333333  333    33 3333333  333333  33      3333333 !33      33    33 3333   33 33      33    33 33      33      !33      33    33 33 33  33 3333333 33    33 33      33333   !33      33    33 33  33 33      33 33    33 33      33      ! 333333  333333  33   3333 3333333  333333  3333333 3333333 !                                                            !222222   22222  22 222    22 22222222 2222222 222222        !22   22 22   22 22 2222   22    22    22      22   22       !222222  2222222 22 22 22  22    22    22222   222222        !22      22   22 22 22  22 22    22    22      22   22       !22      22   22 22 22   2222    22    2222222 22   22 ";
string name = "ArtyK's 4bit Console Painter v1.0.3." + build;
LPCSTR lname = name.c_str();

short lastcol = 0;


















#endif // !VARS_H
