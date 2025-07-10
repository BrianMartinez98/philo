#include "philosophers.h"

static void	fork_assignation(t_data data)
{
	int	i;

	i = 0;
	while (i < data->arguments)
	{
		data->table->philos[i]->right_fork = data->table->forks[i];
		if (i == 0)
			data->table->philos[i]->left_fork = data->table->forks[data->arguments - 1];
		else
			data->table->philos[i]->left_fork = data->table->forks[i - 1];
		i++;
	}
}

static void	**create_array(t_data data, size_t size)
{
	void	**array;
	int		i;

	i = 0;
	array = ft_calloc(data->arguments[0], sizeof(void *))
	if (!array)
			handle_error(MALLOCERROR);
	while (i < data->arguments[0])
	{
		array[i] = ft_calloc(1, size);
		if (!array[i])
			handle_error(MALLOCERROR);
		i++;
	}
	return (array);
}

void	init(t_data *data, char **argv)
{
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		handle_error(MALLOCERROR);
	data->arg = argv;
	parser(data);
	data->table = ft_calloc(1, sizeof(t_table));
	if (!data->table)
		handle_error(MALLOCERROR);
	data->table->philos = create_array(data, data->table->philo);
	data->table->forks = create_array(data, data->table->fork);
	fork_assignation(data);
}