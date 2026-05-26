/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:36:48 by brimarti          #+#    #+#             */
/*   Updated: 2025/12/02 15:36:49 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

static void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork", 0);
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork", 0);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork", 0);
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork", 0);
	}
}

void	eat_philo(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(&philo->data->sim_mutex);
	philo->last_meal_time = get_current_time();
	philo->meals_eating++;
	pthread_mutex_unlock(&philo->data->sim_mutex);
	print_status(philo, "is eating", 0);
	precise_usleep(philo->data->time_to_eat, philo->data);
	release_forks(philo);
}

void	sleep_philo(t_philo *philo)
{
	print_status(philo, "is sleeping", 0);
	precise_usleep(philo->data->time_to_sleep, philo->data);
}

void	think(t_philo *philo)
{
	print_status(philo, "is thinking", 0);
	usleep(1000);
}
