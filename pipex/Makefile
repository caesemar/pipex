# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 03:06:52 by caesemar          #+#    #+#              #
#    Updated: 2023/04/10 03:10:17 by jocasado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
NAME = pipex
RM = rm -rf
HDRS = -I ./includes/
################################################################################
##								MANDATORY									  ##
################################################################################
CFILES = \
		libft/ft_strlen.c \
		libft/ft_bzero.c \
		libft/ft_strchr.c \
		libft/ft_strrchr.c \
		libft/ft_strncmp.c \
		libft/ft_calloc.c \
		libft/ft_strdup.c \
		libft/ft_strjoin.c \
		libft/ft_split.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		source/pipex.c\
		source/pipex_cmd_find.c\
		source/pipex_errors.c\
		source/pipex_childs.c
#- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - #
OBJS = $(CFILES:.c=.o)
################################################################################
.PHONY: all re fclean clean
################################################################################

all:        $(NAME)

$(NAME):	$(OBJS)
			@echo "$(YELLOW)compiling ..."
			@$(CC) $(OBJS) -o $(NAME) 
			@echo "$(GREEN)compiled:$(NAME) build ✅"
.c.o:
			@${CC} -c ${CFLAGS} $^ -o $@ ${HDRS}

re:     	fclean all

fclean:     clean
			@$(RM) $(NAME)
			@echo "$(YELLOW)deleting...\n$(RED)$(NAME) deleted"

clean:
			@$(RM) $(OBJS)
			@echo "$(YELLOW)deleting...\n$(RED)$(OBJS) deleted"

##COLOURS##
GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
