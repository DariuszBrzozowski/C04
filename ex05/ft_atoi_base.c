
#include <unistd.h>
int check_base(char *base)
{
        int j;
        int k;
        int length;
        if (*base == '\0')
                return (0);
        length = 0;
        while(base[length] != '\0')
        {
                if (base[length] == '+' || base[length] == '-')
                        return (0);
                length++;
        }

        j = 0;
        while (j < length-1)
        {
                k = j+1;
                while (k < length)
                {
                        if (base[j] == base[k])
                                return (0);
                        k++;
                }
                j++;
        }
        return (length);
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
		}
		else if (str[i] == '+')
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
/*
int main(int argc, char *argv[])
{
#include <stdio.h>
	if (argc > 1)
		printf("%d", ft_atoi_base(argv[1], argv[2]));
}*/

