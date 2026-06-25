/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbenmou <isbenmou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 03:16:27 by isbenmou          #+#    #+#             */
/*   Updated: 2026/06/24 03:17:47 by isbenmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Codexion.h"

void	init(t_data *data, char **av)
{
	data->number_of_coders = ft_atoi_long(av[1]);
	data->time_to_burnout = ft_atoi_long(av[2]);
	data->time_to_compile = ft_atoi_long(av[3]);
	data->time_to_debug = ft_atoi_long(av[4]);
	data->time_to_refactor = ft_atoi_long(av[5]);
	data->number_of_compiles_required = ft_atoi_long(av[6]);
	data->dongle_cooldown = ft_atoi_long(av[7]);
	data->scheduler = av[8];
}
