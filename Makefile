NAME = libftprintf.a

CC= cc
CFLAGS= -c -Wall -Werror -Wextra
AR= ar rcs
RM= rm -rf

CFILES= $(wildcard *.c)
BSRC= $(wildcard *_bonus.c)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(CFILES)
	$(AR) $(NAME) $(CFILES:.c=.o)

clean:
	$(RM) $(wildcard *.o)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

bonus:
	$(CC) $(CFLAGS) $(BSRC)
	$(AR) $(NAME) $(BSRC:.c=.o)

.PHONY:  all clean fclean re bonus