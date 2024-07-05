/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 04:19:31 by seong-ki          #+#    #+#             */
/*   Updated: 2024/07/05 15:27:39 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

void	check_arguments(int ac, char **av)
{
	int		pid;
	size_t	i;

	if (ac < 3)
	{
		ft_printf("\033[31mfew arguments!!\033[0m\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (ft_isdigit(av[1][i]))
		i++;
	if (i != ft_strlen(av[1]))
	{
		ft_printf("\033[31mInvalid PID!!\033[0m\n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || pid > 4194304)
	{
		ft_printf("\033[31mInvalid PID!!\033[0m\n");
		exit(EXIT_FAILURE);
	}
}

char	*create_msg(char *msg)
{
	char	*new_msg;
	char	*client_pid;

	client_pid = ft_itoa(getpid());
	new_msg = ft_strdup("\033[32mCLIENT[\033[35m");
	new_msg = ft_strjoin(new_msg, client_pid);
	new_msg = ft_strjoin(new_msg, "\033[32m]: \033[0m");
	new_msg = ft_strjoin(new_msg, msg);
	new_msg = ft_strjoin(new_msg, "\n");
	new_msg = ft_strjoin(new_msg, "\b");
	free(client_pid);
	return (new_msg);
}

void	sig_handle(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Server received message success!\n");
}

void	send_str(int pid, char *msg)
{
	int	i;
	int	j;
	int	bit;

	i = 0;
	while (msg[i])
	{
		j = 0;
		while (j < 8)
		{
			bit = msg[i] >> (7 - j) & 1;
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

int	main(int ac, char *av[])
{
	int					pid;
	struct sigaction	sa;
	char				*msg;

	check_arguments(ac, av);
	pid = ft_atoi(av[1]);
	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_handler = sig_handle;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	ft_printf("CLIENT PID: %d\n", getpid());
	msg = create_msg(av[2]);
	send_str(pid, msg);
	free(msg);
	return (0);
}
