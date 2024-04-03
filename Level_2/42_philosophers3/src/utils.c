/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:37:27 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/02 12:02:41 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

int	ft_isnumber(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

// void	print_philos(t_core *core)
// {
// 	int	i;

// 	i = 0;
// 	while (i < core->philos[0].num_philos)
// 	{
// 		printf("========================================\n");
// 		printf("Philosopher %d\n", core->philos[i].id);
// 		printf("Eating: %d\n", core->philos[i].eating);
// 		printf("Meals eaten: %d\n", core->philos[i].meals_eaten);
// 		printf("Last meal: %zu\n", core->philos[i].last_meal);
// 		printf("Time to die: %zu\n", core->philos[i].time_to_die);
// 		printf("Time to eat: %zu\n", core->philos[i].time_to_eat);
// 		printf("Time to sleep: %zu\n", core->philos[i].time_to_sleep);
// 		printf("Start time: %zu\n", core->philos[i].start_time);
// 		printf("Max eat: %d\n", core->philos[i].max_eat);
// 		printf("Dead: %d\n", *core->philos[i].dead);
// 		printf("Right fork: %p\n", core->philos[i].r_fork);
// 		printf("Left fork: %p\n", core->philos[i].l_fork);
// 		printf("Write lock: %p\n", core->philos[i].write_lock);
// 		printf("Dead lock: %p\n", core->philos[i].dead_lock);
// 		printf("Meal lock: %p\n", core->philos[i].meal_lock);
// 		i++;
// 	}
// }

void	print_message(t_philo *philo, int id, char *str)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}
