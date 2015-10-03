// Made by Tijndagamer
// Released under the MIT license

#include <ncurses.h>
#include <stdio.h>
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

    get_choice(startx, starty);

    clrtoeol();
    refresh();
    getch();
    endwin();

    return 0;
}