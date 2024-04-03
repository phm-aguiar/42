/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:48:52 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/02 16:19:00 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	thinking(t_philo *philo)
{
	print_message(philo, philo->id, PINK "is thinking" RESET);
}

static void	sleeping(t_philo *philo)
{
	print_message(philo, philo->id, BLUE "is sleeping" RESET);
	usleep(philo->time_to_sleep * 1000);
}

static void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_message(philo, philo->id, GREEN "has taken a fork" RESET);
	if (philo->num_philos == 1)
	{
		usleep(philo->time_to_die * 1000);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_message(philo, philo->id, GREEN "has taken a fork" RESET);
	philo->eating = 1;
	print_message(philo, philo->id, YELLOW "is eating" RESET);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	usleep(philo->time_to_eat * 1000);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(500);
	while (!dead_loop(philo))
	{
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (arg);
}
