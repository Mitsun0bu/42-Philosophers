/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_data_after_dinner.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:30:26 by llethuil          #+#    #+#             */
/*   Updated: 2022/03/30 18:43:34 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include	"philo.h"

void	clean_data_after_dinner(t_data *data)
{
	destroy_mutex(data);
	free(data->philos);
	free(data->forks);
}
