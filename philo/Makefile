# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 10:06:02 by llethuil          #+#    #+#              #
#    Updated: 2022/05/05 18:07:33 by llethuil         ###   ########lyon.fr    #
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

INCS		:=	philo.h

SRCS		:=	main.c						\
				philo_actions.c				\
				philo_dinner_cleaner.c		\
				philo_dinner_ender.c		\
				philo_dinner_initializer.c	\
				philo_dinner_launcher.c		\
				philo_dinner_routine.c		\
				philo_dinner_supervisor.c	\
				philo_drop_forks.c			\
				philo_should_stop_routine.c	\
				philo_take_forks.c			\
				utils_global.c				\
				utils_initializer.c			\

OBJS_LST		:=	$(SRCS:.c=.o)

OBJS_DIR	:=	.objs

OBJS		:= $(addprefix $(OBJS_DIR)/, $(OBJS_LST))

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror -I $(INCS) -pthread

#	To use valgrind --leak-check=full
#	add the flag :	-ggdb3

#	To check for data race
#	add the flags :	-g -fsanitize=thread

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