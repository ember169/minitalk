/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:52:00 by lgervet           #+#    #+#             */
/*   Updated: 2026/01/05 13:07:21 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../includes/minitalk.h"

/*
** single_char_converter:
**     Converts one char to binary
**
**     @param c  character to convert
**     @param n  bytes needed for character
**     @return binary string
*/
// char *ascii_char_to_bin(char c, int bytes_nb)
// {
// 	char	*dst;
// 	int		decimal;
// 	int		i;

// 	dst = (char *)malloc((bytes_nb + 1) * sizeof(char));
// 	if (!dst)
// 		return (NULL);
// 	decimal = (int)c;
// 	i = bytes_nb - 1;
// 	while (i)
// 	{
// 		dst[i] = ft_itoa(decimal % 2);
// 		decimal /= 2;
// 		i--;
// 	}
// 	dst[n] = '\0';
// 	printf("[ ] char %c (%d) = %s\n", c, (int)c, dst);
// 	return (dst);
// }

// char	*ascii_str_to_bin(char	*s)
// {
// 	int		i;
// 	int		bytes_nb;
// 	char	*dst;

// 	bytes_nb = 8;
// 	dst = malloc((strlen(s) * sizeof(char)) * bytes_nb);
// 	if (!dst)
// 		return (NULL);
// 	i = 0;
// 	while (s[i])
// 	{
// 		dst[i] = ascii_char_to_bin(s[i], bytes_nb);
// 		i++;
// 	}
// 	return (dst);
// }

// int	main(void)
// {
// 	char	*src = "lorem";
// 	char	*dst[5][8];
// 	char	*end;

// 	printf("[ ] src = %s\n", src);
// 	printf("[X] CONVERTING...\n");
// 	ascii_str_to_bin(src);
// 	printf("[X] CONVERTING BACK...\n");
// 	// bin_converter(dst);
// 	return (0);
// }

// printf("[ ] char %c (%d) = %d%d%d%d%d%d%d%d\n", c, (int)c, dst[0], dst[1], dst[2], dst[3], dst[4], dst[5], dst[6], dst[7]);

/*
	binary utf-8 character = 8 bytes
	  -> 1 char =  1 str
	one str in binary = multiple str (1 by char)
*/

char	*convert_char_to_binary(int char_int, int byte_nb, int bits_nb)
{
	int		i;
	int		j;
	char	*encoded_char;

	encoded_char = malloc((8 * sizeof(char)) + 1);
	if (!encoded_char)
		return (NULL);
	i = 0;
	while (i < byte_nb)
	{
		j = 0;
		while (j < bits_nb)
		{
			encoded_char[bits_nb - 1 - j] = ((char_int >> j) & 1) + '0';
			j++;
		}
		i++;
	}
	encoded_char[bits_nb] = '\0';

	printf("[ ] Encoded char %d: %s\n", char_int, encoded_char);
	return (encoded_char);
}

int	main(int ac, char **av)
{
	int		i;
	size_t	len;
	char	**encoded;
	int		byte_nb = 1 ; // for utf8
	int		bits_nb = 8 ; // for utf8

	if (ac < 2)
		return (1);
	len = strlen(av[1]);
	encoded = (char **)malloc((sizeof(*encoded) * (len + 1)) * byte_nb);
	if (!encoded)
		return (1);
	printf("[x] IN: %s\n", av[1]);
	i = 0;
	while (i < len)
	{
		encoded[i] = convert_char_to_binary((int)av[1][i], byte_nb, bits_nb);
		i++;
	}
	printf("[x] OUT: ");
	for (i = 0; i < len; i++)
		printf("%s ", encoded[i]);
}
