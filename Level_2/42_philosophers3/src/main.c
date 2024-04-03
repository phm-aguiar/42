/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:36:30 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/02 15:22:29 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	input_tratament(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isnumber(argv[i]))
		{
			printf("Error: argument %d is not a number\n", i);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	param_tratament(char **argv)
{
	if (ft_atoi(argv[2]) < 60)
	{
		printf("Error: time to die must be at least 60ms\n");
		return (0);
	}
	if (ft_atoi(argv[3]) < 60)
	{
		printf("Error: time to eat must be at least 60ms\n");
		return (0);
	}
	if (ft_atoi(argv[4]) < 60)
	{
		printf("Error: time to sleep must be at least 60ms\n");
		return (0);
	}
	if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 200)
	{
		printf("Error: number of philosophers must be between 1 and 200\n");
		return (0);
	}
	return (1);
}

static void	destroy_mutex(pthread_mutex_t *forks, t_core *core, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	pthread_mutex_destroy(&core->write_lock);
	pthread_mutex_destroy(&core->dead_lock);
	pthread_mutex_destroy(&core->meal_lock);
}

int	main(int argc, char **argv)
{
	pthread_mutex_t	forks[MAX_P];
	t_philo			philos[MAX_P];
	t_core			core;

	if (argc != 5 && argc != 6)
	{
		printf("Error: wrong number of arguments\n");
		return (1);
	}
	if (!input_tratament(argv) || !param_tratament(argv))
		return (1);
	init_core(&core, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(philos, &core, forks, argv);
	init_thread(philos);
	destroy_mutex(forks, &core, ft_atoi(argv[1]));
	return (0);
}
