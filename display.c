#include <ncurses.h>
//Used to get the ASCII number of a pressed key; may not work properly with not sign keys (e.g. ctrl+C)//
int main(void)
{
    int c;
    initscr();

    c = getchar();
    clear();
    printw("%d",c);


    getch();
    endwin();

    return 0;./
}