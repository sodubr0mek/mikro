#include <ncurses.h>

int main(void)
{
    int c;
    initscr();

    c = getchar();
    clear();
    printw("%d",c);


    getch();
    endwin();

    return 0;
}