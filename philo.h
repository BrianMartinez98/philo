/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 15:37:08 by brimarti          #+#    #+#             */
/*   Updated: 2025/12/02 15:38:47 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				meals_eating;
	long			last_meal_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}				t_philo;

typedef struct s_data
{
	int				num_philos;
	int				num_meals_to_eat;
	int				simulation_should_end;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	sim_mutex;
}				t_data;

// utils.c
void	print_status(t_philo *philo, const char *status, int force_print);
void	handle_error(char *message);
long	ft_atol(const char *str);
size_t	ft_strlen(char *s);

// Parser.c
int		parse_args(t_data *data, int agc, char **agv);

// init.c
int		init(t_data *data);

// main.c
int		main(int ac, char **av);

// routine.c
void	*routine(void *arg);
int		thread_creation(t_data *data);

// Monitor.c
void	*monitoring(void *arg);

// timestamp.c
long	get_current_time(void);
void	precise_usleep(long time_in_ms, t_data *data);
long	get_time_since(long start_time);

// actions.c
void	eat_philo(t_philo *philo);
void	sleep_philo(t_philo *philo);
void	think(t_philo *philo);

#endif
