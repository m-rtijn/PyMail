// Made by Tijndagamer
// Released under the MIT license

#include <ncurses.h>
#include <stdio.h>
#include "pymail_cli.h"

#define WIDTH 30
#define HEIGHT 10

char *choices[] = {
            "Send email",
            "Receive email",
            "Help",
            "Config",
            "Exit",
                  };
int choicesc = sizeof(choices) / sizeof(char *);

void print_choice_menu(WINDOW *choice_menu, int highlight)
{
    int x, y, i;
    x = 2;
    y = 2;

    box(choice_menu, 0, 0);
    for(i = 0; i < choicesc; ++i)
    {
        if (highlight == i + 1)
        {
            wattron(choice_menu, A_REVERSE);
            mvwprintw(choice_menu, y, x, "%s", choices[i]);
            wattroff(choice_menu, A_REVERSE);
        }
        else
        {
            mvwprintw(choice_menu, y, x, "%s", choices[i]);
        }
        ++y;
    }

    wrefresh(choice_menu);
}

int get_choice(int startx, int starty)
{
    WINDOW *choice_menu;
    int highlight = 1;
    int choice = 0;
    int c;

    choice_menu = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(choice_menu, TRUE);
    refresh();
    print_choice_menu(choice_menu, highlight);
    while(1)
    {
        c = wgetch(choice_menu);
        switch(c)
        {
            case KEY_UP:
                if (highlight == 1)
                {
                    highlight = choicesc;
                }
                else
                {
                    --highlight;
                }
                break;
            case KEY_DOWN:
                if (highlight == choicesc)
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
                //mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
                refresh();
                break;
        }
        print_choice_menu(choice_menu, highlight);
        if (choice != 0)
        {
            break;
        }
    }

    //mvprintw(23, 0, "%s", choices[choice - 1]);
    wclear(choice_menu);
    wclrtobot(choice_menu);
    wclrtoeol(choice_menu);
    wrefresh(choice_menu);
    delwin(choice_menu);
    refresh();
    return choice;
}