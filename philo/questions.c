/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_questioning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:39:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/25 09:53:26 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	should_i_stop(t_philo *philo)
{
	if (am_i_alive(philo) == NO || am_i_full(philo) == YES)
	{
		philo_drop_forks(philo);
		return (YES);
	}

	// pthread_mutex_lock(&philo->presence);
	// if (philo->leave_dinner == YES)
	// {
	// 	pthread_mutex_unlock(&philo->presence);
	// 	philo_drop_forks(philo);
	// 	return (YES);
	// }
	// pthread_mutex_unlock(&philo->presence);

	// pthread_mutex_lock(&philo->data->death);
	// if (philo->data->death_event == YES)
	// {
	// 	pthread_mutex_unlock(&philo->data->death);
	// 	philo_drop_forks(philo);
	// 	return (YES);
	// }
	// pthread_mutex_unlock(&philo->data->death);

	return (NO);
}

int	am_i_alive(t_philo *philo)
{
	long	time;

	time = get_ts() - philo->data->start_time;
	if (time - philo->last_meal_ts >= philo->data->time_to_die)
	{
		ft_print(philo, time, DIE);
		philo->data->death_event = YES;
		return (NO);
	}
	return (YES);
}

int	am_i_full(t_philo *philo)
{
	long	time;

	time = get_ts() - philo->data->start_time;
	pthread_mutex_lock(&philo->meal);
	if (philo->meal_count == philo->data->n_time_must_eat)
	{
		pthread_mutex_unlock(&philo->meal);
		pthread_mutex_lock(&philo->presence);
		philo->leave_dinner = YES;
		pthread_mutex_unlock(&philo->presence);
		return (YES);
	}
	pthread_mutex_unlock(&philo->meal);
	return (NO);
}

void	am_i_an_odd_philo(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(100);
	else
		return ;
}
