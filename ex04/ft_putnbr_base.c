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

void ft_putnbr_base(int nbr, char *base)
{
	int base_cnt;
	long long nbr_l;
	char nb_char;
	nbr_l = nbr;
	base_cnt = check_base(base);
	if (base_cnt == 0)
		return;
	if (nbr_l < 0)
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
