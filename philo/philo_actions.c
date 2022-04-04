/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:52:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/04 19:11:50 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_take_forks(t_philo *philo)
{
	int		i;
	long	time;

	i = philo->id - 1;

	pthread_mutex_lock(&philo->data->forks[i]);
	if (philo->data->n_forks == 1)
		usleep(philo->data->time_to_die * 1000);
	if (i < philo->data->n_philos)
		pthread_mutex_lock(&philo->data->forks[i + 1]);
	else if (i == philo->data->n_philos)
		pthread_mutex_lock(&philo->data->forks[0]);
	time = get_ts() - philo->data->start_time;
	if (should_i_stop(philo) == NO)
	{
		pthread_mutex_lock(&philo->print);
		printf("\033[0;35m[%lu\tms]\033[0m Philo #%d is holding forks !\n", time, philo->id);
		pthread_mutex_unlock(&philo->print);
	}
}

void	philo_eat(t_philo *philo)
{
	int		i;
	long	time;

	i = philo->id - 1;
	pthread_mutex_lock(&philo->data->time);
	time = get_ts() - philo->data->start_time;
	pthread_mutex_unlock(&philo->data->time);
	philo->last_meal_ts = time;
	if (should_i_stop(philo) == NO)
	{
		pthread_mutex_lock(&philo->print);
		printf("\033[0;35m[%lu\tms]\033[0m Philo #%d is eating !\n", time, philo->id);
		pthread_mutex_unlock(&philo->print);
	}
	my_usleep(time, philo->data->time_to_eat, philo->data->start_time);
	pthread_mutex_lock(&philo->meal);
	philo->meal_count ++;
	pthread_mutex_unlock(&philo->meal);
}

void	philo_drop_forks(t_philo *philo)
{
	int	i;

	i = philo->id - 1;
	pthread_mutex_unlock(&philo->data->forks[i]);
	if (philo->id < philo->data->n_philos)
		pthread_mutex_unlock(&philo->data->forks[i + 1]);
	else if (i == philo->data->n_philos)
		pthread_mutex_unlock(&philo->data->forks[0]);
}

void	philo_sleep(t_philo *philo)
{
	int		i;
	long	time;


	i = philo->id - 1;
		pthread_mutex_lock(&philo->data->time);
	time = get_ts() - philo->data->start_time;
	pthread_mutex_unlock(&philo->data->time);
	if (should_i_stop(philo) == NO)
	{
		pthread_mutex_lock(&philo->print);
		printf("\033[0;36m[%lu\tms]\033[0m Philo #%d is sleeping !\n", time, philo->id);
		pthread_mutex_unlock(&philo->print);
	}
	my_usleep(time, philo->data->time_to_sleep, philo->data->start_time);
}

void	philo_think(t_philo *philo)
{
	int		i;
	long	time;

	i = philo->id - 1;
	pthread_mutex_lock(&philo->data->time);
	time = get_ts() - philo->data->start_time;
	pthread_mutex_unlock(&philo->data->time);
	if (should_i_stop(philo) == NO)
	{
		pthread_mutex_lock(&philo->print);
		printf("\033[0;32m[%lu\tms]\033[0m Philo #%d is thinking !\n", time, philo->id);
		pthread_mutex_unlock(&philo->print);
	}
}

