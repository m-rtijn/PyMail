// Made by Tijndagamer
// Released under the MIT license

#include <ncurses.h>
#include <stdio.h>
#include "pymail_cli.h"

#define WIDTH 55
#define HEIGHT 20

void print_send_menu(WINDOW *send_menu)
{
    int x, y, i;
    x = 2;
    y = 2;

    box(send_menu, 0, 0);

    mvwprintw(send_menu, y, x, "To:");
    mvwprintw(send_menu, y + 3, x, "Subject:");
    mvwprintw(send_menu, y + 6, x, "Body:");
    wrefresh(send_menu);

    char to_address[256]; 
    mvwgetstr(send_menu, y, x + 3, to_address);
    wrefresh(send_menu);

    mvwprintw(send_menu, y, x + 4, "%s", to_address);
    wrefresh(send_menu);
}

void send(int startx, int starty)
{
    WINDOW *send_menu;

    send_menu = newwin(HEIGHT, WIDTH, startx, starty);
    keypad(send_menu, TRUE);
    refresh();

    print_send_menu(send_menu);
}