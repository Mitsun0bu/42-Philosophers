/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 19:16:08 by llethuil          #+#    #+#             */
/*   Updated: 2022/04/26 16:41:24 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	if (prepare_philos_for_dinner(ac, av, &data) == FAILED)
		return (FAILED);
	philo_dinner_manager(&data);
	clean_after_dinner(&data);
	return (0);
}
