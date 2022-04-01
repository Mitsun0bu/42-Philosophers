/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:52:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/01 18:44:00 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_take_forks(t_philo *philo)
{
	int		i;
	long	time;

	i = philo->id - 1;

	pthread_mutex_lock(&philo->data->forks[i]);
	if (philo->id < philo->data->n_philos)
		pthread_mutex_lock(&philo->data->forks[i + 1]);
	else if (i == philo->data->n_philos)
		pthread_mutex_lock(&philo->data->forks[0]);

	time = get_ts() - philo->data->dinner_start_time;
	if (should_i_stop(philo) == NO)
	{
		pthread_mutex_unlock(&philo->print);
		printf("\033[0;35m[%lu\tms]\033[0m Philo #%d is holding forks !\n", time, philo->id);
		pthread_mutex_unlock(&philo->print);
	}
}

void	philo_eat(t_philo *philo)
{
	int		i;
	long	time;

	i = philo->id - 1;

	time = get_ts() - philo->data->dinner_start_time;
	philo->last_meal_ts = time;

	if (should_i_stop(philo) == NO)
	{
		pthread_mutex_lock(&philo->print);
		printf("\033[0;35m[%lu\tms]\033[0m Philo #%d is eating !\n", time, philo->id);
		pthread_mutex_unlock(&philo->print);
	}

	usleep(philo->data->time_to_eat * 1000);

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
	time = get_ts() - philo->data->dinner_start_time;

	if (should_i_stop(philo) == NO)
	{
		pthread_mutex_lock(&philo->print);
		printf("\033[0;36m[%lu\tms]\033[0m Philo #%d is sleeping !\n", time, philo->id);
		pthread_mutex_unlock(&philo->print);
	}

	usleep(philo->data->time_to_sleep * 1000);
}

void	philo_think(t_philo *philo)
{
	int		i;
	long	time;

	i = philo->id - 1;

	time = get_ts() - philo->data->dinner_start_time;

	if (should_i_stop(philo) == NO)
	{
		pthread_mutex_lock(&philo->print);
		printf("\033[0;32m[%lu\tms]\033[0m Philo #%d is thinking !\n", time, philo->id);
		pthread_mutex_unlock(&philo->print);
	}
}