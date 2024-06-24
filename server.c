#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"
#include "ft_printf.h"

void	get_str(int sig, siginfo_t *info, void *ucontext)
{
	static char	chr;
	static int	bit;

	(void) ucontext;
	(void) info;
	if (sig == SIGUSR1)
		chr |= 0;
	else if (sig == SIGUSR2)
		chr |= 1;
	if (bit < 7)
		chr <<= 1;
	bit++;
	if (bit == 8)
	{
		write(1, &chr, 1);
		bit = 0;
		chr = 0;
	}
}

int	main(void)
{
	struct sigaction act;
	ft_memset(&act, 0, sizeof(act));
	act.sa_sigaction =  get_str;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	ft_putstr_fd("pid: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		pause();
	}
}
