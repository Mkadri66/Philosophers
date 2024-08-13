/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkadri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:54:18 by mkadri            #+#    #+#             */
/*   Updated: 2024/08/12 16:45:02 by mkadri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

int	main(int argc, char **argv)
{
	t_program			program;
	t_philo				philos[PHILO_MAX];
	pthread_mutex_t		forks[PHILO_MAX];

	if (argc == 5 || argc == 6)
	{
		if (parsing_args(argv) == 1)
			return (1);
		init_program(&program, philos);
		init_forks(forks, ft_atoi(argv[1]));
		init_philos(philos, &program, forks, argv);
		create_threads(&program, forks);
		destroy_all_mutex(NULL, &program, forks);
	}
	else
		write(1, "Invalid number of arguments\n", 28);
}
