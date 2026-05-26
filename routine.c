/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:37:11 by brimarti          #+#    #+#             */
/*   Updated: 2025/12/02 15:37:12 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*handle_one_philosopher(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork", 0);
	usleep(philo->data->time_to_die * 1000 + 10000);
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

static void	*philo_loop(t_philo *philo)
{
	if (philo->id % 2 == 0)
		precise_usleep(philo->data->time_to_eat / 2, philo->data);
	while (1)
	{
		pthread_mutex_lock(&philo->data->sim_mutex);
		if (philo->data->simulation_should_end)
		{
			pthread_mutex_unlock(&philo->data->sim_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->data->sim_mutex);
		eat_philo(philo);
		sleep_philo(philo);
		think(philo);
	}
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->num_philos == 1)
		return (handle_one_philosopher(philo));
	else
		return (philo_loop(philo));
}

int	thread_creation(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	i = 0;
	while (i < data->num_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &routine,
				&data->philos[i]) != 0)
			return (handle_error("Failed to create the thread for philo"), 0);
		i++;
	}
	if (pthread_create(&monitor_thread, NULL, &monitoring, data) != 0)
		return (handle_error("Failure to create monitor thread"), 0);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
	pthread_join(monitor_thread, NULL);
	return (1);
}
