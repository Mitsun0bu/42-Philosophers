/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_dinner_routine.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 09:32:57 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/25 09:33:14 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

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