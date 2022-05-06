/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:22:39 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/06 09:47:42 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_count_mutex);
	if (philo->meal_count == 0)
	{
		pthread_mutex_unlock(&philo->meal_count_mutex);
		if (philo->id % 2 == 0)
		{
			ft_print(philo, THINK);
			usleep(100);
		}
		return ;
	}
	pthread_mutex_unlock(&philo->meal_count_mutex);
	ft_print(philo, THINK);
	return ;
}

void	philo_eat(t_philo *philo)
{
	int		i;
	long	time;

	i = philo->id;
	time = get_ts() - philo->data->start_time;
	pthread_mutex_lock(&philo->last_meal_mutex);
	philo->last_meal_ts = get_ts() - philo->data->start_time;
	pthread_mutex_unlock(&philo->last_meal_mutex);
	pthread_mutex_lock(&philo->meal_count_mutex);
	if (philo->meal_count != philo->data->n_time_must_eat)
	{
		ft_print(philo, EAT);
		philo->meal_count ++;
	}
	pthread_mutex_unlock(&philo->meal_count_mutex);
	ft_usleep(time, philo->data->time_to_eat, philo->data->start_time);
}

void	philo_sleep(t_philo *philo)
{
	long	time;

	ft_print(philo, SLEEP);
	time = get_ts() - philo->data->start_time;
	ft_usleep(time, philo->data->time_to_sleep, philo->data->start_time);
}
