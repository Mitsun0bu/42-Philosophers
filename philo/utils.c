/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 15:12:19 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/22 18:32:36 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

int	ft_atoi(char *str)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		if (nbr > 2147483647 || nbr < 0)
			return (-1);
		nbr = nbr * 10;
		nbr = nbr + str[i] - '0';
		i++;
	}
	return (nbr);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}

long	get_ts(void)
{
	struct timeval	ts;
	long			ms_ts;

	gettimeofday(&ts, NULL);
	ms_ts = (ts.tv_sec * 1000) + (ts.tv_usec / 1000);
	return (ms_ts);
}

void	my_usleep(long time, int action_duration, long dinner_start)
{
	long	time_to_stop;

	time_to_stop = time + action_duration;
	usleep(action_duration * 0.80 * 1000);
	while ((get_ts() - dinner_start) < time_to_stop)
		usleep(500);
}

void	ft_print(t_philo *philo, long time)
{
	pthread_mutex_lock(&philo->data->death);
	if (philo->data->death_event == NO)
	{
		printf("\033[0;35m[%lu\tms]\033[0m Philo #%d died !\n", time, philo->id);
		philo->data->death_event = YES;
	}
	pthread_mutex_unlock(&philo->data->death);

}