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

char* read_tmp_email_file()
{
    FILE *recv_file = fopen("pymail_cli_recv.tmp", "r");
    if (recv_file == NULL) { terminate("Error opening file."); }
    char *recv_file_buffer;
    long file_length;

    fseek(recv_file, 0, SEEK_END);
    file_length = ftell(recv_file);
    fseek(recv_file, 0, SEEK_SET);
    recv_file_buffer = (char*)calloc(file_length, sizeof(char));
    fread(recv_file_buffer, sizeof(char), file_length, recv_file);
    fclose(recv_file);

    return recv_file_buffer;
}

void show_email(WINDOW *email_window, char *email)
{
    // TODO: Fix the way the email is displayed.
    erase();
    printf("%s", email); // A temp shitty workaround. Should fix this.
    refresh();
    getch();
    erase();
    refresh();
}

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
    //delwin(recv_choice_menu);
    refresh();
    return choice;
}

void recv_list_view(WINDOW *recv_menu)
{
    WINDOW *recv_latest_show_email;
    int x = 1;
    int y = 1;

    // Create and execute command to receive the email using PyMail
    char *cmd_part = " receive list > pymail_cli_recv.tmp";
    char cmd[2048];
    strcpy(cmd, pymail_install_dir);
    strcat(cmd, cmd_part);
    printw("Loading emails...");
    refresh();
    system(cmd);
    erase();
    refresh();

    char *email_buffer = read_tmp_email_file();
    show_email(recv_menu, email_buffer);
    free(email_buffer);
}

void recv_latest(WINDOW *recv_menu)
{
    WINDOW *recv_latest_show_email;
    int x = 1;
    int y = 1;

    // Create and execute command to receive the email using PyMail
    char *cmd_part = " receive > pymail_cli_recv.tmp";
    char cmd[2048];
    strcpy(cmd, pymail_install_dir);
    strcat(cmd, cmd_part);
    printw("Loading email...");
    refresh();
    system(cmd);
    erase();
    refresh();

    char *email_buffer = read_tmp_email_file();
    show_email(recv_menu, email_buffer);
    free(email_buffer);
}

void recv_nth(WINDOW *recv_menu, int starty, int startx)
{
    char input_n[128];
    WINDOW *recv_nth_input_menu;
    WINDOW *recv_nth_show_email;
    int x = 1;
    int y = 1;

    recv_nth_show_email = newwin(HEIGHT, WIDTH, 1, 1);

    // Get the email id from the user.
    recv_nth_input_menu = newwin(3, 18, starty, startx);
    box(recv_nth_input_menu, 0, 0);
    wrefresh(recv_nth_input_menu);

    mvwprintw(recv_nth_input_menu, y, x, "email id = ");
    wrefresh(recv_nth_input_menu);

    mvwgetstr(recv_nth_input_menu, y, x + strlen("email id = "), input_n);
    wrefresh(recv_nth_input_menu);

    // Create command to receive the email using PyMail
    char *cmd_part_1 = " receive ";
    char *cmd_part_2 = " > pymail_cli_recv.tmp";
    char cmd[2048];
    strcpy(cmd, pymail_install_dir);
    strcat(cmd, cmd_part_1);
    strcat(cmd, input_n);
    strcat(cmd, cmd_part_2);

    // Get the email by executing the previously made command.
    printw("Loading email...");
    refresh();
    system(cmd);

    // Clear the screen
    werase(recv_nth_input_menu);
    wrefresh(recv_nth_input_menu);
    erase();
    refresh();

    // Read the mail
    char *email_buffer = read_tmp_email_file();

    // TODO: Fix the way the email is displayed.
    show_email(recv_nth_show_email, email_buffer);

    free(email_buffer);
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
        erase();
        refresh();
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