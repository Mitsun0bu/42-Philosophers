/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:08:49 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/30 18:46:01 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_dinner(t_data *data)
{
	start_dinner(data);
	end_dinner(data);
}

int	start_dinner(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &dinner, &*data) != 0)
		{
			printf("Error : Creation of philo thread failed !\n");
			return (FAILED);
		}
	}
	return (0);
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

void	*dinner(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	return ((void *)1);
}

	// while (1)
	// {
	// 	if (data->philo == data->args.n_time_must_eat)
	// 		break ;
	// 	if (philo->param->n_philo == 1)
	// 	{
	// 		usleep(philo->param->time_to_die * 1000);
	// 		check_my_death(philo);
	// 		break ;
	// 	}
	// 	if (!ft_eat(philo))
	// 		break ;
	// 	if (!ft_sleep(philo))
	// 		break ;
	// 	if (!ft_think(philo))
	// 		break ;
	// }
