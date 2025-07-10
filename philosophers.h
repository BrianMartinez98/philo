#ifndef PHILOSOPHERS
# define PHILOSOPHERS

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <pthread.h>

typedef enum 
{
    PARAMETROS,
    MALLOCERROR,
    FD,
    IMG_ERROR,
	NOTRECTANGULAR,
	NOTWALLS,
	NOTPOSSIBLE,
	BER,
	INVALID_CHARS,
	INVALID_PE
} 		t_errorlst;

typedef struct s_philo
{
	int		id;
	long	meals;
	bool	full;
	int		time;
	t_fork	*right_fork;
	t_fork	*left_fork;
} t_philo;

typedef struct s_fork
{
	pthread_mutex_t 	fork;
	int					id;
} t_fork;

typedef struct s_table
{
	t_philo		*philo;
	t_fork		*fork;
	void		*philos;
	void		*forks;
} t_table;

typedef struct s_data
{
	char		**arg;
	int			arguments;
	t_table		*table;
} t_data;



void	handle_error(t_errorlst error, t_data *data);

void	init(t_data *data, char **argv);

char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);

void	parser(t_data data, char** argv[]);

#endif