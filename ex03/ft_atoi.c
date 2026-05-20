
int ft_atoi(char *str)

{
	int	sign;
	int	nb;
	int 	i;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] != '\0')
	{
		if (i == 0)
		{
			while (*str == ' ')
			{
				str++;
			}
		}
		if (str[i] == '-')
		{
			sign = -sign;
			i++;
		}
		else if (str[i] == '+')
			i++;
		else if (str[i] < '0' || str[i] > '9')
		{
			return (sign * nb);
		}
		else
		{	nb = nb * 10 + (str[i] - '0');
			i++;
		}
	}
	return (sign * nb);
}
/*
int main(int argc, char *argv[1])
{
#include <stdio.h>
	if (argc > 1)
	printf("%d", ft_atoi(argv[1]));
}
*/
