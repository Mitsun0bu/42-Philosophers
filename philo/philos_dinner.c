/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_dinner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:08:49 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 11:37:52 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philos_dinner(t_data *data)
{
	if (start_dinner(data) == FAILED)
		return ;
	supervise_dinner(data);
	end_dinner(data);
}

int	start_dinner(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = get_ts();
	while (++i < data->n_philos)
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
	am_i_an_odd_philo(philo);
	while (1)
	{
		philo_take_forks(philo);
		if(should_i_stop(philo) == YES)
			break;
		philo_eat(philo);
		philo_drop_forks(philo);
		if(should_i_stop(philo) == YES)
			break ;
		philo_sleep(philo);
		if(should_i_stop(philo) == YES)
			break ;
		philo_think(philo);
		if(should_i_stop(philo) == YES)
			break ;
	}
	return ((void *)1);
}

void	supervise_dinner(t_data *data)
{
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
	while (++i < data->n_philos)
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (1);
	return (0);
}