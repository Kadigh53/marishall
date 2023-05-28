# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 18:08:49 by aaoutem-          #+#    #+#              #
#    Updated: 2023/05/28 02:19:00 by aaoutem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# utils/error.c \

NAME = minishell
CC = gcc
FLAGS  = -Wall
RM = rm
SRC = minishell.c \
		utils/ft_strncmp.c\
		utils/ft_strlen.c \
		utils/ft_substr.c \
		utils/ft_strdup.c \
		utils/ft_bzero.c \
		utils/ft_memcpy.c \
		utils/ft_memset.c \
		utils/ft_calloc.c \
		utils/ft_malloc.c \
		utils/ft_split.c \
		utils/ft_strjoin.c \
		utils/set_env.c \
		utils/ft_lstnew.c\
		utils/ft_lstsize.c\
		utils/ft_lstadd_back.c\
		utils/ft_lstadd_front.c\
		utils/get_newenv.c\
		utils/set_env.c \
		execution/cmd_execute.c\
		execution/Builtins/cd.c\
		execution/Builtins/pwd.c\
		execution/Builtins/env.c\
		execution/Builtins/echo.c\
		execution/Builtins/exit.c\
		execution/Builtins/unset.c\
		execution/Builtins/export.c\

OBJ_F = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ_F} ${SRC}
	${CC} ${FLAGS} ${OBJ_F} -o minishell

%.o : %.c
	${CC} ${FLAGS} $< 

clean :
	${RM} ${OBJ_F}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY : re fclean clean all