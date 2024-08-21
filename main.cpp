#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#include <unistd.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <locale.h>
#include <ncursesw/ncurses.h>
#include <cmath>


//std::wcout.imbue(std::locale("ja_jp.utf-8"));

double pth (double x,double y, double mx, double my)  {
    return sqrt (pow((x-mx),2)+pow((y-my)/2,2));
 }

 double cy (double x,double r, double mx, double my)  {
    return sqrt (pow((r),2)+pow((x-mx),2))+my;
 }

int main() {
    // Set locale
   // srand(time(NULL));
    int rng;
    int rng2;

        WINDOW *mainwin;

    if ( (mainwin = initscr()) == NULL)
    {
        exit(EXIT_FAILURE);
    }

    int mx,my;
    int rngmx;



   
    std::setlocale(LC_ALL, "");

    //initialize ncurses mode
    initscr();

    cbreak();
    noecho();
    timeout(0); // Set the delay for getch() to 0 milliseconds

    //define the character to move
  //  wchar_t ch[] = L"木";
      int ch;
      double rngx;
      double rngy;

    const wchar_t* inject[33]={L"ぁ",L"ぃ",L"い",L"ぅ",L"う",L"ぇ",L"え",L"ぉ",L"お",L"か",L"が",L"き",L"ぎ",
        L"く",L"け",L"げ",L"こ",L"さ",L"ざ",L"す",L"じ",L"ず",L"ぜ",L"ぞ",L"ち",L"の",
        L"ロ",L"ヲ",L"ヴ",L"ユ",L"ミ",L"ポ",L"ホ"};

    const wchar_t* inject2[2]={L"0",L"1"};

   
    int chars = 33;

    // set seed to time(0)
    srand(time(0));

  
  


    
    if (has_colors()) {
    use_default_colors();
    start_color();
    init_pair(1, COLOR_GREEN, -1);
    init_pair(2, COLOR_RED, -1);
    init_pair(3, COLOR_BLUE, -1);
    init_pair(4, COLOR_CYAN, -1);
    init_pair(5, COLOR_MAGENTA, -1);
    init_pair(6, COLOR_YELLOW, -1);
    init_pair(7, COLOR_WHITE, -1);
    }

    srand(static_cast<unsigned int>(time(0)));
  
    int pos[COLS] = {0};

    int count= 0;

double r = 1;
double tol = 0.1;
 double hx = 0;
 double hy = 0;
 while(1) {

           int ch = getch();


    count++;

      getmaxyx(mainwin,mx,my);

  
     
        
  

        int randomNumber3 = rand() % 7 + 1;
        attrset(COLOR_PAIR(randomNumber3));


       rng = rand() % chars; 
       rng2 = rand() % 2;

        rngx = rand() % mx;
        rngy = rand() % my;

        hx = mx/2;
        hy = my/2;

        if ((double) pth(rngx,rngy,hx,hy) > (r - r*tol) && (double) pth(rngx,rngy,hx,hy) < (r + r*tol)) {
            addwstr(inject2[rng2]);  //inject[rng]
            move(rngx, rngy);
        }

        if(r+r*tol > mx/2){
                usleep(1);
               r = 1/10;
               count = 0;
            }

  
        refresh();
       // usleep(5);  // 100 milliseconds


        if(count > COLS*LINES){
            count = 0;
            r= r + 1;
        }

        if (ch == 'q') {
            break;
        }

    }

    // End ncurses mode
    endwin();

    return 0;
}
