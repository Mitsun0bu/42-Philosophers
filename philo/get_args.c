/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:37:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/29 19:38:50 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	get_args(char **av, t_args *args)
{
	args->n_philo = ft_atoi(av[1]);
	args->time_to_die = ft_atoi(av[2]);
	args->time_to_eat = ft_atoi(av[3]);
	args->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		args->n_time_must_eat = ft_atoi(av[5]);
	else
		args->n_time_must_eat = -1;
	return ;
}
