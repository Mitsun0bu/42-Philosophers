/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner_ender.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:16:49 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 09:57:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	philo_dinner_ender(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (FAILED);
	return (SUCCESS);
}
