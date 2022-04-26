/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:23:12 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/26 16:56:54 by llethuil         ###   ########lyon.fr   */
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
