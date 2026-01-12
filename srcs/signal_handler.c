/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 15:47:20 by lgervet           #+#    #+#             */
/*   Updated: 2026/01/12 17:54:52 by lgervet          ###   ########.fr       */
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

void	server_wait_for_signals(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &server_handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}

static void	client_handle_signal(int sig)
{
	if (sig)
		;
	return ;
}

void	client_wait_for_signal(void)
{
	struct sigaction	sa;

	sa.sa_handler = &client_handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	pause();
}
