#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
//subfile used for testing//

int funMenu(void)
{
    int c;
    int k;
    int funcn = 2;
    int loopin = 1;
    char funcarray[3];
    funcarray[0] = '>';
    funcarray[1] = ' ';
    funcarray[2] = ' ';
    clear();
    printw("\n  FUNCTIONS MENU\n%c 1 : cut recent word\n%c 2 : cut recent line\n%c 3 : save as file\n\n", funcarray[0], funcarray[1], funcarray[2]);
    refresh();

    int pick = 0;

    while (loopin == 1)
    {
        c = getch();


        if (c == 115)
        {
            pick++;
        }
        if (c == 119)
        {
            pick--;
        }


        //enter RETURNS - 1z, 2k
        if (c == 10)
        {
            if (pick == 0)
            {
                clear();
                refresh();
                return 1;
            }
            if (pick == 1)
            {
                clear();
                refresh();
                return 2;
            }
            if (pick == 2)
            {
                clear();
                refresh();
                return 3;
            }
        }
        if (c == 49)
        {
            clear();
            refresh();
            return 1;
        }
        if (c == 50)
        {
            clear();
            refresh();
            return 2;
        }
        if (c == 51)
        {
            clear();
            refresh();
            return 3;
        }


        if (pick == -1)
        {
            pick = funcn;
        }
        if (pick == funcn + 1)
        {
            pick = 0;
        }

        for(k = 0; k<= funcn; k++)
        {
            funcarray[k] = ' ';
        }
        funcarray[pick] = '>';
        clear();

        printw("\n  FUNCTIONS MENU\n%c 1 : cut recent word\n%c 2 : cut recent line\n%c 3 : save as file\n\n", funcarray[0], funcarray[1], funcarray[2]);
        refresh();
    }








}

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
            int calledfunc = funMenu();
            refresh();
            if(calledfunc == 1)
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
            else if(calledfunc == 2)
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
            else if (calledfunc == 3)
            {
                //save to file
                FILE *fptr;
                clear();
                printw("\n  Name file : ");
                
                char savf[128];
                int enterpressed = 0;
                int sfn;
                int is = 1;
                int ks = 1;
                while (enterpressed != 1)
                {
                    ks = 1;
                    sfn = getch();
                    clear();
                    printw("\n  Name file : ");
                    

                    if(sfn != 127 && sfn != 10)
                    {
                        savf[is] = (char)sfn;
                    } 
                    if(sfn == 10)
                    {
                        enterpressed = 1;

                    }  
                    if(sfn == 127 && is > 2)
                    {
                        memset(&savf[is-1], 0, sizeof(char));
                        is = is-2;
                    }
                    else if(sfn == 127 && is == 2)
                    {
                        memset(&savf[1], 0 , sizeof(char));
                        is = 0;
                    }
                    else if(sfn == 127 && is == 1)
                    {
                        is = 0;
                    }


                    if(strlen(savf) == 0 && is == 2)
                    {
                        is = -1;
                    }

                    for(ks = 1; ks<=is; ks++)
                    {
                        printw("%c", savf[ks]);
                    }  

                    refresh();
                    is++;               
                }
                savf[is+2] = 't';
                savf[is+1] = 'x';
                savf[is] = 't';
                savf[is-1] = '.';
                memset(&savf[is+3], 0, sizeof(savf[is+3]));
                fptr = fopen(&savf[1], "w");
                fptr = fopen(&savf[1], "w");
                fprintf(fptr, &znaki[1]);

                fclose(fptr); 


            }
        }
            
            
            clear();

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

//TO DO: move saving to file to external function, add safeguards for different key combinations, make opening files from external function from main