/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:13:35 by mkadri            #+#    #+#             */
/*   Updated: 2024/08/08 18:49:34 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void destroy_all_mutex(char *str, t_program *program, pthread_mutex_t *forks)
{
	int	i;
	
	i = 0;
	if (str)
		printf("%s \n", str);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (i < program->philos[0].philo_count)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

size_t	current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "error with gettimeofday() function\n", 36);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	check_dead_lock(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int custom_usleep(size_t milliseconds)
{
	size_t start;
	
	start = current_time();
	while ((current_time() - start) < milliseconds)
	{
		usleep(500);
	}
	return (0);
}