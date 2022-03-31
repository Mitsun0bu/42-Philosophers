/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:52:38 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/31 19:06:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_take_forks(t_philo *philo)
{
	int		i;
	long	time;

	i = philo->id - 1;
	printf("Philo #%d is waiting for a fork !\n", philo->id);
	pthread_mutex_lock(&philo->data.forks[i]);
	if (philo->id < philo->data.n_philo)
		pthread_mutex_lock(&philo->data.forks[i + 1]);
	else if (i == philo->data.n_philo)
		pthread_mutex_lock(&philo->data.forks[0]);
	pthread_mutex_lock(&philo->data.message_lock);
	time = get_ts() - philo->data.dinner_start_time;
	printf("\033[0;35m[%lu\tms]\033[0m", time);
	printf("Philo #%d is holding forks\n", philo->id);
	pthread_mutex_unlock(&philo->data.message_lock);
}

void	philo_eat(t_philo *philo)
{


}

void	philo_sleep(t_philo *philo)
{


}

void	philo_think(t_philo *philo)
{



}