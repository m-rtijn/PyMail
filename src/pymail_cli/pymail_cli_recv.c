// Made by Tijndagamer
// Released under the MIT license

#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include "pymail_cli.h"

#define WIDTH 55
#define HEIGHT 20

#define CHOICE_MENU_WIDTH 25
#define CHOICE_MENU_HEIGHT 8

extern char *pymail_install_dir;

char *recv_choices[] = {
            "View latest",
            "List view",
            "View n-th email",
            "Back",
                  };
int recv_choicesc = sizeof(recv_choices) / sizeof(char *);

void print_recv_choice_menu(WINDOW *recv_choice_menu, int highlight)
{
    int x, y, i;
    x = 2;
    y = 2;

    box(recv_choice_menu, 0, 0);
    for(i = 0; i < recv_choicesc; ++i)
    {
        if (highlight == i + 1)
        {
            wattron(recv_choice_menu, A_REVERSE);
            mvwprintw(recv_choice_menu, y, x, "%s", recv_choices[i]);
            wattroff(recv_choice_menu, A_REVERSE);
        }
        else
        {
            mvwprintw(recv_choice_menu, y, x, "%s", recv_choices[i]);
        }
        ++y;
    }

    wrefresh(recv_choice_menu);
}

int recv_get_choice(int starty, int startx)
{
    WINDOW *recv_choice_menu;
    int highlight = 1;
    int choice = 0;
    int c;

    recv_choice_menu = newwin(CHOICE_MENU_HEIGHT, CHOICE_MENU_WIDTH, starty, startx);
    keypad(recv_choice_menu, TRUE);
    refresh();
    print_recv_choice_menu(recv_choice_menu, highlight);
    while(1)
    {
        c = wgetch(recv_choice_menu);
        switch(c)
        {
            case KEY_UP:
                if (highlight == 1)
                {
                    highlight = recv_choicesc;
                }
                else
                {
                    --highlight;
                }
                break;
            case KEY_DOWN:
                if (highlight == recv_choicesc)
                {
                    highlight = 1;
                }
                else
                {
                    ++highlight;
                }
                break;
            case 10:
                choice = highlight;
                break;
            default:
                refresh();
                break;
        }
        print_recv_choice_menu(recv_choice_menu, highlight);
        if (choice != 0)
        {
            break;
        }
    }

    wclear(recv_choice_menu);
    werase(recv_choice_menu);
    wrefresh(recv_choice_menu);
    delwin(recv_choice_menu);
    refresh();
    return choice;
}

void recv_list_view(WINDOW *recv_menu)
{
    erase();
    printw("TODO: Add this (recv list view)");
    getch();
    return;
}

void recv_latest(WINDOW *recv_menu)
{
    erase();
    printw("TODO: Add this (recv latest)");
    getch();
    return;
}

void recv_nth(WINDOW *recv_menu, int starty, int startx)
{
    WINDOW *recv_nth_input_menu;
    recv_nth_input_menu = newwin(3, 18, starty, startx);

    box(recv_nth_input_menu, 0, 0);
    wrefresh(recv_nth_input_menu);
    mvwprintw(recv_nth_input_menu, 1, 1, "email id = ");
    wrefresh(recv_nth_input_menu);
    getch();
    return;
}

void recv(int startx, int starty)
{
    erase();
    WINDOW *recv_menu;
    recv_menu = newwin(HEIGHT, WIDTH, 2, 2);
    keypad(recv_menu, TRUE);
    refresh();
    int choice;

    while(1)
    {
        choice = recv_get_choice(starty, startx);

        switch(choice)
        {
            case 1:
                recv_latest(recv_menu);
                break;
            case 2:
                recv_list_view(recv_menu);
                break;
            case 3:
                recv_nth(recv_menu, starty, startx);
                break;
            case 4:
                return;
        }
        refresh();
        wrefresh(recv_menu);
    }

}