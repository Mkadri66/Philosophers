/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:59:13 by mkadri            #+#    #+#             */
/*   Updated: 2024/07/11 19:40:14 by mkadri           ###   ########.fr       */
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

int	parsing_args(char **argv);
int	ft_atoi(char *str);

#endif
