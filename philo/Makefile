# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 10:06:02 by llethuil          #+#    #+#              #
#    Updated: 2022/03/29 19:32:56 by llethuil         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                              ~~~ COLOR CODES ~~~                             #
#                                                                              #
# **************************************************************************** #

ERASE		:=	\033[2K\r
BOLD		:=	\033[1m
RED			:=	\033[31m
GREEN		:=	\033[32m
BLUE		:=	\033[34m
PINK		:=	\033[35m
BOLD		:=	\033[1m
END			:=	\033[0m

# **************************************************************************** #
#                                                                              #
#                              ~~~ VARIABLES ~~~                               #
#                                                                              #
# **************************************************************************** #

.SILENT		:

NAME		:=	philo

INCS		:=	philo.h	\

SRCS		:=	check_args_utils.c	\
				check_args.c		\
				main.c				\

OBJS_LST		:=	$(SRCS:.c=.o)

OBJS_DIR	:=	.objs

OBJS		:= $(addprefix $(OBJS_DIR)/, $(OBJS_LST))

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror -I $(INCS) -pthread #-g -fsanitize=thread

RM			:=	rm -f

all : $(NAME)

$(OBJS_DIR) :
	mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	printf "$(BLUE)> Creating the executable file :$(END) $@\n"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o: %.c $(INCS) Makefile | $(OBJS_DIR)
	printf "$(BLUE)> Compiling :$(END) $<\n"
	$(CC) $(CFLAGS) -I $(INCS) -c $< -o $@

clean:
	printf "$(PINK)> Removing .o files ...$(END)\n"
	$(RM) $(OBJS)
	printf "$(PINK)> Removing .objs directory ...$(END)\n"
	rm -rf $(OBJS_DIR)
	printf "$(GREEN)> All the .o files have been removed successfully !$(END)\n"

fclean: clean
	printf "$(PINK)> Removing$(END) $(NAME) $(PINK)executable file ...$(END)\n"
	$(RM) $(NAME)
	printf "$(GREEN)>$(END) $(NAME) $(GREEN)executable files have been removed successfully !$(END)\n"

re: fclean all

.PHONY: all clean fclean re