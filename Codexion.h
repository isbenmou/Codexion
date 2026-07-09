/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Codexion.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isbenmou <isbenmou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 22:44:44 by isbenmou          #+#    #+#             */
/*   Updated: 2026/07/06 11:31:44 by isbenmou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CODEXION_H
# define CODEXION_H

# include <string.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_data
{
	int		number_of_coders;
	int		time_to_burnout;
	int		time_to_compile;
	int		time_to_debug;
	int		time_to_refactor;
	int		number_of_compiles_required;
	int		dongle_cooldown;
	char	*scheduler;
}	t_data;

typedef struct s_dongels
{
	pthread_t		id;
}	t_dongels;

typedef struct s_coders
{
	pthread_t	t;
	int id;
	int			counter;
	t_dongels	*left;
	t_dongels	*right;
}	t_coders;

long	ft_atoi_long(char *str);
void	init(t_data *data, char **av);
unsigned long long getmsseccond(void);
unsigned long long get_albased_time(unsigned long long start);
unsigned long long mssleep(unsigned long long sleeping);
char check_time(unsigned long long start_timing, unsigned long long time);
void create_threads(t_data data);
void *routine(void *tmp);

#endif
