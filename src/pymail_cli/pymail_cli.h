// Made by Tijndagamer
// Released under the MIT license

#ifndef PYMAIL_CLI_H
#define PYMAIL_CLI_H

int startx;
int starty;

int main(int argc, char *argv[]);
void terminate(char *errormsg);

void print_choice_menu(WINDOW *choice_menu, int highlight);
int get_choice(int startx, int starty);

void print_send_menu(WINDOW *send_menu);
void send(int startx, int starty);

void print_help();

#endif // PYMAIL_CLI_H