/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:23:41 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/26 16:57:19 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	philo_sleep(t_philo *philo)
{
	long	time;

	ft_print(philo, SLEEP);
	time = get_ts() - philo->data->start_time;
	ft_usleep(time, philo->data->time_to_sleep, philo->data->start_time);
}
