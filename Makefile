##
## Makefile for 42sh in /home/mourau_a/PSU_2015_42sh
##
## Made by Mouraud Andrea
## Login   <mourau_a@epitech.net>
##
## Started on  Fri May  6 02:00:32 2016 Mouraud Andrea
## Last update Sun Jun  5 21:57:33 2016 Johan Ganem--Brunet
##

NAME	=	42sh

SRCS	+=	shell/main.c
SRCS    +=	utils/my_str_to_wordtab.c
SRCS    +=	shell/prompt.c
SRCS    +=	utils/epur_str.c
SRCS    +=	shell/my_prog.c
SRCS    +=	shell/check_prog.c
SRCS    +=	parser/parser.c
SRCS	+=	parser/parser2.c
SRCS    +=	utils/free_tab.c
SRCS    +=	utils/get_next_line.c
SRCS    +=	shell/get_path.c
SRCS    +=	shell/redirections.c
SRCS    +=	utils/my_strcmp.c
SRCS    +=	builtins/my_exit.c
SRCS    +=	builtins/builtins.c
SRCS    +=	builtins/echo.c
SRCS    +=	builtins/my_cd.c
SRCS	+=	parser/parser_pipe.c
SRCS	+=	utils/detect_pipe.c
SRCS	+=	shell/pipe.c
SRCS	+=	utils/tablen.c
SRCS	+=	parser/init_parser.c
SRCS	+=	utils/clear_str.c

ECHO	=	echo -e

OBJS	=	$(addprefix sources/, $(SRCS:.c=.o))

CC	=	gcc

RM	=	rm -rf

CFLAGS	+=	-W
CFLAGS	+=	-Wall
CFLAGS  +=	-Wextra
CFLAGS  +=	-Werror
CFLAGS  +=      -I./include

$(NAME)	:	$(OBJS)
		@$(CC) -o $(NAME) $(OBJS)
		clear
		@$(ECHO) '\033[00;34m'
		@$(ECHO) '------> \033[00;31m Compilation completed'
		@$(ECHO) '\033[01;00m'

all	:	$(NAME)

clean	:
		$(RM) $(OBJS)
		clear
		@$(ECHO) '\033[00;34m'
		@$(ECHO) '------> \033[00;31m Clean completed'
		@$(ECHO) '\033[01;00m'

fclean	:	clean
		$(RM) $(NAME)
		clear
		@$(ECHO) '\033[00;34m'
		@$(ECHO) '------> \033[00;31m FClean completed'
		@$(ECHO) '\033[01;00m'

re	:	fclean all

.PHONY	:	all clean fclean re
