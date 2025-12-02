#include "philo.h"

static void	cleanup(t_data *data)
{
	int	i;

	if (!data)
		return ;
	i = 0;
	while (i < data->num_philos && data->forks)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->write_mutex);
	pthread_mutex_destroy(&data->sim_mutex);
	if (data->philos)
		free(data->philos);
	if (data->forks)
		free(data->forks);
}

int	main(int argc, char **argv)
{
	t_data	data;

	memset(&data, 0, sizeof(t_data));
	if (!parse_args(&data, argc, argv))
		return (1);
	if (!init(&data))
	{
		cleanup(&data);
		return (1);
	}
	if (!thread_creation(&data))
	{
		cleanup(&data);
		return (1);
	}
	cleanup(&data);
	return (0);
}
