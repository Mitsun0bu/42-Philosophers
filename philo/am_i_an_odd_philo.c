/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   am_i_an_odd_philo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:27:53 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/26 21:39:23 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	am_i_an_odd_philo(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(100);
	else
		return ;
}