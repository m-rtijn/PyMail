// Made by Tijndagamer
// Released under the MIT license

#ifndef PYMAIL_CLI_H
#define PYMAIL_CLI_H

int startx;
int starty;
char *choices[];

int main(int argc, char *argv[]);
void print_main_menu(WINDOW *main_menu, int highligh);
int get_choice(int startx, int starty);
void sent_menu(int startx, int starty);

#endif // PYMAIL_CLI_H