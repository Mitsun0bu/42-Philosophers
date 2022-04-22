/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_questioning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:39:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 18:30:28 by llethuil         ###   ########lyon.fr   */
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
		pthread_mutex_lock(&philo->data->death);
		if (philo->data->death_event == NO)
		{
			printf("\033[0;35m[%lu\tms]\033[0m Philo #%d died !\n", time, philo->id);
			philo->data->death_event = YES;
		}
		pthread_mutex_unlock(&philo->data->death);
		return (NO);
	}
	return (YES);
}

int	am_i_full(t_philo *philo)
{
	long	time;

	// pthread_mutex_lock(&philo->data->time);
	time = get_ts() - philo->data->start_time;
	// pthread_mutex_unlock(&philo->data->time);

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

int	does_somebody_died(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->n_philos)
	{
		pthread_mutex_lock(&data->death);
		if (data->death_event == YES)
		{
			pthread_mutex_unlock(&data->death);
			j = -1;
			while (j++ < data->n_philos)
			{
				pthread_mutex_lock(&data->philos[j].presence);
				data->philos[j].leave_dinner = YES;
				pthread_mutex_unlock(&data->philos[j].presence);
			}
			return (YES);
		}
		pthread_mutex_unlock(&data->death);
	}
	return (NO);
}

int	is_everyone_full(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal);
		if (data->philos[i].meal_count != data->n_time_must_eat)
		{
			pthread_mutex_unlock(&data->philos[i].meal);
			return (NO);
		}
		pthread_mutex_unlock(&data->philos[i].meal);
	}
	return (YES);
}
