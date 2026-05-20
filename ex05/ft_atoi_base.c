#include <unistd.h>
int check_base(char *base)
{
	int j;
	int k;
	j = 0;
	if (*base == '\0')
		return (0);
	while (base[j] != '\0')
	{
		if (base[j] == '+' || base[j] == '-')
			return (0);
		k = j+1;
		while (base[k] != '\0')
		{
			if (base[j] == base[k])
				return (0);
			k++;
		}
		j++;
	}
	return (j);
}

int get_num(char *base, char c)
{
	int i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}


int ft_atoi_base(char *str, char *base)
{
	int base_cnt;
	int	sign;
	int	nb;
	int 	i;
	int 	cur_num;

	i = 0;
	sign = 1;
	cur_num = 0;
	nb = 0;
	base_cnt = check_base(base);
	if (base_cnt == 0)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			sign = -sign;
		}
		else if (str[i] == '+' || str[i] == ' ')
			nb = 1*nb;
		else
		{	
			cur_num = get_num(base, str[i]);
			if (cur_num == -1)
				return (sign * nb);
			else
				nb = nb * base_cnt + cur_num;
		}
		i++;
	}
	return (sign * nb);
}
int main(int argc, char *argv[])
{
#include <stdio.h>
	if (argc > 1)
		printf("%d", ft_atoi_base(argv[1], argv[2]));
}

