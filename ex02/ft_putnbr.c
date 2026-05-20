#include <unistd.h>

void	ft_putnbr(int nb)
{
	
	char nb_char;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return; 
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = - nb;
	}
	if (nb >= 10)
		ft_putnbr(nb/10);
	nb_char = nb%10 + '0';
	write(1, &nb_char, 1);
}
/*
int main(int argc, char *argv[])
{
	ft_putnbr(-120000034);
	return(0);
}*/
