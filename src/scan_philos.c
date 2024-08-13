/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 12:48:03 by mkadri            #+#    #+#             */
/*   Updated: 2024/08/08 18:47:04 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	philo_is_dead(t_philo *philo, size_t time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if ((current_time() - philo->last_meal) >= time_to_die
		&& philo->eating == 0)
		return (pthread_mutex_unlock(philo->meal_lock), 1);
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	if_are_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].philo_count)
	{
		if (philo_is_dead(&philos[i], philos[i].time_to_die))
		{
			print_message("died", &philos[i], philos[i].philo_id);
			pthread_mutex_lock(philos[0].dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	everyone_ate(t_philo *philos)
{
	int	i;
	int	finish_eat;

	i = 0;
	finish_eat = 0;
	if (philos[0].number_of_times_each_philosopher_must_eat == -1)
		return (0);
	while (i < philos[0].philo_count)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten
			>= philos[i].number_of_times_each_philosopher_must_eat)
			finish_eat++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (finish_eat == philos[0].philo_count)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*scan_philos(void *pointer)
{
	t_philo	*philos;

	philos = (t_philo *) pointer;
	while (1)
		if (if_are_dead(philos) == 1 || everyone_ate(philos) == 1)
			break ;
	return (pointer);
}

void	print_message(char *str, t_philo *philo, int philo_id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = current_time() - philo->start_time;
	if (!check_dead_lock(philo))
		printf("%zu %d %s\n", time, philo_id, str);
	pthread_mutex_unlock(philo->write_lock);
}
