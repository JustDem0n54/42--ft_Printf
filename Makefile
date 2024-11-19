NAME	= libftprintf.a

LIBC	= ft_printf.c ft_utilities.c

SRCS	= ${LIBC}

OBJS	= ${SRCS:.c=.o}

CC		= cc
RM		= rm -rf
AR		= ar rc

CFLAGS	= -Wall -Werror -Wextra

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJSALL}

fclean:		clean
			${RM} ${NAME}

re:			fclean all
