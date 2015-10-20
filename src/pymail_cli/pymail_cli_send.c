// Made by Tijndagamer
// Released under the MIT license

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pymail_cli.h"

#define WIDTH 55
#define HEIGHT 20

char to_addr[256];
char subject[1024];
char body[65536];

extern char *pymail_install_dir;

void print_send_menu(WINDOW *send_menu)
{
    int x, y;
    x = 2;
    y = 1;

    box(send_menu, 0, 0);

    mvwprintw(send_menu, y, x, "To: ");
    mvwprintw(send_menu, y + 1, x, "Subject: ");
    mvwprintw(send_menu, y + 2, x, "Body: ");
    wrefresh(send_menu);

    mvwgetstr(send_menu, y, x + strlen("To: "), to_addr);
    wrefresh(send_menu);

    mvwgetstr(send_menu, y + 1, x + strlen("Subject: "), subject);
    wrefresh(send_menu);

    mvwgetstr(send_menu, y + 2, x + strlen("Body: "), body);
    wrefresh(send_menu);
}

void send(int startx, int starty)
{
    extern char *pymail_install_dir;
    WINDOW *send_menu;
    send_menu = newwin(HEIGHT, WIDTH, starty, startx);
    keypad(send_menu, TRUE);
    refresh();

    // Get all the info from the user using a nice UI
    print_send_menu(send_menu);

    erase();
    printw("Sending email...");
    refresh();
    FILE *concept_file = fopen("pymail_cli_send_concept.tmp", "w");
    if (concept_file == NULL) { terminate("Error opening file."); }

    // Write the input to our tmp concept file in a way pymail will read it correctly
    fprintf(concept_file, "%s\n--- --- ---\n%s\n--- --- ---\n%s", to_addr, subject, body);
    fclose(concept_file);

    char *cmd = " file pymail_cli_send_concept.tmp y";
    char *dest;
    strcpy(dest, pymail_install_dir);
    strcat(dest, cmd);
    system(dest);

    erase();
    refresh();
    printw("Email sent.");
    getch();
    refresh();
}