#include <unistd.h>

void	ft_putnbr(int nb)
{
	int div;
	int mod;
	char nb_char;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return; 
	}

	else if (nb < 0)
	{
		write(1, "-", 1);
		nb = - nb;
	}

	if (nb < 10)
	{
		nb_char = nb + '0';
		write(1, &nb_char, 1);
	}
	else 
	{
		div = nb/10;
		mod = nb%10;
		ft_putnbr(div);
		ft_putnbr(mod);
	}

}

int main(int argc, char *argv[])
{
	ft_putnbr(-1234);
	return(0);
}
