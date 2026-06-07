#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
//subfile used for testing//

int main(void)
{
    int i = 1;
    int k = 0;
    int c = 0;
    int p = 0;
    int block = 0;
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
        if (c != 127 && c!= 27 && c != 1) 
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




        //funcions//
        if(c == 1)
        {
            printw("\n  FUNCTIONS: \n       z : cut recent word\n       k : cut line\n");
            refresh();
            c = getch();
            if(c == 122)
            {
                k = i;
                block = 0;
                while (k >= 1 && block != 1)
                {
                    if (znaki[k] == 32)
                    {
                        for(p = i; p>= k; p--)
                        {
                            memset(&znaki[p], 0, sizeof(znaki[p]));
                        }
                        i = k-1;
                        block = 1;
                    }
                    else if (k == 1)
                    {
                        for(p = i; p>= k; p--)
                        {
                            memset(&znaki[p], 0, sizeof(znaki[p]));
                        }
                        i = 0;
                        block = 1;
                    }
                    k--;
                }
            }
            else if(c == 107)
            {
                k = i;
                block = 0;
                while (k >= 1 && block != 1)
                {
                    if (znaki[k] == 10)
                    {
                        for(p = i; p>= k; p--)
                        {
                            memset(&znaki[p], 0, sizeof(znaki[p]));
                        }
                        i = k-1;
                        block = 1;
                    }
                    else if (k == 1)
                    {
                        for(p = i; p>= k; p--)
                        {
                            memset(&znaki[p], 0, sizeof(znaki[p]));
                        }
                        i = 0;
                        block = 1;
                    }
                    k--;
                }
            }
            
            clear();
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