/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:16:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/31 14:38:13 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	if (prepare_philos_for_dinner(ac, av, &data) == FAILED)
		return (FAILED);
	philos_dinner(&data);
	clean_after_dinner(&data);
	return (0);
}

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