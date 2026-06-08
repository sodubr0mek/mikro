#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
    char nazwa[20];
    nazwa[1] = 'n';
    nazwa[2] = 'a';
    nazwa[3] = 'w';

    FILE *fptr;

    fptr = fopen(&nazwa[1], "w");
    fclose(fptr);





    return 0;
}