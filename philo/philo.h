/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:59:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/29 19:39:05 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

/* ULLONG_MAX */
# include <limits.h>

/* pthread */
# include <pthread.h>

/* printf */
# include <stdio.h>

/* free, malloc */
# include <stdlib.h>

/* memset */
# include <string.h>

/* gettimeofday */
# include <sys/time.h>

/* write */
# include <unistd.h>

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ TYPEDEFS ~~~                              */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_args
{
	int				n_philo;
	int				n_fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_time_must_eat;
}	t_args;

typedef struct s_philo
{
	int				id;
	t_args			*args;
	long			last_meal_ts;
	int				eat_count;
	pthread_t		philo_thread;
	pthread_mutex_t	fork;
}	t_philo;

// pthread_mutex_t	death_event;
// long			start_time;

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/*	check_args_utils.c	*/
int	ft_atoi(char *str);
int	ft_isdigit(int c);

/*	check_args.c		*/
int	check_args(int ac, char **av);
int	check_n_args(int ac);
int	check_arg_is_nbr(int ac, char **av);
int	check_arg_overflow(int ac, char **av);

/*	main.c				*/
int	main(int ac, char **av);

#endif