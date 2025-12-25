/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:43:41 by lgervet           #+#    #+#             */
/*   Updated: 2025/12/23 18:58:10 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handle_signal(int sig)
{
	ft_printf("SERVER > Received signal %d\n", sig);
	exit(sig);
}

void	wait_for_signal(void)
{
	signal(SIGUSR1, handle_signal);
	while (1)
		usleep(1);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("SERVER > PID: %d\n", pid);
	wait_for_signal();
	return (1);
}
