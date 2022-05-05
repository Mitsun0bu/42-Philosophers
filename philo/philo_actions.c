/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:22:39 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/05 18:24:56 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_count_mutex);
	if (philo->meal_count == 0)
	{
		printf("philo #%d : HERE\n", philo->id + 1);
		if((philo->id + 1) % 2 == 0)
		{
			pthread_mutex_unlock(&philo->meal_count_mutex);
			ft_print(philo, THINK);
			usleep(1000);
		}
		else
			pthread_mutex_unlock(&philo->meal_count_mutex);
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
	ft_print(philo, EAT);
	ft_usleep(time, philo->data->time_to_eat, philo->data->start_time);
	pthread_mutex_lock(&philo->meal_count_mutex);
	philo->meal_count ++;
	pthread_mutex_unlock(&philo->meal_count_mutex);
}

void	philo_sleep(t_philo *philo)
{
	long	time;

	ft_print(philo, SLEEP);
	time = get_ts() - philo->data->start_time;
	ft_usleep(time, philo->data->time_to_sleep, philo->data->start_time);
}
