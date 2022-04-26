/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:59:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/26 16:58:33 by llethuil         ###   ########lyon.fr   */
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
// # define UNUSED 0
// # define AVAILABLE 1
// # define BUSY -1
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

/* am_i_an_odd_philo.c */
void	am_i_an_odd_philo(t_philo *philo);

/* clean_after_dinner.c */
void	clean_after_dinner(t_data *data);

/* dinner_routine.c	*/
void	*dinner_routine(void *arg);

/*	main.c	*/
int		main(int ac, char **av);

/* philo_drop_forks.c */
void	philo_drop_forks(t_philo *philo);

/* philo_eat.c */
void	philo_eat(t_philo *philo);

/* philo_sleep.c */
void	philo_sleep(t_philo *philo);

/* philo_take_forks.c */
int		philo_take_forks(t_philo *philo);

/* philo_think.c */
void	philo_think(t_philo *philo);

/*	philo_dinner_manager.c	*/
void	philo_dinner_manager(t_data *data);

/*	prepare_philo_for_dinner.c	*/
int		prepare_philos_for_dinner(int ac, char **av, t_data *data);

/*	should_i_stop.c	*/
int		should_i_stop(t_philo *philo);

/* dinner_superviser.c */
void	supervise_dinner(t_data *data);

/*	utils_global.c	*/
long	get_ts(void);
void	ft_usleep(long	time, int	action_duration, long dinner_start);
void	ft_print(t_philo *philo, int action);
void	*ft_calloc(size_t size, size_t count);
void	*ft_memset(void *b, int c, size_t len);

/*	utils_prepare_philo_for_dinner.c	*/
int		check_n_args(int ac);
int		check_arg_is_nbr(int ac, char **av);
int		check_arg_overflow(int ac, char **av);
int		ft_atoi(char *str);

#endif