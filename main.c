#include <ncurses.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    int i = 1;
    int k = 0;
    int c = 0;
    int doLoop = 1;
    int ask = 1;
    char * znaki;
    char * temp;
    znaki = (char*)malloc(8*sizeof(char));
    temp = (char*)malloc(8*sizeof(char));


    initscr();
    
    while (doLoop == 1)
    {
        temp = (char*)malloc(i + 2);

        for (k = 1; k <= i; k++)
        {
            temp[k] = znaki[k];
        }

        znaki = (char*)malloc(i + 2);

        for (k = 1; k <= i; k++)
        {
            znaki[k] = temp[k];
        }
        free(temp);



        c = getch();
        clear();
        if (c != 127 && c != 27) 
        {
            znaki[i] = (char)c;
        }

        //backspace//
        if(c == 127 && i > 1)
        {
            memset(&znaki[i-1], 0, sizeof(znaki[i-1]));
            i = i-2;
        }
        else if (c == 127 && i == 1)
        {
            memset(&znaki[0], 0, sizeof(znaki[0]));
            i--;
        }

        //escape//
        if(c == 27)
        {
            ask = 1;
            while(ask == 1)
            {
                printw("\n  Close? [y/n]: ");
                refresh();
                c = getch();
                if (c == 121)
                {
                    endwin();
                    ask = 0;
                    return 0;
                }
                if (c == 110)
                {
                    doLoop = 1;
                    ask = 0;
                    clear();
                }
                else
                {
                    doLoop = 1;
                    clear();
                }
            }

        }


        for (k = 1; k <= i; k++)
        {
            printw("%c",znaki[k]);
        }
        refresh();

        i++;


    }
    free(znaki);



    return 0;
}