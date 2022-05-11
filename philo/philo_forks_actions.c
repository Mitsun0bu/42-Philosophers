/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:57:37 by llethuil          #+#    #+#             */
/*   Updated: 2022/05/11 09:57:42 by llethuil         ###   ########lyon.fr   */
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
	pthread_mutex_lock(&philo->data->forks_mutex[i_left_fork]);
	philo->data->forks[i_left_fork] = BUSY;
	pthread_mutex_lock(&philo->data->forks_mutex[i_right_fork]);
	philo->data->forks[i_right_fork] = BUSY;
	ft_print(philo, TAKE_FORK);
	ft_print(philo, TAKE_FORK);
	return (SUCCESS);
}

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
