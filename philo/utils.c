/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:12:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/25 10:01:52 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_ts(void)
{
	struct timeval	ts;
	long			ms_ts;

	gettimeofday(&ts, NULL);
	ms_ts = (ts.tv_sec * 1000) + (ts.tv_usec / 1000);
	return (ms_ts);
}

void	ft_usleep(long time, int action_duration, long dinner_start)
{
	long	time_to_stop;

	time_to_stop = time + action_duration;
	usleep(action_duration * 0.80 * 1000);
	while ((get_ts() - dinner_start) < time_to_stop)
		usleep(500);
}

void	ft_print(t_philo *philo, long time, int action)
{
	pthread_mutex_lock(&philo->data->death);
	if (philo->data->death_event == NO)
	{
		if (action == DIE)
		{
			printf("\033[0;35m[%lu\tms]\033[0m Philo #%d died !\n",
				time, philo->id);
		}
		else if (action == TAKE)
		{
			printf("\033[0;35m[%lu\tms]\033[0m Philo #%d has taken a fork !\n",
				time, philo->id);
		}
		else if (action == SLEEP)
		{
			printf("\033[0;36m[%lu\tms]\033[0m Philo #%d is sleeping !\n",
				time, philo->id);
		}
		else if (action == THINK)
		{
			printf("\033[0;32m[%lu\tms]\033[0m Philo #%d is thinking !\n",
				time, philo->id);
		}
	}
	pthread_mutex_unlock(&philo->data->death);
}