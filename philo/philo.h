/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 18:59:07 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/04 19:16:56 by llethuil         ###   ########lyon.fr   */
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
	pthread_mutex_t	time;
	int				death_event;
	pthread_mutex_t	death;
	pthread_mutex_t	*forks;
	struct s_philo	*philos;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_mutex_t	odd_id;
	int				meal_count;
	pthread_mutex_t	meal;
	long			last_meal_ts;
	int				leave_dinner;
	pthread_mutex_t	presence;
	pthread_mutex_t	print;
	pthread_t		thread;
	struct s_data	*data;
}	t_philo;

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

/* clean_data_after_dinner.c */
void	clean_after_dinner(t_data *data);

/*	main.c	*/
int		main(int ac, char **av);

/*	philo_actions	*/
void	philo_take_forks(t_philo *philo);
void	philo_eat(t_philo *philo);
void	philo_drop_forks(t_philo *philo);
void	philo_sleep(t_philo *philo);
void	philo_think(t_philo *philo);
void	my_usleep(long	time, int	action_duration, long dinner_start);

/*	philo_questioning.c	*/
int		should_i_stop(t_philo *philo);
int		am_i_alive(t_philo *philo);
int		am_i_full(t_philo *philo);
void	am_i_an_odd_philo(t_philo *philo);
int		does_somebody_died(t_data *data);
int		is_everyone_full(t_data *data);

/*	philo_dinner.c	*/
void	philos_dinner(t_data *data);
int		start_dinner(t_data *data);
void	*dinner(void *arg);
void	supervise_dinner(t_data *data);
int		end_dinner(t_data *data);
void	check_meal_count(t_data *data);

/*	prepare_philos_for_dinner.c	*/
int		prepare_philos_for_dinner(int ac, char **av, t_data *data);
void	get_args(char **av, t_data *data);
int		init_other_data(t_data *data);
int		init_philos(t_data *data);

/*	utils.c	*/
void	*ft_memset(void *b, int c, size_t len);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
long	get_ts(void);
void	destroy_mutex(t_data *data);

#endif