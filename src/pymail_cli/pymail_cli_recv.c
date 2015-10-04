// Made by Tijndagamer
// Released under the MIT license

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "pymail_cli.h"

#define WIDTH 55
#define HEIGHT 20

extern char *pymail_install_dir;

void print_receive_menu(WINDOW *recv_menu)
{
    box(recv_menu, 0, 0);
    wrefresh(recv_menu);
    wprintw(recv_menu, "%s", pymail_install_dir);
    wrefresh(recv_menu);
    getch();
}

void recv(int startx, int starty)
{
    WINDOW *recv_menu;
    recv_menu = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(recv_menu, TRUE);
    refresh();

    print_receive_menu(recv_menu);
}