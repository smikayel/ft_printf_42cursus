/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:14:22 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/24 20:18:21 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
/*
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
*//*
int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
		{
			break ;
		}
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
*/
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
		ft_putchar(base[call[i]]);
	if (nbr == 0)
		ft_putchar('0');
}
