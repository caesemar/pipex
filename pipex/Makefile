# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 03:06:52 by caesemar          #+#    #+#              #
#    Updated: 2023/03/31 19:45:07 by jocasado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -c -Wall -Wextra -Werror
AR = ar -rcs
NAME = pipex
RM = rm -rf
HDRS = pipex.h
################################################################################
##								MANDATORY									  ##
################################################################################
CFILES = \
		libft/ft_strlen.c \
		libft/ft_memset.c \
		libft/ft_bzero.c \
		libft/ft_memcpy.c \
		libft/ft_memmove.c \
		libft/ft_strlcpy.c \
		libft/ft_strlcat.c \
		libft/ft_strchr.c \
		libft/ft_strrchr.c \
		libft/ft_strncmp.c \
		libft/ft_memchr.c \
		libft/ft_memcmp.c \
		libft/ft_strnstr.c \
		libft/ft_atoi.c \
		libft/ft_calloc.c \
		libft/ft_strdup.c \
		libft/ft_substr.c \
		libft/ft_strjoin.c \
		libft/ft_strtrim.c \
		libft/ft_split.c \
		libft/ft_itoa.c \
		libft/ft_strmapi.c \
		libft/ft_striteri.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		pipex.c\
		pipex_cmd_find.c\
		pipex_errors.c\
		pipex_childs.c
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
			@${CC} ${CFLAGS} $< -o ${<:.c=.o} -I ${HDRS}

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