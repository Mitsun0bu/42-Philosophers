/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner_launcher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:11:27 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 09:41:19 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	philo_dinner_launcher(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = get_ts();
	while (++i < data->n_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				&philo_dinner_routine, &data->philos[i]) != 0)
		{
			printf("Error : Creation of philo thread failed !\n");
			return (FAILED);
		}
	}
	return (SUCCESS);
}
