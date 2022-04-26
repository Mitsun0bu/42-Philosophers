/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_take_forks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:32:15 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/26 16:59:05 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	philo_take_forks(t_philo *philo)
{
	int		i;
	int		i_left_fork;
	int		i_right_fork;

	i = philo->id;
	i_left_fork = i;
	if (i == philo->data->n_philos - 1)
		i_right_fork = 0;
	else
		i_right_fork = i + 1;
	// am_i_an_odd_philo(philo);
	pthread_mutex_lock(&philo->data->forks_mutex[i_left_fork]);
	// if (philo->data->forks[i_left_fork] == UNUSED)
	// 	philo->data->forks[i_left_fork] = AVAILABLE;
	pthread_mutex_lock(&philo->data->forks_mutex[i_right_fork]);
	// if (philo->data->forks[i_right_fork] == UNUSED)
	// 	philo->data->forks[i_right_fork] = AVAILABLE;
	if (philo->data->forks[i_left_fork] == AVAILABLE && philo->data->forks[i_right_fork] == AVAILABLE)
	{
		philo->data->forks[i_left_fork] = BUSY;
		philo->data->forks[i_right_fork] = BUSY;
		ft_print(philo, TAKE_FORK);
		ft_print(philo, TAKE_FORK);
		return (SUCCESS);
	}
	else
	{
		philo->data->forks[i_left_fork] = AVAILABLE;
		philo->data->forks[i_right_fork] = AVAILABLE;
		pthread_mutex_unlock(&philo->data->forks_mutex[i_left_fork]);
		pthread_mutex_unlock(&philo->data->forks_mutex[i_right_fork]);
		return (FAILED);
	}
}

