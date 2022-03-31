/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_dinner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:08:49 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/31 19:07:49 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philos_dinner(t_data *data)
{
	start_dinner(data);
	supervise_dinner(data);
	end_dinner(data);
}

int	start_dinner(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				&dinner, &data->philos[i]) != 0)
		{
			printf("Error : Creation of philo thread failed !\n");
			return (FAILED);
		}
	}
	return (0);
}

void	*dinner(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		philo_take_forks(philo);
		if(am_i_alive(philo) == NO)
			break ;
		philo_eat(philo);
		if (am_i_full(philo) == YES)
			break ;
		if(am_i_alive(philo) == NO)
			break ;
		philo_sleep(philo);
		if(am_i_alive(philo) == NO)
			break ;
		philo_think(philo);
		if(am_i_alive(philo) == NO)
			break ;
	}
	return ((void *)1);
}

void	supervise_dinner(t_data *data)
{
	data->dinner_start_time = get_ts();
	while (1)
	{
		if (does_somebody_died(data) == YES)
			break ;
		if (is_everyone_full(data) == YES)
			break ;
	}
}

int	end_dinner(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (1);
	}
	return (0);
}

int	is_everyone_full(t_data *data)
{
	// check if every philo are full and only then u can break ?
}

void	check_meal_count(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		pthread_mutex_lock(&data->meal_checker_lock);
		if (data->philos[i].meal_count == data->n_time_must_eat)
		{
			data->philos[i].leave_dinner = YES;
			pthread_mutex_unlock(&data->meal_checker_lock);
			break ;
		}
		pthread_mutex_unlock(&data->meal_checker_lock);
	}
}


