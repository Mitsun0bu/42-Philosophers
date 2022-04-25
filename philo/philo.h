/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:59:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/25 10:10:28 by llethuil         ###   ########lyon.fr   */
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
# define NO 0
# define YES 1
# define DIE 0
# define TAKE 1
# define EAT 2
# define DROP 3
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
	pthread_mutex_t	death;
	pthread_mutex_t	*forks;
	struct s_philo	*philos;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				n_fork_held;
	int				meal_count;
	pthread_mutex_t	meal;
	long			last_meal_ts;
	int				leave_dinner;
	pthread_mutex_t	presence;
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

/*	actions	*/
void	philo_take_forks(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_drop_forks(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);

/* cleaner.c */
void	clean_after_dinner(t_data *data);

/*	questions.c	*/
int		should_i_stop(t_philo *philo);
int		am_i_alive(t_philo *philo);
int		am_i_full(t_philo *philo);
void	am_i_an_odd_philo(t_philo *philo);

/*	dinner_manager.c	*/
void	philos_diner_manager(t_data *data);

/* dinner_routine.c	*/
void	*dinner(void *arg);

/* dinner_superviser.c */
void	supervise_dinner(t_data *data);

void	check_meal_count(t_data *data);

/*	dinner_initializer.c	*/
int		prepare_philos_for_dinner(int ac, char **av, t_data *data);

/*	dinner_initializer_utils.c	*/
int		check_n_args(int ac);
int		check_arg_is_nbr(int ac, char **av);
int		check_arg_overflow(int ac, char **av);
int		ft_atoi(char *str);

/*	utils.c	*/
long	get_ts(void);
void	ft_usleep(long	time, int	action_duration, long dinner_start);
void	ft_print(t_philo *philo, long time, int action);

#endif