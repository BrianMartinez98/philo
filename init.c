/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:36:56 by brimarti          #+#    #+#             */
/*   Updated: 2025/12/02 15:36:57 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (handle_error("Failed to initialize mutex fork"), 0);
		i++;
	}
	if (pthread_mutex_init(&data->write_mutex, NULL) != 0)
		return (handle_error("Failed to initialize mutex write"), 0);
	if (pthread_mutex_init(&data->sim_mutex, NULL) != 0)
		return (handle_error("Failed to initialize mutex"), 0);
	return (1);
}

static void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].data = data;
		data->philos[i].meals_eating = 0;
		data->philos[i].last_meal_time = data->start_time;
		data->philos[i].left_fork = &data->forks[i];
		if (i == data->num_philos - 1)
			data->philos[i].right_fork = &data->forks[0];
		else
			data->philos[i].right_fork = &data->forks[i + 1];
		i++;
	}
}

int	init(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
		return (handle_error("Malloc failed for philosophers"), 0);
	memset(data->philos, 0, sizeof(t_philo) * data->num_philos);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (free(data->philos), handle_error("Malloc failed for forks"),
			0);
	if (!init_mutex(data))
	{
		free(data->philos);
		free(data->forks);
		return (0);
	}
	data->start_time = get_current_time();
	init_philos(data);
	return (1);
}
