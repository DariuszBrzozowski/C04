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

int ft_atoi_base(char *str, char *base)
{
	int base_cnt;
	int	sign;
	int	nb;
	int 	i;
	int 	j;

	i = 0;
	sign = 1;
	j = 0;
	nb = 0;
	base_cnt = check_base(base);
	if (base_cnt == 0)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			sign = -sign;
			i++;
		}
		else if (str[i] == '+' || str[i] == ' ')
			i++;
		else if ((str[i] < '0' || str[i] > '9') && (!( str[i] >= 'A' && str[i] <= 'F')))
		{
			return (sign * nb);
		}
		else
		{	nb = nb * base + (str[i] - '0');
			i++;
		}
	}
	return (sign * nb);
}
int main(int argc, char *argv[1])
{
#include <stdio.h>
	printf("%d", ft_atoi(argv[1]));
}

