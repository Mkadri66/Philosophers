/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:59:13 by mkadri            #+#    #+#             */
/*   Updated: 2024/08/08 17:09:27 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <sys/wait.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define PHILO_MAX 200

typedef struct s_philo
{
	pthread_t		thread;
	int				philo_id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_eat;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			start_time;
	int				philo_count;
	int				number_of_times_each_philosopher_must_eat;
	int				*dead;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}	t_philo;

typedef struct s_program
{
	int				dead_flg;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philos;
}	t_program;

// Utils

int		parsing_args(char **argv);
int		ft_atoi(char *str);
size_t	current_time(void);
void	print_message(char *str, t_philo *philo, int philo_id);
int		custom_usleep(size_t milliseconds);

// Init 

void	init_program(t_program *program, t_philo *philos);
void	init_forks(pthread_mutex_t *forks, int philo_count);
void	init_philos(t_philo *philos, t_program *program,
			pthread_mutex_t *forks, char **argv);

// Threads

int		create_threads(t_program *program, pthread_mutex_t *forks);
void	*scan_philos(void *pointer);
int		check_dead_lock(t_philo *philo);
void	*philo_routine(void *pointer);
void	destroy_all_mutex(char *str, t_program *program,
			pthread_mutex_t *forks);

#endif
