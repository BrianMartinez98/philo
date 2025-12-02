#include "philo.h"

long	ft_atol(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	handle_error(char *message)
{
	write(2, "Error: ", 7);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
}

void	print_status(t_philo *philo, const char *status, int force_print)
{
	long	timestam;
	int		sim_ended;

	pthread_mutex_lock(&philo->data->write_mutex);
	timestam = get_time_since(philo->data->start_time);
	pthread_mutex_lock(&philo->data->sim_mutex);
	sim_ended = philo->data->simulation_should_end;
	pthread_mutex_unlock(&philo->data->sim_mutex);
	if (!sim_ended || force_print)
	{
		printf("%ld %d %s\n", timestam, philo->id, status);
	}
	pthread_mutex_unlock(&philo->data->write_mutex);
}
