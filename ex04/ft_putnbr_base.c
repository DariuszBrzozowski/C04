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

void ft_putnbr_base(int nbr, char *base)
{
	int base_cnt;
	long int nbr_l;
	char nb_char;
	nbr_l = nbr;
	base_cnt = check_base(base);
	if (base_cnt == 0)
		return;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr_l = - nbr_l;
	}
	if (nbr_l >= base_cnt)
		ft_putnbr_base(nbr_l/base_cnt, base);
	nb_char = base[nbr_l%base_cnt];
	write(1, &nb_char, 1);
}

int main(int argc, char *argv[])
{
	ft_putnbr_base(-2147483648, "0123456789abcdef");
	return(0);
}
