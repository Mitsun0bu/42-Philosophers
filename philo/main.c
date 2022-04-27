/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:16:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/27 09:36:35 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	if (philo_dinner_initializer(ac, av, &data) == FAILED)
		return (FAILED);
	if (philo_dinner_launcher(&data) == SUCCESS)
	{
		philo_dinner_supervisor(&data);
		philo_dinner_ender(&data);
	}
	philo_dinner_cleaner(&data);
	return (0);
}
