/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 04:19:19 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/25 04:38:45 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "libft.h"
#include "ft_printf.h"

void	get_str(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	chr;
	static int				bit_itr = -1;

	(void) ucontext;
	if (bit_itr < 0)
		bit_itr = 7;
	if (sig == SIGUSR2)
		chr |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0)
	{
		ft_putchar_fd(chr, 1);
		chr = 0;
		if (kill(info->si_pid, SIGUSR1) == -1)
			ft_printf("Server failed to send SIGUSR1\n");
	}
}

void	config_signals(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &get_str;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("Failed to change SIGUSR1's behavior\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("Failed to change SIGUSR2's behavior\n");
}

int	main(void)
{
	ft_printf("SERVER PID: %d\n", getpid());
	while (1)
		config_signals();
	return (0);
}
