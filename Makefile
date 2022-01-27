SRCS = functions/ft_split.c\
		functions/ft_strjoin.c\
		functions/ft_strlen.c\
		functions/ft_strncmp.c\
		error.c\
		child.c\
		free.c\
		main.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = pipex

${NAME}:
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

all: ${NAME}

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
