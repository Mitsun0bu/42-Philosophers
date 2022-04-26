/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_superviser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:53:03 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/26 14:13:09 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static int	does_somebody_died(t_data *data);
static int	is_everyone_full(t_data *data);

void	supervise_dinner(t_data *data)
{
	while (1)
		if (does_somebody_died(data) == YES || is_everyone_full(data) == YES)
			break ;
}

static int	does_somebody_died(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		pthread_mutex_lock(&data->death_mutex);
		if (data->death_event == YES)
		{
			pthread_mutex_unlock(&data->death_mutex);
			return (YES);
		}
		pthread_mutex_unlock(&data->death_mutex);
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
		if (data->philos[i].meal_count != data->n_time_must_eat)
		{
			pthread_mutex_unlock(&data->philos[i].meal_count_mutex);
			return (NO);
		}
		pthread_mutex_unlock(&data->philos[i].meal_count_mutex);
	}
	return (YES);
}
