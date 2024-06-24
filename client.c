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
	(void) pid;
	while (msg[i])
	{
		j = 0;
		while (j < 8)
		{
			ft_printf("%d ", msg[i] >> (7 - j) & 1);
			j++;
		}
		write(1, "\n", 1);
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
//	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
	return (0);

}
