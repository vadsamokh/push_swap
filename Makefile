.PHONY:	re all clean fclean

NAME =	push_swap

SRCS =	./main.c \
		./algorithms.c \
		./instructions1.c \
		./instructions2.c \
		./instructions3.c \
		./lst_utils.c \
		./markups.c \
		./shift_variants.c \
		./sorting_1.c \
		./sorting_2.c

INCLUDES =	./headers

LIBRARIES =	./libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -O2

all:	${NAME}

${LIBRARIES}:
		make -C ./libft/
		cp ./libft/libft.a .

${NAME}: ${SRCS} ${INCLUDES} ${LIBRARIES}
		${CC} ${SRCS} -o ${NAME} ${CFLAGS} -I ${INCLUDES} ${LIBRARIES}

clean:
		$(MAKE) clean -C ./libft/


fclean:	clean
		$(MAKE) fclean -C ./libft/
		rm -f ${LIBRARIES}
		rm -f ${NAME}

re:		fclean all
