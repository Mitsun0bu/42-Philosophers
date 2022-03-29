/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:19:55 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/29 19:40:49 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	check_args(int ac, char **av)
{
	if (check_n_args(ac) == -1)
		return (-1);
	if (check_arg_is_nbr(ac, av) == -1)
		return (-1);
	if (check_arg_overflow(ac, av) == -1)
		return (-1);
	return (0);
}

int	check_n_args(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error. Please enter a valid number of arguments !\n");
		return (-1);
	}
	return (0);
}

int	check_arg_is_nbr(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
			{
				printf("Error. All arguments should be (positive) numbers !\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_arg_overflow(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) == -1)
		{
			printf("Error. Overflow ! Argument should be an int.\n");
			return (-1);
		}
	i ++;
	}
	return (0);
}
