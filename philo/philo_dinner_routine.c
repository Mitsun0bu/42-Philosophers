/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:41:36 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/06 12:23:28 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	*philo_dinner_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->n_forks == 1)
	{
		usleep(philo->data->time_to_die);
		return ((void *)1);
	}
	while (1)
	{
		philo_think(philo);
		if (philo_take_forks(philo) == FAILED)
			break ;
		philo_eat(philo);
		philo_drop_forks(philo);
		if (philo_should_stop_routine(philo) == YES)
			break ;
		philo_sleep(philo);
		if (philo_should_stop_routine(philo) == YES)
			break ;
	}
	return ((void *)1);
}
