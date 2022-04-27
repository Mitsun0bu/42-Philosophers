/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_after_dinner.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:30:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 09:19:42 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static void	destroy_mutex(t_data *data);

void	philo_dinner_cleaner(t_data *data)
{
	destroy_mutex(data);
	free(data->philos);
	free(data->forks);
	free(data->forks_mutex);
}

static void	destroy_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
		pthread_mutex_destroy(&data->philos[i].meal_count_mutex);
	while (++i < data->n_forks)
		pthread_mutex_destroy(&data->forks_mutex[i]);
	return ;
}
