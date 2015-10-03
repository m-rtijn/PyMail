// Made by Tijndagamer
// Released under the MIT license

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include "pymail_cli.h"

#define WIDTH 30
#define HEIGHT 10

int main(int argc, char *argv[])
{
    // Vars
    WINDOW *main_menu;
    int highlight = 1;
    int choice = 0;
    int c;

    startx = (80 - WIDTH) / 2;
    starty = (24 - HEIGHT) / 2;

    // Init ncurses
    initscr();
    clear();
    noecho();
    cbreak();

    choice = get_choice(startx, starty);

    switch(choice)
    {
        case 5:
            clrtoeol();
            refresh();
            endwin();
            return 0;
        default:
            return 1;

    }
    send(2, 2);

    clrtoeol();
    refresh();
    getch();
    endwin();
    return 0;
}