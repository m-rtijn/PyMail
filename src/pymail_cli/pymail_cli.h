// Made by Tijndagamer
// Released under the MIT license

#ifndef PYMAIL_CLI_H
#define PYMAIL_CLI_H

int main(int argc, char *argv[]);
void terminate(char *errormsg);

void print_choice_menu(WINDOW *choice_menu, int highlight);
int get_choice(int startx, int starty);

void print_send_menu(WINDOW *send_menu);
void send(int startx, int starty);

void print_receive_menu(WINDOW *recv_menu);
void recv(int startx, int starty);

void print_help();

//void print_config_menu(WINDOW *conf_menu);
//void config(int startx, int starty)

#endif // PYMAIL_CLI_H