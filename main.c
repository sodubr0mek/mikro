#include <ncurses.h>
#include<string.h>

int main (void) 
{
    char text[4000];
    int c;
    int i = 0;
    int k;


    initscr();

    for (i=1; i<=4001; i++)
    {
        c = getch();
        clear();
        if (c != 127)
        {
            text[i] = (char)c;
        }

        //backspace
        if (c == 127 && i > 1)
        {
            memset(&text[i-1], 0, sizeof(text[i-1]));
            i = i-2;
        }
        if (c == 127 && i == 0)
        {
            memset(&text[0], 0, sizeof(text[0]));
            i = 0;
        }

        //escape
        if(c == 27)
        {
            memset(&text, 0, sizeof(text));
            endwin();






            
            return 0;
        }

        //wypisz
        for (k = 1; k<=i; k++)
        {
            printw("%c", text[k]);
        }
        refresh();


    }


    





    getch();
    endwin();



    return 0;
}