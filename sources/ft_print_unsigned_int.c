/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:15:14 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/24 20:15:16 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int len_unsigned_int(unsigned number)
{
	int len;

	len = 0;
	while (number != 0)
	{
		len++;
		number /= 10;
	}
	return (len);
}

void	ft_rev_int_tab(char *tab, int size)
{
	int	i;
	int k;

	i = 0;
	while (i < (size) / 2)
	{
		k = *(tab + i);
		*(tab + i) = *(tab + size - 1 - i);
		*(tab + size - 1 - i) = k;
		i++;
	}
}

int ft_print_unsigned_int(unsigned int number)
{
	char *b;
	int	i;
	int len;

	if (number == 0)
		ft_putchar_fd('0', 1);
	else
	{
		i = 0;
		len = len_unsigned_int(number);
		b = malloc(len);
		while (number != 0)
		{
			b[i] = number % 10 + '0';
			number /= 10;
			i++;
		}
		ft_rev_int_tab(b, len);
		ft_putstr_fd(b, 1);
		free(b);
	}
	return (i);
}
