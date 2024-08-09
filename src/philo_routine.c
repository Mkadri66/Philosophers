/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:43:52 by mkadri            #+#    #+#             */
/*   Updated: 2024/08/08 17:35:35 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	dream(t_philo *philo)
{
	print_message("is sleeping",philo, philo->philo_id);
	custom_usleep(philo->time_to_sleep);
}

void	think(t_philo *philo)
{
	print_message("is thinking",philo, philo->philo_id);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo, philo->philo_id);
	if (philo->philo_count == 1)
	{
		custom_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo, philo->philo_id);
	philo->eating = 1;
	print_message("is eating", philo, philo->philo_id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	custom_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;
	
	philo = (t_philo *) pointer;
	if (philo->philo_id % 2 == 0)
		custom_usleep(1);
	while (!check_dead_lock(philo))
	{
		eat(philo);
		dream(philo);
		think(philo);
	}
	return (pointer);
}