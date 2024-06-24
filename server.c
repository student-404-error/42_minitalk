#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"

#define UTF8_1 0x7F
#define UTF8_2 0x7FF
#define UTF8_3 0xFFFF
#define UTF8_4 0x1FFFFF

void	get_str(int sig)
{
	char	chr;

	chr = sig;
	ft_putnbr_fd(sig, 1);
	write(1, "\n", 1);
	write(1, &chr, 1);
}

int	main(void)
{
	ft_putstr_fd("pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	unsigned char	chr = ;
	printf("%d", chr);
	signal(SIGUSR1, get_str);
	signal(SIGUSR2, get_str);
	while (1)
	{
		pause();
	}
}
