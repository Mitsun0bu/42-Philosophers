/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_initializer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:19:55 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 09:43:22 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

static int	ft_isdigit(int c);

int	check_n_args(int ac)
{
	if (ac < 5 || ac > 6)
	{
		printf("Error: Please enter a valid number of arguments !\n");
		return (-1);
	}
	return (0);
}

int	check_arg_is_nbr(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]) || av[1][0] == '0')
			{
				printf("Error: All arguments should be (positive) numbers !\n");
				return (-1);
			}
		}
	}
	return (0);
}

int	check_arg_overflow(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atoi(av[i]) == -1)
		{
			printf("Error: Overflow ! Argument should be an int.\n");
			return (-1);
		}
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		if (nbr > 2147483647 || nbr < 0)
			return (-1);
		nbr = nbr * 10;
		nbr = nbr + str[i] - '0';
		i++;
	}
	return (nbr);
}

static int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}
