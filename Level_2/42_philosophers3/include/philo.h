/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:29:22 by phenriq2          #+#    #+#             */
/*   Updated: 2024/04/02 13:13:03 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_P 200

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PINK "\033[0;35m"
# define RESET "\033[0m"

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	int				*dead;
	int				max_eat;
	int				num_philos;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_core
{
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}					t_core;

size_t				get_time(void);
int					ft_atoi(const char *str);
int					ft_isnumber(const char *str);
void				init_core(t_core *core, t_philo *philos);
void				init_forks(pthread_mutex_t *forks, int num_philos);
void				init_thread(t_philo *philos);
void				set_argv(t_philo *philos, char **argv);
void				init_philos(t_philo *philos, t_core *core,
						pthread_mutex_t *forks, char **argv);
int					dead_loop(t_philo *philo);
void				print_message(t_philo *philo, int id, char *str);
void				*routine(void *arg);
void				*waiter_routine(void *arg);

#endif

// void				print_philos(t_core *core);