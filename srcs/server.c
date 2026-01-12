/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:43:41 by lgervet           #+#    #+#             */
/*   Updated: 2026/01/12 17:53:40 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("[x] Server PID: %d\n", pid);
	server_wait_for_signals();
	return (1);
}
