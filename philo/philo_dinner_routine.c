/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:41:36 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/05 18:23:10 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	*philo_dinner_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		philo_think(philo);
		printf("philo #%d : THERE\n", philo->id + 1);
		if (philo_should_stop_routine(philo) == YES)
			break ;
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
