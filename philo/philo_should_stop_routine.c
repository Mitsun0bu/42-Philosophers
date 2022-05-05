/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_should_stop_routine.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:28:27 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/05 18:15:11 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	philo_should_stop_routine(t_philo *philo)
{
	if (philo->data->n_forks == 1)
		usleep(philo->data->time_to_die + 1000);
	pthread_mutex_lock(&philo->data->stop_dinner_mutex);
	if (philo->data->stop_dinner == YES)
	{
		pthread_mutex_unlock(&philo->data->stop_dinner_mutex);
		return (YES);
	}
	pthread_mutex_lock(&philo->meal_count_mutex);
	return (NO);
}
