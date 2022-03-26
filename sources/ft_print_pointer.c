/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:14:22 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/26 15:00:21 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int len_llu(unsigned long long nbr)
{
	int len;

	len = 0;
	while(nbr != 0)
	{
		nbr /= 10;
		len++;
	}
	return (len);

}

int	ft_print_pointer(unsigned long long int nbr)
{
	char *char_arr_llu;
	int len;
	int			i;
	int	tmp;

	char_arr_llu = NULL;
	write(1, "0x", 2);
	len = len_llu(nbr);
	i = 0;
	if (nbr == 0)
	{
		len += 3;
		write(1, "0", 1);
	}
	else
	{
		char_arr_llu = malloc(len);
		while (nbr != 0)
		{
			tmp = nbr % 16;
			if (tmp >= 10)
				tmp = 'a' + tmp - 10;
			else
				tmp += '0';
			char_arr_llu[i] = tmp;
			nbr /= 16;
			i++;
		}
		len = i;
		while (--i >= 0)
			ft_putchar_fd(char_arr_llu[i], 1);
		len += 2;
	}
	free(char_arr_llu);
	return (len);
}
