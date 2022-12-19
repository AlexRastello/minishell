SRCS	=	srcs/ft_check.c \
			srcs/ft_printf_char.c \
			srcs/ft_printf_dec.c \
			srcs/ft_printf_hex.c \
			srcs/ft_printf_ptr.c \
			srcs/ft_printf_str.c \
			srcs/ft_printf.c \
			srcs/ft_putnbr.c 

OBJS	=	${SRCS:.c=.o}

RM		=	rm -f

CFLAGS	=	-Wall -Wextra -Werror

NAME	= libftprintf.a

.c.o:
	gcc ${CFLAGS} -I ./includes -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	make -C ../libft
	ar rc ${NAME} ${OBJS}

all:	${NAME}

clean:
	make clean -C ../libft
	${RM} ${OBJS}

fclean:	clean
	make fclean -C ../libft
	${RM} ${NAME}

re:	fclean all

.PHONY: all clean flcean re
