CC = gcc
CFLAGS = -w
INCLUDES = -I.
LIBS = -lncurses
SRCS = pymail_cli_main.c pymail_cli_choice_menu.c pymail_cli_send.c pymail_cli_help.c

# Define the object files by replacing .c with .o
OBJS = $(SRCS:.c=.o)

# Define the executable file
MAIN = pymail_cli

.PHONY: depend clean

all:    $(MAIN)
	@echo  Simple compiler named $(MAIN) has been compiled
	$(RM) *.o

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $<  -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it