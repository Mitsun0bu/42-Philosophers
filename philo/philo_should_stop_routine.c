/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_should_stop_routine.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:28:27 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/06 12:18:04 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	philo_should_stop_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->stop_dinner_mutex);
	if (philo->data->stop_dinner == YES)
	{
		pthread_mutex_unlock(&philo->data->stop_dinner_mutex);
		return (YES);
	}
	pthread_mutex_unlock(&philo->data->stop_dinner_mutex);
	return (NO);
}
