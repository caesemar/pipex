# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocasado <jocasado@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/05 03:06:52 by caesemar          #+#    #+#              #
#    Updated: 2023/04/11 17:07:57 by jocasado         ###   ########.fr        #
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
.PHONY: all re fclean clean tests
################################################################################

all:        $(NAME)

$(NAME):	$(OBJS)
			@echo "$(YELLOW)compiling ..."
			@$(CC) $(OBJS) -o  $(NAME)
			@echo "$(GREEN)compiled:$(NAME) build ✅"
.c.o:
			@${CC} ${CFLAGS} $^ -o $@ ${HDRS}

re:     	fclean all

fclean:     clean
			@$(RM) $(NAME)
			@echo "$(YELLOW)deleting...\n$(RED)$(NAME) deleted"

clean:
			@$(RM) $(OBJS)
			@echo "$(YELLOW)deleting...\n$(RED)$(OBJS) deleted"

tests: test1 test2 test3 test4 test5
		@echo "$(GREEN)tests done ✅ $(DEFAULT)"

test1:
			@echo "creating a.txt @df > a.txt" 
			@df > a.txt
			@echo "$(YELLOW)executing (non error) tests...\n$(DEFAULT)"
			@echo "$(GREEN)##TEST 1##$(DEFAULT)"
			@echo "./$(NAME) a.txt $(COMMAND1) $(COMMAND2) b.txt: \n"
			@./$(NAME) a.txt $(COMMAND1) $(COMMAND2) b.txt
			@echo "< a.txt $(COMMAND_1) | $(COMMAND_2)  > c.txt:\n"
			@ < a.txt $(COMMAND_1) | $(COMMAND_2)  > c.txt
			@echo "diff b.txt c.txt"
			@diff b.txt c.txt
test2:
			@echo "$(GREEN)##TEST 2##$(DEFAULT)"
			@echo "input pipex :./$(NAME) a.txt $(COMMAND1) $(COMMAND3) b.txt: \n"
			@./$(NAME) a.txt $(COMMAND1) $(COMMAND3) b.txt
			@echo "input bash: < a.txt $(COMMAND_1) | $(COMMAND_3)  > c.txt:\n"
			@ < a.txt $(COMMAND_1) | $(COMMAND_3)  > c.txt
			@echo "diff b.txt c.txt"
			@diff b.txt c.txt
test3:
			@echo "$(GREEN)##TEST 3##$(DEFAULT)"
			@echo "input pipex :./$(NAME) a.txt $(COMMAND1) $(COMMAND4) b.txt: \n"
			@./$(NAME) a.txt $(COMMAND1) $(COMMAND4) b.txt
			@echo "input bash: < a.txt $(COMMAND_1) | $(COMMAND_4)  > c.txt:\n"
			@ < a.txt $(COMMAND_1) | $(COMMAND_4)  > c.txt
			@echo "diff b.txt c.txt"
			@diff b.txt c.txt
test4:
			@echo "$(GREEN)##TEST 4##$(DEFAULT)"
			@echo "input pipex :./$(NAME) a.txt $(COMMAND5) $(COMMAND5) b.txt: \n"
			@./$(NAME) a.txt $(COMMAND5) $(COMMAND5) b.txt
			@echo "input bash: < a.txt $(COMMAND_5) | $(COMMAND_5)  > c.txt:\n"
			@ < a.txt $(COMMAND_5) | $(COMMAND_5)  > c.txt
			@echo "diff b.txt c.txt"
			@diff b.txt c.txt
test5:
			@echo "$(GREEN)##TEST 5##$(DEFAULT)"
			@echo "input pipex :./$(NAME) a.txt $(COMMAND4) $(COMMAND5) b.txt: \n"
			@./$(NAME) a.txt $(COMMAND4) $(COMMAND5) b.txt
			@echo "input bash: < a.txt $(COMMAND_4) | $(COMMAND_5)  > c.txt:\n"
			@ < a.txt $(COMMAND_4) | $(COMMAND_5)  > c.txt
			@echo "diff b.txt c.txt"
			@diff b.txt c.txt

##COLOURS##
GREEN = \033[1;32m
YELLOW = \033[1;33m
RED = \033[1;31m
DEFAULT = \033[0m

##COMMANDS##
COMMAND1 = "grep /"
COMMAND2 = "wc -l"
COMMAND_1 = grep /
COMMAND_2 = wc -l
COMMAND3 = "/usr/bin/wc -l"
COMMAND_3 = /usr/bin/wc -l
COMMAND4 = "awk '/^\// {print}'"
COMMAND_4 = awk '/^\// {print}'
COMMAND5 = "cat"
COMMAND_5 = cat