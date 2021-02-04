#include "bankomat.h"

/*
**  gcc bankomat.c ft_strslpit.c -lreadline
*/

int		count(int value, int *strct, int cash)
{
	int		amount;

	amount = cash / *strct;
	if (amount > *strct)
		amount = *strct;
	cash = cash - value * amount;
	*strct = *strct - amount;
	return (cash);
}

void	ft_money_out(char **arr, t_money *money)
{
	int		cash;
	int		tmp_cash;

	if (arr[1])
		cash = atoi(arr[1]);
	else
		return ;
	if (money->sum < cash)
	{
		printf("Not enough money\n");
		return ;
	}
	if (cash % 50 != 0)
	{
		printf("Invalid money summ\n");
		return ;
	}
	tmp_cash = cash;
	if (cash >= 5000 && money->five_t > 0)
		cash = count(5000, &money->five_t, cash);
	if (cash >= 2000 && money->two_t > 0)
		cash = count(2000, &money->two_t, cash);
	if (cash >= 1000 && money->one_t > 0)
		cash = count(1000, &money->one_t, cash);
	if (cash >= 500 && money->five_h > 0)
		cash = count(500, &money->five_h, cash);
	if (cash >= 200 && money->two_h > 0)
		cash = count(200, &money->two_h, cash);
	if (cash >= 100 && money->one_h > 0)
		cash = count(100, &money->one_h, cash);
	if (cash >= 50 && money->half_h > 0)
		cash = count(50, &money->half_h, cash);
	if (cash != 0)
	{
		printf("Not enough specific denomination notes\n");
		return ;
	}
	else
		money->sum-=tmp_cash;
}

void	ft_money_in(char **arr, t_money *money)
{
	int		i;
	int		amount;

	i = 1;
	while (arr[i])
	{
		if (arr[i + 1])
			amount = atoi(arr[i + 1]);
		else
			return ;
		if (strcmp(arr[i], "5000") == 0)
		{
			money->five_t+= amount;
			money->sum+= 5000 * amount;
		}
		else if (strcmp(arr[i], "2000") == 0)
		{
			money->two_t+= amount;
			money->sum+= 2000 * amount;
		}
		else if (strcmp(arr[i], "1000") == 0)
		{
			money->one_t+= amount;
			money->sum+= 1000 * amount;
		}
		else if (strcmp(arr[i], "500") == 0)
		{
			money->five_h+= amount;
			money->sum+= 500 * amount;
		}
		else if (strcmp(arr[i], "200") == 0)
		{
			money->two_h+= amount;
			money->sum+= 200 * amount;
		}
		else if (strcmp(arr[i], "100") == 0)
		{
			money->one_h+= amount;
			money->sum+= 100 * amount;
		}
		else if (strcmp(arr[i], "50") == 0)
		{
			money->half_h+= amount;
			money->sum+= 50 * amount;
		}
		i+=2;
	}
}

void	ft_struct_init(t_money *money)
{
	money->five_t = 0;
	money->two_t = 0;
	money->one_t = 0;
	money->five_h = 0;
	money->two_h = 0;
	money->one_h = 0;
	money->half_h = 0;
	money->sum = 0;
}

int     main(void)
{
	t_money	*money;
	char	*str;

	if (!(money = malloc(sizeof(t_money))))
	{
		printf("Malloc error\n");
		return (1);
	}
	ft_struct_init(money);
	str = readline(NULL);
	while (strcmp(str, "exit") != 0)
	{	
		if (strncmp(str, "in", 2) == 0)
			ft_money_in(ft_strsplit(str, ' '), money);
		else if (strncmp(str, "out", 3) == 0)
			ft_money_out(ft_strsplit(str, ' '), money);
		else
		{
			free (str);
			printf("Invalid data\n");
			return (1);
		}
		printf("Balance = %i\n", money->sum);
		str = readline(NULL);
	}
	return (0);
}
