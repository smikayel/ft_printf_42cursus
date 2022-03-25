/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:14:22 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/25 12:29:06 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	is_base_valid(char *str)
{
	int		i;
	int		j;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i])
	{
		j = i +1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == '+' || str[i] == '-')
			return (0);
		if (str[i] < 33 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

void	ft_putnbr_base(unsigned long long int nbr, char *base)
{
	unsigned long long int	num;
	int			call[20];
	int			a;
	int			i;

	write(1, "0x", 2);
	num = nbr;
	a = ft_strlen(base);
	i = 0;
	if (nbr < 0 && is_base_valid(base))
	{
		num = num * -1;
	}
	while (num && is_base_valid(base))
	{
		call[i] = num % a;
		num = num / a;
		i++;
	}
	while (--i >= 0)
		ft_putchar_fd(base[call[i]], 1);
	if (nbr == 0)
		ft_putchar_fd('0', 1);
}
