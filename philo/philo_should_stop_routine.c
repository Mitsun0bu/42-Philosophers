/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_should_stop_routine.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:28:27 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 09:42:21 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static int	am_i_alive(t_philo *philo);
static int	am_i_full(t_philo *philo);

int	philo_should_stop_routine(t_philo *philo)
{
	while (philo->data->n_forks == 1)
	{
		usleep(philo->data->time_to_die);
		if (am_i_alive(philo) == NO)
			return (YES);
	}
	if (am_i_alive(philo) == NO || am_i_full(philo) == YES)
		return (YES);
	return (NO);
}

static int	am_i_alive(t_philo *philo)
{
	long	time;

	time = get_ts() - philo->data->start_time;
	if (time - philo->last_meal_ts >= philo->data->time_to_die)
	{
		ft_print(philo, DIE);
		pthread_mutex_lock(&philo->data->death_mutex);
		philo->data->death_event = YES;
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (NO);
	}
	return (YES);
}

static int	am_i_full(t_philo *philo)
{
	long	time;

	time = get_ts() - philo->data->start_time;
	pthread_mutex_lock(&philo->meal_count_mutex);
	if (philo->meal_count == philo->data->n_time_must_eat)
	{
		pthread_mutex_unlock(&philo->meal_count_mutex);
		return (YES);
	}
	pthread_mutex_unlock(&philo->meal_count_mutex);
	return (NO);
}
