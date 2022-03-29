/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:16:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/29 19:38:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	main(int ac, char **av)
{
	t_args	args;
	t_philo	*philo;

	(void)philo;
	(void)args;
	if (check_args(ac, av) == -1)
		return (0);
	get_args(av, &args);
}

// pthread_mutex_init(&args->am_i_alive, NULL);
// args->start_time = get_ts();
// args->death_event = 0;
