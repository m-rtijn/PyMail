#!/bin/bash

cc pymail_cli_main.c pymail_cli_choice_menu.c pymail_cli_send.c pymail_cli_help.c -w -lncurses -o pymail_cli
