# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hnaciri- <hnaciri-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 14:18:57 by mannouao          #+#    #+#              #
#    Updated: 2022/02/18 22:00:37 by hnaciri-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell
SRCS = minishell.c \
		errors.c \
		execute.c \
		mini_tools_1.c \
		mini_tools_2.c \
		tokens.c \
		mini_cmds.c \
		init_tokens.c \
		get_cmd_paths.c \
		her_doc.c \
		mini_tools_3.c \
		builtins_cmds1.c \
		builtins_cmds2.c \
		mini_tools_4.c \
		cd_cmd.c \
		mini_tools_5.c \
		echo_cmd.c \
		mini_tools_6.c \
		export.c

LIBFT_PATH = libft/libft.a
OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -lreadline -L/Users/hnaciri-/.brew/opt/readline/lib -I/Users/hnaciri-/.brew/opt/readline/include

all : $(NAME)

$(NAME) :
	@make -C libft
	@$(CC) $(CFLAGS) $(SRCS) $(LIBFT_PATH) -o $(NAME)


clean :
	@make -C libft fclean
	@rm -f $(NAME)

fclean : clean

re : fclean all