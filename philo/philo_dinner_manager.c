/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:08:49 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/25 09:33:31 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static int	start_dinner(t_data *data);
static int	end_dinner(t_data *data);

void	philo_dinner_manager(t_data *data)
{
	if (start_dinner(data) == FAILED)
		return ;
	supervise_dinner(data);
	end_dinner(data);
}

static int	start_dinner(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = get_ts();
	while (++i < data->n_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				&dinner_routine, &data->philos[i]) != 0)
		{
			printf("Error : Creation of philo thread failed !\n");
			return (FAILED);
		}
	}
	return (0);
}

static int	end_dinner(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (1);
	return (0);
}
