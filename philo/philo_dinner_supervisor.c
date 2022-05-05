/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner_supervisor.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:53:03 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/05 17:28:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static int	does_somebody_died(t_data *data);
static int	is_everyone_full(t_data *data);

void	philo_dinner_supervisor(t_data *data)
{
	while (1)
		if (does_somebody_died(data) == YES || is_everyone_full(data) == YES)
			break ;
}

static int	does_somebody_died(t_data *data)
{
	long	time;
	int		i;

	time = get_ts() - data->start_time;
	i = -1;
	while (++i < data->n_philos)
	{
		pthread_mutex_lock(&data->philos[i].last_meal_mutex);
		if (time - data->philos[i].last_meal_ts > data->time_to_die)
		{
			pthread_mutex_unlock(&data->philos[i].last_meal_mutex);
			ft_print(&data->philos[i], DIE);
			pthread_mutex_lock(&data->stop_dinner_mutex);
			data->stop_dinner = YES;
			pthread_mutex_unlock(&data->stop_dinner_mutex);
			return (YES);
		}
		pthread_mutex_unlock(&data->philos[i].last_meal_mutex);
	}
	return (NO);
}

static int	is_everyone_full(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		pthread_mutex_lock(&data->philos[i].meal_count_mutex);
		if (data->philos[i].meal_count == data->n_time_must_eat)
		{
			pthread_mutex_unlock(&data->philos[i].meal_count_mutex);
			pthread_mutex_lock(&data->stop_dinner_mutex);
			data->stop_dinner = YES;
			pthread_mutex_unlock(&data->stop_dinner_mutex);
			return (YES);
		}
		pthread_mutex_unlock(&data->philos[i].meal_count_mutex);
	}
	return (NO);
}
