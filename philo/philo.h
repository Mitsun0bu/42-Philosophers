/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:59:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 09:57:46 by llethuil         ###   ########lyon.fr   */
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
# define SUCCESS 1
# define NO 0
# define YES 1
# define AVAILABLE 0
# define BUSY 1
# define DIE 0
# define TAKE_FORK 1
# define EAT 2
# define DROP_FORK 3
# define SLEEP 4
# define THINK 5

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

typedef struct s_data
{
	int				n_philos;
	int				n_forks;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_time_must_eat;
	long			start_time;
	int				death_event;
	pthread_mutex_t	death_mutex;
	int				*forks;
	pthread_mutex_t	*forks_mutex;
	struct s_philo	*philos;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meal_count;
	pthread_mutex_t	meal_count_mutex;
	long			last_meal_ts;
	pthread_t		thread;
	struct s_data	*data;
}	t_philo;

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/*	main.c	*/
int		main(int ac, char **av);

/*	philo_actions_forks.c */
int		philo_take_forks(t_philo *philo);
void	philo_drop_forks(t_philo *philo);

/*	philo_actions.c */
void	philo_eat(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

/*	philo_dinner_cleaner.c */
void	philo_dinner_cleaner(t_data *data);

/*	philo_dinner_ender.c */
int		philo_dinner_ender(t_data *data);

/*	philo_dinner_initializer.c	*/
int		philo_dinner_initializer(int ac, char **av, t_data *data);

/*	philo_dinner_launcher.c	*/
int		philo_dinner_launcher(t_data *data);

/* philo_dinner_routine.c	*/
void	*philo_dinner_routine(void *arg);

/* philo_dinner_supervisor.c */
void	philo_dinner_supervisor(t_data *data);

/*	philo_should_stop_routine.c	*/
int		philo_should_stop_routine(t_philo *philo);

/* philo_waiting_line.c */
void	philo_waiting_line(t_philo *philo);

/*	utils_global.c	*/
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t size, size_t count);
long	get_ts(void);
void	ft_print(t_philo *philo, int action);
void	ft_usleep(long time, int action_duration, long dinner_start);

/*	utils_prepare_philo_for_dinner.c	*/
int		check_n_args(int ac);
int		check_arg_is_nbr(int ac, char **av);
int		check_arg_overflow(int ac, char **av);
int		ft_atoi(char *str);

#endif