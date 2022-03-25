/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:15:05 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/25 20:23:00 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_rev_int_tab(char *tab, int size)
{
	int	i;
	int	k;

	i = 0;
	while (i < (size) / 2)
	{
		k = *(tab + i);
		*(tab + i) = *(tab + size - 1 - i);
		*(tab + size - 1 - i) = k;
		i++;
	}
}

static int	len_hex_number(unsigned int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	hex_print(unsigned int number, int fd, char upper_lower)
{
	char	hex;
	int		len;
	int		i;
	char	*hex_str;

	if (number == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	len = len_hex_number(number);
	hex_str = malloc(sizeof(char)*len);
	i = 0;
	while (number != 0)
	{
		hex = number % 16;
		if(hex >= 10)
		{
			if (upper_lower == 'x')
				hex += 87;
			else
				hex += 55;
		}
		else
			hex += 48;
		hex_str[i] = hex;
		number /= 16;
		i++;
	}
	ft_rev_int_tab(hex_str, ft_strlen(hex_str));
	ft_putstr_fd(hex_str, 1);
	free(hex_str);
}
