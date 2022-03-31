/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_questioning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:39:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/31 18:51:27 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	am_i_alive(t_philo *philo)
{
	long	time;

	printf("Philo #%d is checking if he is alive !\n", philo->id);
	pthread_mutex_lock(&philo->data.death_checker_lock);
	time = get_ts() - philo->data.dinner_start_time;
	if (time - philo->last_meal_ts >= philo->data.time_to_die)
	{
		philo->is_alive = NO;
		philo->leave_dinner = YES;
		printf("\033[0;35m[%lu\tms]\033[0m", time);
		printf("Philo #%d died !\n", philo->id);
		return (NO);
	}
	pthread_mutex_unlock(&philo->data.death_checker_lock);
	return (YES);
}

int	am_i_full(t_philo *philo)
{
	long	time;

	printf("Philo #%d is checking if he is full !\n", philo->id);
	pthread_mutex_lock(&philo->data.meal_checker_lock);
	time = get_ts() - philo->data.dinner_start_time;
	if (philo->meal_count == philo->data.n_time_must_eat)
	{
		philo->leave_dinner = YES;
		return (YES);
	}
	pthread_mutex_unlock(&philo->data.meal_checker_lock);
}

int	does_somebody_died(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->n_philo)
	{
		pthread_mutex_lock(&data->death_checker_lock);
		if (data->philos[i].is_alive == NO)
		{
			j = -1;
			while (j++ < data->n_philo)
				data->philos[j].leave_dinner = YES;
			pthread_mutex_unlock(&data->death_checker_lock);
			return (YES);
		}
		pthread_mutex_unlock(&data->death_checker_lock);
	}
	return (NO);
}