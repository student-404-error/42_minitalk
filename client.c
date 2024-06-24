#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

void	send_str(int pid, char *msg)
{
	int	i;
	int	j;

	i = 0;
	while (msg[i])
	{
		j = 0;
		while (j < 8)
		{
			int	bit = msg[i] >> (7 - j) & 1;
			ft_printf("%d\n", bit);
			if (bit == 0)
				kill(pid, SIGUSR1);
			else if (bit == 1)
				kill(pid, SIGUSR2);
			j++;
			usleep(50);
		}
		i++;
	}
}

int main(int ac, char *av[])
{
	int	pid;

	if (ac < 3)
	{
		ft_printf("invalid arguments\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || pid > 4194304)
	{
		ft_printf("invalid pid\n");
		return (1);
	}
	send_str(pid, av[2]);
	return (0);

}
