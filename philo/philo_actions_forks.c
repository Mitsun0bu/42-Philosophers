/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 09:24:06 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 11:43:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static int	philo_try_to_take_forks(t_philo *philo, int i_left, int i_right);

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
	if (philo_try_to_take_forks(philo, i_left_fork, i_right_fork) == SUCCESS)
		return (SUCCESS);
	else
		return (FAILED);
}

static int	philo_try_to_take_forks(t_philo *philo, int i_left, int i_right)
{
	pthread_mutex_lock(&philo->data->forks_mutex[i_left]);
	pthread_mutex_lock(&philo->data->forks_mutex[i_right]);
	if (philo->data->forks[i_left] == AVAILABLE
		&& philo->data->forks[i_right] == AVAILABLE)
	{
		philo->data->forks[i_left] = BUSY;
		philo->data->forks[i_right] = BUSY;
		ft_print(philo, TAKE_FORK);
		ft_print(philo, TAKE_FORK);
		return (SUCCESS);
	}
	else
	{
		philo->data->forks[i_left] = AVAILABLE;
		philo->data->forks[i_right] = AVAILABLE;
		pthread_mutex_unlock(&philo->data->forks_mutex[i_left]);
		pthread_mutex_unlock(&philo->data->forks_mutex[i_right]);
		return (FAILED);
	}
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
