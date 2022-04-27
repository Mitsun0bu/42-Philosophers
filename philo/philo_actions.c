/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:22:39 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 09:40:52 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_eat(t_philo *philo)
{
	int		i;
	long	time;

	i = philo->id;
	ft_print(philo, EAT);
	time = get_ts() - philo->data->start_time;
	ft_usleep(time, philo->data->time_to_eat, philo->data->start_time);
	pthread_mutex_lock(&philo->meal_count_mutex);
	philo->meal_count ++;
	pthread_mutex_unlock(&philo->meal_count_mutex);
	philo->last_meal_ts = get_ts() - philo->data->start_time;
}

void	philo_sleep(t_philo *philo)
{
	long	time;

	ft_print(philo, SLEEP);
	time = get_ts() - philo->data->start_time;
	ft_usleep(time, philo->data->time_to_sleep, philo->data->start_time);
}

void	philo_think(t_philo *philo)
{
	ft_print(philo, THINK);
}
