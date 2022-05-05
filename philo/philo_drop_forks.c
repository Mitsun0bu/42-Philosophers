/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_drop_forks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:24:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/05 17:50:06 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_drop_forks(t_philo *philo)
{
	int	i;
	int	i_left_fork;
	int	i_right_fork;

	i = philo->id;
	i_left_fork = i;
	if (i == philo->data->n_philos - 1)
		i_right_fork = 0;
	else
		i_right_fork = i + 1;
	philo->data->forks[i_left_fork] = AVAILABLE;
	philo->data->forks[i_right_fork] = AVAILABLE;
	pthread_mutex_unlock(&philo->data->forks_mutex[i_left_fork]);
	pthread_mutex_unlock(&philo->data->forks_mutex[i_right_fork]);
}
