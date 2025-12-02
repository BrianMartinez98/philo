#include "philo.h"

static int	has_philo_died(t_philo *philo)
{
	long	current_time;
	int		died;

	died = 0;
	pthread_mutex_lock(&philo->data->sim_mutex);
	current_time = get_current_time();
	if (current_time - philo->last_meal_time >= philo->data->time_to_die
		&& !philo->data->simulation_should_end)
	{
		philo->data->simulation_should_end = 1;
		died = 1;
	}
	pthread_mutex_unlock(&philo->data->sim_mutex);
	if (died)
	{
		print_status(philo, "died", 1);
		return (1);
	}
	return (0);
}

static int	all_eaten(t_data *data)
{
	int	i;
	int	all_full;

	all_full = 1;
	if (data->num_meals_to_eat == -1)
		return (0);
	pthread_mutex_lock(&data->sim_mutex);
	i = 0;
	while (i < data->num_philos)
	{
		if (data->philos[i].meals_eating < data->num_meals_to_eat)
		{
			all_full = 0;
			break ;
		}
		i++;
	}
	if (all_full)
		data->simulation_should_end = 1;
	pthread_mutex_unlock(&data->sim_mutex);
	return (all_full);
}

static int	check_death_and_meals(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philos)
	{
		if (has_philo_died(&data->philos[i]))
			return (1);
		i++;
	}
	if (all_eaten(data))
		return (1);
	return (0);
}

void	*monitoring(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	usleep(data->time_to_die / 2 * 1000);
	while (1)
	{
		if (check_death_and_meals(data))
			break ;
		usleep(1000);
	}
	return (NULL);
}
