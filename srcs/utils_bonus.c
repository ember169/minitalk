/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:44:01 by lgervet           #+#    #+#             */
/*   Updated: 2026/01/15 14:21:07 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

/*
** convert_char_to_binary:
**     Converts a given char in its binary representation.
**	   (Allocates memory for it)
**
**     @param char_int  character decimal representation.
**     @return str containing the binary representation / NULL if alloc failed.
*/
char	*convert_char_to_binary(int char_int)
{
	int		i;
	char	*encoded_char;

	encoded_char = malloc((8 * sizeof(char)) + 1);
	if (!encoded_char)
		return (NULL);
	i = 0;
	while (i < BITS_NB)
	{
		encoded_char[BITS_NB - 1 - i] = ((char_int >> i) & 1) + '0';
		i++;
	}
	encoded_char[BITS_NB] = '\0';
	return (encoded_char);
}

void	wait_for_ack(struct sigaction sa)
{
	sigset_t	sigset;

	sigemptyset(&sigset);
	sigaction(SIGUSR1, &sa, NULL);
	sigsuspend(&sigset);
}

void	send_null_char(int target, struct sigaction sa)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(target, SIGUSR1);
		wait_for_ack(sa);
		i++;
	}
	return ;
}
