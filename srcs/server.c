/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:43:41 by lgervet           #+#    #+#             */
/*   Updated: 2026/01/14 12:41:27 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	server_handle_signal(int sig, siginfo_t *info, void *context)
{
	if (context)
		(void)0;
	if (sig == SIGUSR1)
		ft_printf("0");
	else if (sig == SIGUSR2)
		ft_printf("1");
	kill(info->si_pid, SIGUSR1);
}


int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;
	static char			*bin_str;

	bin_str = (char *)malloc((BITS_NB + 1) * sizeof(char));
	pid = getpid();
	ft_printf("[x] Server PID: %d\n", pid);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &server_handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sigsuspend(&sa.sa_mask);
}
