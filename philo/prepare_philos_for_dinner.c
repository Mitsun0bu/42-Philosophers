/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_philos_for_dinner.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:37:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/04 19:17:24 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	prepare_philos_for_dinner(int ac, char **av, t_data *data)
{
	if (check_args(ac, av) == FAILED)
		return (FAILED);
	get_args(av, data);
	if (init_other_data(data) == FAILED)
		return (FAILED);
	if (init_philos(data) == FAILED)
		return (FAILED);
	return (0);
}

void	get_args(char **av, t_data *data)
{
	data->n_philos = ft_atoi(av[1]);
	data->n_forks = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->n_time_must_eat = ft_atoi(av[5]);
	else
		data->n_time_must_eat = -1;
}

int	init_other_data(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = 0;
	pthread_mutex_init(&data->time, NULL);
	data->death_event = NO;
	pthread_mutex_init(&data->death, NULL);
	data->forks = malloc(sizeof(pthread_mutex_t) * (data->n_forks));
	if (!data->forks)
	{
		printf("Error : Malloc of forks failed !");
		return (FAILED);
	}
	while (++i < data->n_forks)
		pthread_mutex_init(&data->forks[i], NULL);
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * (data->n_philos));
	if (!data->philos)
	{
		printf("Error : Malloc of philos failed !");
		return (FAILED);
	}
	i = -1;
	while (++i < data->n_philos)
	{
		data->philos[i].id = i + 1;
		pthread_mutex_init(&data->philos[i].odd_id, NULL);
		data->philos[i].meal_count = 0;
		pthread_mutex_init(&data->philos[i].meal, NULL);
		data->philos[i].last_meal_ts = 0;
		data->philos[i].leave_dinner = NO;
		pthread_mutex_init(&data->philos[i].presence, NULL);
		pthread_mutex_init(&data->philos[i].print, NULL);
		data->philos[i].thread = 0;
		data->philos[i].data = data;
	}
	return (0);
}
