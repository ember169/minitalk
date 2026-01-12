/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_char_converter.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 14:52:00 by lgervet           #+#    #+#             */
/*   Updated: 2026/01/11 14:52:18 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

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

int	convert_binary_to_decimal(char *char_bin)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (char_bin[i])
	{
		j = j << 1 | (char_bin[i] - '0');
		i++;
	}
	return (j);
}

int	main(int ac, char **av)
{
	int		i;
	size_t	len;
	char	**encoded;

	if (ac < 2)
		return (1);
	len = strlen(av[1]);
	encoded = (char **)malloc((sizeof(*encoded) * (len + 1)));
	if (!encoded)
		return (1);
	printf("[x] UTF-8 IN:  %s\n", av[1]);
	i = 0;
	while (i < len)
	{
		encoded[i] = convert_char_to_binary((int)av[1][i]);
		i++;
	}
	printf("[ ] binary out: ");
	for (i = 0; i < len; i++)
		printf("%s ", encoded[i]);
	printf("\n[x] RESULT: ");
	i = 0;
	while (encoded[i])
	{
		printf("%c", (char)convert_binary_to_decimal(encoded[i]));
		i++;
	}
}
