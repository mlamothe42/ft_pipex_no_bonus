SRCS		=	./ft_bzero.c ./ft_memccpy.c ./ft_memchr.c ./ft_memcmp.c ./ft_memcpy.c ./ft_memmove.c \
				./ft_memset.c ./ft_isalnum.c ./ft_isascii.c ./ft_isalpha.c ./ft_isdigit.c ./ft_isprint.c \
				./ft_toupper.c ./ft_tolower.c ./ft_strchr.c ./ft_strrchr.c ./ft_strncmp.c \
				./ft_strlcpy.c ./ft_strlcat.c ./ft_strlen.c ./ft_strnstr.c ./ft_strtrim.c \
				./ft_strdup.c ./ft_substr.c ./ft_strjoin.c ./ft_atoi.c ./ft_itoa.c ./ft_calloc.c \
				./ft_split.c ./ft_strmapi.c ./ft_putchar_fd.c ./ft_putstr_fd.c \
				./ft_putendl_fd.c ./ft_putnbr_fd.c

SRCS_BONUS	=	./ft_lstnew.c ./ft_lstadd_front.c ./ft_lstsize.c ./ft_lstlast.c ./ft_lstadd_back.c \
				./ft_lstdelone.c ./ft_lstclear.c ./ft_lstiter.c ./ft_lstmap.c

HDRS		= ./

OBJS		= ${SRCS:.c=.o}

OBJS_BONUS	= ${SRCS_BONUS:.c=.o}

NAME		= libft.a

CC			= gcc

CFLAG		=  -Wall -Wextra -Werror

OPTS		= -c -I ${HDRS}

RM			= rm -f

green = /bin/echo -e "\x1b[32m$1\x1b[0m"

yellow = /bin/echo -e "\x1b[33m$1\x1b[0m"

_END=$'\x1b[0m'

.c.o:
	@${CC} ${OPTS} ${CFLAG} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}
			@ranlib ${NAME}
			@$(call green,"making done")

all:		${NAME}

bonus:		${NAME} ${OBJS_BONUS}
			@ar rc ${NAME} ${OBJS_BONUS}
			@ranlib ${NAME}
			@$(call green,"making done")

clean:
			@${RM} ${OBJS} ${OBJS_BONUS}
			@$(call green,"libft cleaned")

fclean:
			@${RM} ${OBJS} ${OBJS_BONUS}
			@$(call green,"libft cleaned")
			@${RM} ${NAME}
			
re:			fclean all

.PHONY:		all clean fclean re bonus
