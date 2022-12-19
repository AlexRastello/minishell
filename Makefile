SRCS = 	main.c \
		srcs/builtins/echo/echo_logic.c \
		srcs/builtins/echo/echo_utils.c \
		srcs/builtins/env/env.c \
		srcs/builtins/unset/unset.c \
		srcs/builtins/pwd/pwd_logic.c\
		srcs/builtins/cd/cd_logic.c\
		srcs/builtins/cd/cd_utils.c\
		srcs/builtins/manage_builtins.c \
		srcs/builtins/exit/ft_exit.c \
		srcs/builtins/export/export.c \
    	srcs/utils/env_list.c \
		srcs/utils/env_list2.c \
		srcs/utils/env_list3.c \
		srcs/utils/parse_list.c \
		srcs/utils/utils.c \
		srcs/utils/fd_list.c \
		srcs/pipe/ft_pipe.c \
		srcs/pipe/path.c \
		srcs/pipe/pipe_utils.c \
		srcs/pipe/pipe_utils2.c \
		srcs/parsing/lexer.c \
		srcs/parsing/utils/tokens.c \
		srcs/parsing/parser.c \
		srcs/parsing/parser2.c \
		srcs/parsing/expander.c \
		srcs/signal/handler.c \
		srcs/free/free_obs.c \
		srcs/free/free_obs2.c
		
OBJS = $(SRCS:.c=.o)

NAME = minishell

LIB = libftminishell.a

USER = $(shell whoami)

CFLAGS = -Wall -Wextra -Werror

LIB_EXTERN = -L./library/libft -l ft -L./library/ft_printf -l ftprintf -L./library/gnl -l gnl -L /Users/$(USER)/.brew/opt/readline/lib -l readline
 
HEADERS = -I /Users/$(USER)/.brew/opt/readline/include/ -I includes/

.c.o:
	gcc $(CFLAGS) $(HEADERS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	make -C library/ft_printf
	make -C library/libft
	make -C library/gnl
	ar crs $(LIB) $(OBJS)
	gcc $(CFLAGS) $(LIB_EXTERN) $(HEADERS) -L. -lftminishell -o $(NAME)

all: $(NAME)

clean:
	make clean -C library/ft_printf
	make clean -C library/libft
	make clean -C library/gnl
	rm -rf $(OBJS)

fclean: clean
	make fclean -C library/ft_printf
	make fclean -C library/libft
	make fclean -Clibrary/gnl
	rm -rf $(LIB)
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
