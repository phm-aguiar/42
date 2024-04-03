/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:26:03 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/02 16:49:20 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_time() - philo->last_meal >= philo->time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

static int	check_death(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[i].num_philos)
	{
		if (philo_dead(&philos[i]))
		{
			print_message(&philos[i], philos[i].id, RED"died"RESET);
			pthread_mutex_lock(philos[i].dead_lock);
			*philos[i].dead = 1;
			pthread_mutex_unlock(philos[i].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_all_full(t_philo *philo)
{
	int	i;
	int	philos_full;

	i = 0;
	philos_full = 0;
	if (philo->max_eat == -1)
		return (0);
	while (i < philo->num_philos)
	{
		pthread_mutex_lock(philo[i].meal_lock);
		if (philo[i].meals_eaten >= philo->max_eat)
			philos_full++;
		pthread_mutex_unlock(philo[i].meal_lock);
		i++;
	}
	if (philos_full == philo->num_philos)
	{
		pthread_mutex_lock(philo->dead_lock);
		*philo->dead = 1;
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	return (0);
}

void	*waiter_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_death(philo) || check_all_full(philo))
			return (arg);
	}
	return (arg);
}
