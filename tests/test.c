/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:52:00 by lgervet           #+#    #+#             */
/*   Updated: 2025/12/30 16:33:07 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../includes/minitalk.h"

/*
** single_char_converter:
**     Converts one char to binary
**
**     @param c  character to convert
**     @param n  bytes needed for character
**     @return binary string
*/
void single_char_converter(char c, int n)
{
	char	*dst;
	int		decimal;
	int		i;

	dst = (char *)malloc((n + 1) * sizeof(char));
	if (!dst)
		return ;
	decimal = (int)c;
	i = n - 1;
	while (i)
	{
		dst[i] = ft_itoa(decimal % 2);
		decimal /= 2;
		i--;
	}
	dst[n] = '\0';
	// printf("[ ] char %c (%d) = %d%d%d%d%d%d%d%d\n", c, (int)c, dst[0], dst[1], dst[2], dst[3], dst[4], dst[5], dst[6], dst[7]);
	printf("[ ] char %c (%d) = %s\n", c, (int)c, dst);
}

void	string_converter(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		single_char_converter(s[i], 8);
		i++;
	}
}

int	main(void)
{
	char	*src = "lorem";
	char	*dst[5][8];
	char	*end;

	printf("[ ] src = %s\n", src);
	printf("[X] CONVERTING...\n");
	string_converter(src);
	printf("[X] CONVERTING BACK...\n");
	// bin_converter(dst);
	return (0);
}
