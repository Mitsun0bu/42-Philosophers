/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_before_dinner.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:37:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/30 18:42:53 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	init_data_before_dinner(int ac, char **av, t_data *data)
{
	if (check_args(ac, av) == FAILED)
		return (FAILED);
	get_args(av, data);
	if (init_philos(data) == FAILED)
		return (FAILED);
	if (init_forks(data) == FAILED)
		return (FAILED);
	init_rest_of_data(data);
	if (!data->forks)
		return (FAILED);
	return (0);
}

void	get_args(char **av, t_data *data)
{
	data->n_philo = ft_atoi(av[1]);
	data->n_fork = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->n_time_must_eat = ft_atoi(av[5]);
	else
		data->n_time_must_eat = -1;
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * (data->n_philo));
	if (!data->philos)
	{
		printf("Error : Malloc of philos failed !");
		return (FAILED);
	}
	i = -1;
	while (++i < data->n_philo)
	{
		data->philos[i].id = i + 1;
		pthread_mutex_init(&data->philos[i].eat_count, NULL);
		data->philos[i].last_meal_ts = 0;
		data->philos[i].thread = 0;
	}
	return (0);
}

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(t_fork) * (data->n_fork));
	if (!data->forks)
	{
		printf("Error : Malloc of forks failed !");
		return (FAILED);
	}
	i = -1;
	while (++i < data->n_fork)
	{
		data->forks[i].id = i + 1;
		pthread_mutex_init(&data->forks[i].lock, NULL);
	}
	return (0);
}

int	init_rest_of_data(t_data *data)
{
	data->dinner_start_time = 0;
	data->dinner_can_start = FALSE;
	pthread_mutex_init(&data->dinner_start_lock, NULL);
	data->death_event = FALSE;
	pthread_mutex_init(&data->death_event_lock, NULL);
	return (0);
}
