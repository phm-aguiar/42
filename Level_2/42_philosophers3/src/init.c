/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:15:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/02 13:12:44 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_core(t_core *core, t_philo *philos)
{
	core->dead_flag = 0;
	core->philos = philos;
	pthread_mutex_init(&core->write_lock, NULL);
	pthread_mutex_init(&core->dead_lock, NULL);
	pthread_mutex_init(&core->meal_lock, NULL);
}

void	init_forks(pthread_mutex_t *forks, int num_philos)
{
	int	i;

	i = 0;
	while (i < num_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	set_argv(t_philo *philos, char **argv)
{
	philos->num_philos = ft_atoi(argv[1]);
	philos->time_to_die = ft_atoi(argv[2]);
	philos->time_to_eat = ft_atoi(argv[3]);
	philos->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philos->max_eat = ft_atoi(argv[5]);
	else
		philos->max_eat = -1;
}

void	init_philos(t_philo *philos, t_core *core, pthread_mutex_t *forks,
		char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i + 1;
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		set_argv(&philos[i], argv);
		philos[i].last_meal = get_time();
		philos[i].start_time = get_time();
		philos[i].write_lock = &core->write_lock;
		philos[i].dead_lock = &core->dead_lock;
		philos[i].meal_lock = &core->meal_lock;
		philos[i].dead = &core->dead_flag;
		philos[i].l_fork = &forks[i];
		if (i == 0)
			philos[i].r_fork = &forks[philos[i].num_philos - i];
		else
			philos[i].r_fork = &forks[i - 1];
		i++;
	}
}

void	init_thread(t_philo *philos)
{
	int			i;
	pthread_t	waiter;

	i = 0;
	pthread_create(&waiter, NULL, &waiter_routine, philos);
	(void)waiter;
	while (i < philos[0].num_philos)
	{
		pthread_create(&philos[i].thread, NULL, &routine, &philos[i]);
		i++;
	}
	pthread_join(waiter, NULL);
	i = 0;
	while (i < philos[0].num_philos)
	{
		pthread_join(philos[i].thread, NULL);
		i++;
	}
}
