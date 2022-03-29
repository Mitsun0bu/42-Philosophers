/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:21:16 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/29 19:40:54 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	ft_atoi(char *str)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	while (str[i] && '0' <= str[i] && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + str[i] - '0';
		i++;
	}
	if (nbr > INT_MAX)
		return (-1);
	return (nbr);
}

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	else
		return (0);
}
