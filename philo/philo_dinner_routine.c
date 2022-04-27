/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:41:36 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 09:48:46 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	*philo_dinner_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo_waiting_line(philo);
	while (1)
	{
		if (philo_should_stop_routine(philo) == YES)
			break ;
		if (philo_take_forks(philo) == FAILED)
			continue ;
		philo_eat(philo);
		philo_drop_forks(philo);
		if (philo_should_stop_routine(philo) == YES)
			break ;
		philo_sleep(philo);
		if (philo_should_stop_routine(philo) == YES)
			break ;
		philo_think(philo);
	}
	return ((void *)1);
}
