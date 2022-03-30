/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:59:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/30 18:46:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define FAILED -1
# define FALSE 0
# define TRUE 1

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

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	eat_count;
	long			last_meal_ts;
	pthread_t		thread;
}	t_philo;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_data
{
	int				n_philo;
	int				n_fork;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_time_must_eat;
	struct s_philo	*philos;
	struct s_fork	*forks;
	long			dinner_start_time;
	int				dinner_can_start;
	pthread_mutex_t	dinner_start_lock;
	int				death_event;
	pthread_mutex_t	death_event_lock;
}	t_data;

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/*	check_args.c	*/
int		check_args(int ac, char **av);
int		check_n_args(int ac);
int		check_arg_is_nbr(int ac, char **av);
int		check_arg_overflow(int ac, char **av);

/*	init_data_for_dinner.c	*/
int		init_data_before_dinner(int ac, char **av, t_data *data);
void	get_args(char **av, t_data *data);
int		init_philos(t_data *data);
int		init_forks(t_data *data);
int		init_rest_of_data(t_data *data);

/*	main.c	*/
int		main(int ac, char **av);

/*	philo_dinner.c	*/
void	philo_dinner(t_data *data);
int		start_dinner(t_data *data);
void	*dinner(void *arg);
int		end_dinner(t_data *data);

/* clean_data_after_dinner.c */
void	clean_data_after_dinner(t_data *data);

/*	utils.c	*/
void	*ft_memset(void *b, int c, size_t len);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
void	destroy_mutex(t_data *data);

#endif