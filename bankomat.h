#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct	s_money
{
	int			five_t;
	int			two_t;
	int			one_t;
	int			five_h;
	int			two_h;
	int			one_h;
	int			half_h;
	int			sum;
}				t_money;

char		**ft_strsplit(char const *s, char c);