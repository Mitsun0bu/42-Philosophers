/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:32:57 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/26 20:59:15 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	*dinner_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	am_i_an_odd_philo(philo);
	while (1)
	{
		if(should_i_stop(philo) == YES)
			break ;
		if (philo_take_forks(philo) == FAILED)
			continue;
		philo_eat(philo);
		philo_drop_forks(philo);
		philo_sleep(philo);
		if(should_i_stop(philo) == YES)
			break ;
		philo_think(philo);
		if(should_i_stop(philo) == YES)
			break ;
	}
	return ((void *)1);
}