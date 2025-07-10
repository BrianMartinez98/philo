#include "philosophers.h"

static int	ft_atoi(const char *str)
{
	int	i;
	int	j;
	int	result;
	int	sign;

	i = 0;
	j = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	parser(t_data data, char** argv[])
{
    int i;

    i = 1;
	if (argc == 4)
	{
		while(argv[1][i++])
			data->arguments = ft_atoi(split(argv[1][i], ' '));
	}
	if (argc == 5)
	{
		while(argv[1][i++])
			data->arguments = ft_atoi(split(argv[1][i], ' '));
	}
	else
		handle_error(PARAMETROS);
}