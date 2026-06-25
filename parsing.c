/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbenmou <isbenmou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:46:17 by isbenmou          #+#    #+#             */
/*   Updated: 2026/06/25 12:00:50 by isbenmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Codexion.h"

long	ft_atoi_long(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i++] - '0');
		if (res * sign < -2147483648 || res * sign > 2147483647)
			return (2147483648);
	}
	if (str[i] != '\0')
		return (2147483648);
	return (res * sign);
}

int parser(t_data *data, char **av)
{
	if (ft_atoi_long(av[1]) == 2147483648)
		printf("4alate ajmi :(\nline av[1]");
	else if (ft_atoi_long(av[2]) == 2147483648)
		printf("4alate ajmi :(\nline av[2]");
	else if (ft_atoi_long(av[3]) == 2147483648)
		printf("4alate ajmi :(\nline av[3]");
	else if (ft_atoi_long(av[4]) == 2147483648)
		printf("4alate ajmi :(\nline av[4]");
	else if (ft_atoi_long(av[5]) == 2147483648)
		printf("4alate ajmi :(\nline av[5]");
	else if (ft_atoi_long(av[6]) == 2147483648)
		printf("4alate ajmi :(\nline av[6]");
	else if (ft_atoi_long(av[7]) == 2147483648)
		printf("4alate ajmi :(\nline av[7]");
	else if (strcmp(av[8], "fifo") != 0
		&& strcmp(av[8], "edf") != 0)
		printf("4alate ajmi :(\nline av[8]");
	else
		return (init(data, av), 0);
	return 1;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 9)
		return (printf("3adade dyale arguments 4alate ajmi :("), 1);
	if (parser(&data, av) == 1)
		return 1;
	t_coders *coders = malloc(sizeof(t_coders) * data.number_of_coders);
	t_dongels *dongels = malloc(sizeof(t_dongels) * data.number_of_coders);
	if (dongels == NULL)
		return (free(coders), 1);
	int i = 0;
	while (i < data.number_of_coders)
	{
		coders[i].counter = 0;
		coders[i].left = &dongels[i];
		coders[i].right = &dongels[((i+1) % data.number_of_coders)];
		i++;
	}
}
