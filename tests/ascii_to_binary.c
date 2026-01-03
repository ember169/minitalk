/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgervet <42@leogervet.com>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:56:36 by lgervet           #+#    #+#             */
/*   Updated: 2025/12/30 14:51:12 by lgervet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	print_ascii_in_bin(char c)
{
	int		decimal;
	int		i;
	int		temp[8];

	decimal = (int)c;
	i = 0;
	while (i < 8)
	{
		temp[i] = decimal % 2;
		decimal /= 2;
		i++;
	}
	i--;
	while (i >= 0)
	{
		printf("%d", temp[i]);
		i--;
	}
}

/* MAIN FOR ASCII TO BINARY */
// int	main(int ac, char **av)
// {
// 	char	c;
// 	int		i;

// 	if (ac < 2 || !av)
// 		return (0);
// 	i = 0;
// 	while (av[1][i])
// 	{
// 		print_ascii_in_bin(av[1][i]);
// 		printf(" ");
// 		i++;
// 	}
// 	return (1);
// }

void	print_bin_in_ascii(int	*bin)
{
	char	c;
	int		i;
	int		decimal;

	i = 0;
	decimal = 0;
	while (i < 8)
	{
		decimal += bin[i] * 2;
		i++;
	}
	c = decimal;
	printf("%c", c);
}

static char	*ft_chartobinary(char c)
{
	int		decimal;
	int		i;
	int		temp[8];
	char	ret[8];

	decimal = (int)c;
	i = 0;
	while (i < 8)
	{
		temp[i] = decimal % 2;
		decimal /= 2;
		i++;
	}
	i = 0;
	while (i < 8)
	{
		ret[i] = (char)temp[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_atob(char *src)
{
	char	*dest;
	int		i;
	int		j;
	int		len;

	len = strlen(src);
	dest = malloc((len * sizeof(char)) * 8 + sizeof(char));
	while (i < len)
	{
		dest[i] = *ft_chartobinary(src[i]);
		i++;
	}
	printf("%s", dest);
}

/* MAIN FOR BINARY TO ASCII */
int	main(int ac, char **av)
{
	// int		i;
	// int		j;
	char	*input = "lorem";
	// char	*dest;
	// char	**bin = {"01101100","01101111","01110010","01100101","01101101"};

	// i = 0;
	// dest = malloc(((strlen(input)) * sizeof(char)) * 8 + sizeof(char));
	// while (input[i])
	// {
	// 	j = 0;
	// 	while (j < 8)
	// 		dest[j++] = atob(input[i]);
	// 	i++;
	// }
	// return (1);
	ft_atob(input);
}
