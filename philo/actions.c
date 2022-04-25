/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:52:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/25 09:31:57 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_take_forks(t_philo *philo)
{
	int		i;
	long	time;

	i = philo->id - 1;

	time = get_ts() - philo->data->start_time;
	pthread_mutex_lock(&philo->data->forks[i]);
	ft_print(philo, time, TAKE);
	if (philo->data->n_forks == 1)
		usleep(philo->data->time_to_die * 5);
	if (should_i_stop(philo) == NO)
	{
		if (i < philo->data->n_philos)
			pthread_mutex_lock(&philo->data->forks[i + 1]);
		else if (i == philo->data->n_philos)
			pthread_mutex_lock(&philo->data->forks[0]);
		ft_print(philo, time, TAKE);
		philo->n_fork_held = 2;
	}
}

void	philo_eat(t_philo *philo)
{
	int		i;
	long	time;

	i = philo->id - 1;
	time = get_ts() - philo->data->start_time;
	philo->last_meal_ts = time;
	if (should_i_stop(philo) == NO && philo->n_fork_held == 2)
		ft_print(philo, time, EAT);
	ft_usleep(time, philo->data->time_to_eat, philo->data->start_time);
	pthread_mutex_lock(&philo->meal);
	philo->meal_count ++;
	pthread_mutex_unlock(&philo->meal);
}

void	philo_drop_forks(t_philo *philo)
{
	int	i;

	i = philo->id - 1;
	pthread_mutex_unlock(&philo->data->forks[i]);
	if (philo->id < philo->data->n_philos)
		pthread_mutex_unlock(&philo->data->forks[i + 1]);
	else if (i == philo->data->n_philos)
		pthread_mutex_unlock(&philo->data->forks[0]);
	philo->n_fork_held = 0;
}

void	philo_sleep(t_philo *philo)
{
	int		i;
	long	time;


	i = philo->id - 1;
	time = get_ts() - philo->data->start_time;
	if (should_i_stop(philo) == NO)
		ft_print(philo, time, SLEEP);
	ft_usleep(time, philo->data->time_to_sleep, philo->data->start_time);
}

void	philo_think(t_philo *philo)
{
	int		i;
	long	time;

	i = philo->id - 1;
	time = get_ts() - philo->data->start_time;
	if (should_i_stop(philo) == NO)
		ft_print(philo, time, THINK);
}
