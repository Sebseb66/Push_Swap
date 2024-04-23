# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfroidev <sfroidev@student.42perpignan.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/12 10:43:22 by sfroidev          #+#    #+#              #
#    Updated: 2023/10/03 10:07:55 by sfroidev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =  $(wildcard src/*.c utils/*.c)

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@echo "\033[34mCompile Push_Swap...\033[0m"
	@${MAKE} -C ./utils/libft
	@${CC} ${CFLAGS} ${OBJS} ./utils/libft/libft.a -o ${NAME}
	@echo "\033[32mCompilation OK...\033[0m"

clean: 
	@echo "\033[33mEnlève les fichiers .o ...\033[0m"
	@${MAKE} -C ./utils/libft clean
	${RM} ${OBJS}

fclean: clean
	@echo "\033[33mEnlève Push_Swap...\033[0m"
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
.SILENT: