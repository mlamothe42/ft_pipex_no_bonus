SRCS		=	./srcs/ft_pipex.c ./srcs/ft_parse.c ./srcs/ft_parse2.c ./srcs/ft_split_params.c ./srcs/errors_nfree.c

OBJS		= ${SRCS:.c=.o}

HDRS		= ./includes

NAME		= pipex

CFLAG		= -Wall -Wextra -Werror

OPTS		= ${ADDLIBFT} -I ${HDRS}

ADDLIBFT	= -L./libft -lft

VALF		= --tool=memcheck --leak-check=full --leak-resolution=high --show-reachable=yes --track-origins=yes --log-file=valgrind_log

cyan = /bin/echo -e "\x1b[36m$1\x1b[0m"

green = /bin/echo -e "\x1b[32m$1\x1b[0m"

yellow = /bin/echo -e "\x1b[33m$1\x1b[0m"

all:		${NAME}

.c.o:		
			@gcc -c ${CFLAG} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@$(call cyan,"-- MAKING LIBFT --")
			@make --no-print-directory -C libft
			@$(call cyan,"-- COMPILING ALL FILES --")
			@gcc ${OBJS} ${ADDLIBFT} -o ${NAME}
			@$(call green,"making done")

clean:		
			@$(call cyan,"-- CLEANING--")
			@make --no-print-directory -C libft clean
			@rm -f ${OBJS} ${OBJS_BONUS}
			@$(call green,"${NAME} cleaned")

leaks	:
			valgrind ${VALF} ./${NAME} in "ls -l" "cat" out
			grep -A1 "valgrind" valgrind_log | grep ${NAME} || echo -n

fclean:
			@$(call cyan,"-- CLEANING --")
			@make --no-print-directory -C libft fclean
			@rm -f ${NAME} ${OBJS} ${OBJS_BONUS}
			@$(call green,"${NAME} cleaned")

re:			fclean all

.PHONY:		all clean fclean re bonus
