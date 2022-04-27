/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_dinner_initializer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:37:44 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 09:09:19 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static int	check_args(int ac, char **av);
static void	init_data_struct_args(char **av, t_data *data);
static int	init_data_struct_var_and_mutex(t_data *data);
static int	init_philos(t_data *data);

int	philo_dinner_initializer(int ac, char **av, t_data *data)
{
	if (check_args(ac, av) == FAILED)
		return (FAILED);
	init_data_struct_args(av, data);
	if (init_data_struct_var_and_mutex(data) == FAILED)
		return (FAILED);
	if (init_philos(data) == FAILED)
		return (FAILED);
	return (0);
}

static int	check_args(int ac, char **av)
{
	if (check_n_args(ac) == FAILED)
		return (FAILED);
	if (check_arg_is_nbr(ac, av) == FAILED)
		return (FAILED);
	if (check_arg_overflow(ac, av) == FAILED)
		return (FAILED);
	return (0);
}

static void	init_data_struct_args(char **av, t_data *data)
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

static int	init_data_struct_var_and_mutex(t_data *data)
{
	int	i;

	i = -1;
	data->start_time = 0;
	data->death_event = NO;
	data->forks = ft_calloc(sizeof(int), data->n_forks);
	if (!data->forks)
	{
		printf("Error : Malloc of forks failed !");
		return (FAILED);
	}
	pthread_mutex_init(&data->death_mutex, NULL);
	data->forks_mutex = malloc(sizeof(pthread_mutex_t) * (data->n_forks));
	if (!data->forks_mutex)
	{
		printf("Error : Malloc of forks_mutex failed !");
		return (FAILED);
	}
	while (++i < data->n_forks)
		pthread_mutex_init(&data->forks_mutex[i], NULL);
	return (0);
}

static int	init_philos(t_data *data)
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
		data->philos[i].id = i;
		data->philos[i].meal_count = 0;
		pthread_mutex_init(&data->philos[i].meal_count_mutex, NULL);
		data->philos[i].last_meal_ts = 0;
		data->philos[i].thread = 0;
		data->philos[i].data = data;
	}
	return (0);
}
