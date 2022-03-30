/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:16:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/30 18:42:23 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	if (init_data_before_dinner(ac, av, &data) == FAILED)
		return (FAILED);
	philo_dinner(&data);
	clean_data_after_dinner(&data);
	return (0);
}

	// pthread_mutex_init(&args->am_i_alive, NULL);
	// args->start_time = get_ts();
	// args->death_event = 0;

	// printf("========== TEST GET_ARGS ==========\n");
	// printf("n_philo = %d\n", data.n_philo);
	// printf("n_fork = %d\n", data.n_fork);
	// printf("time_to_die = %d\n", data.time_to_die);
	// printf("time_to_eat = %d\n", data.time_to_eat);
	// printf("time_to_sleep = %d\n", data.time_to_sleep);
	// printf("n_time_must_eat = %d\n", data.n_time_must_eat);
	// printf("===================================\n");
	// printf("======= TEST INIT_PHILO_TAB =======\n");
	// int	i = -1;
	// while (++i < data.n_philo)
	// 	printf("Hello, I am philo %d\n", data.philos[i].id);
	// printf("===================================\n");