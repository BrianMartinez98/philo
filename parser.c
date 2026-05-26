/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:37:06 by brimarti          #+#    #+#             */
/*   Updated: 2025/12/02 15:37:07 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(t_data *data)
{
	if (data->num_philos <= 0)
		return (handle_error("The number of philosophers should be > 0"), 0);
	if (data->time_to_die <= 0)
		return (handle_error("time_to_die should be > 0"), 0);
	if (data->time_to_eat <= 0)
		return (handle_error("time_to_eat should be > 0"), 0);
	if (data->time_to_sleep <= 0)
		return (handle_error("time_to_sleep should be > 0"), 0);
	return (1);
}

static int	is_valid_number(const char *s)
{
	int	digit;

	digit = 0;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			digit = 1;
		else
			return (0);
		s++;
	}
	return (digit);
}

int	parse_args(t_data *data, int agc, char **agv)
{
	int	i;

	if (agc < 5 || agc > 6)
		return (handle_error("Incorrect number of arguments"), 0);
	i = 1;
	while (i < agc)
	{
		if (!is_valid_number(agv[i]))
			return (handle_error("Argument contains invalid characters"), 0);
		i++;
	}
	data->num_philos = (int)ft_atol(agv[1]);
	data->time_to_die = ft_atol(agv[2]);
	data->time_to_eat = ft_atol(agv[3]);
	data->time_to_sleep = ft_atol(agv[4]);
	if (agc == 6)
	{
		data->num_meals_to_eat = (int)ft_atol(agv[5]);
		if (data->num_meals_to_eat <= 0)
			return (handle_error("num_meals_to_eat must be > 0"), 0);
	}
	else
		data->num_meals_to_eat = -1;
	return (check_args(data));
}
