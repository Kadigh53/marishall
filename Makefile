# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 18:08:49 by aaoutem-          #+#    #+#              #
#    Updated: 2023/05/21 18:21:45 by aaoutem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = GCC
SRC = execution\cmd_execute.c\
		execution/Builtins/cd.c\
		execution/Builtins/pwd.c\
		execution/Builtins/env.c\
		execution/Builtins/echo.c\
		execution/Builtins/exit.c\
		execution/Builtins/unset.c\
		execution/Builtins/export.c\
		utils\error.c\
		utils\ft_strncmp.c\
		utils\ft_strlen.c\
		utils\ft_substr.c\
		utils\ft_strdup.c\
		utils\ft_bzero.c\
		utils\ft_memcpy.c\
		utils\ft_memset.c \
		utils\ft_calloc.c\
		utils\ft_malloc.c\
		utils\ft_lstnew.c\
		utils\ft_lstsize.c\
		utils\ft_lstadd_back.c\
		utils\ft_lstadd_front.c\
		utils\get_newenv.c\
		utils\set_env.c\

OBJ_F = ${SRC:.c=.o}

all : ${NAME}

NAME : ${OBJ_F}

