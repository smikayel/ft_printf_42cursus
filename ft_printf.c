/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:15:39 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/24 20:15:41 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:15:36 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/24 20:15:36 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:15:34 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/24 20:15:34 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *form, ...)
{
	va_list arguments;
	int i;
	int count_of_chr;

	i = 0;
	count_of_chr = 0;
	va_start(arguments, form);
	while (form[i] != '\0')
	{
		if (form[i + 1] && form[i] == '%')
		{
			if (form[i + 1] == 'c')
			{ 
				ft_putchar_fd(va_arg(arguments, int), 1);
			}
			else if (form[i + 1] == 's')
			{
				ft_putstr_fd(va_arg(arguments, char *), 1);
			}
			else if (form[i + 1] == 'p')
			{
				ft_putnbr_base(va_arg(arguments, unsigned long long),
					   	"0123456789abcdef");
			}
			else if (form[i + 1] == 'd' || form[i + 1] == 'i')
			{
				ft_putnbr_fd(va_arg(arguments, int), 1);
			}
			else if (form[i + 1] == 'u')
			{
				ft_print_unsigned_int(va_arg(arguments, unsigned int));
			}
			else if (form[i + 1] == 'x' || form[i + 1] == 'X')
			{
				hex_print(va_arg(arguments, int) , 1, form[i + 1]);
			}
			else if (form[i + 1] == '%')
			{
				ft_putchar_fd('%', 1);
			}
			i++;
		}
		else
		{
			count_of_chr += 1;
			ft_putchar_fd(form[i], 1);

		}
		i++;
			
	}
	va_end(arguments);
	return 0;
}

int main()
{
	int a;

	//ft_printf("%p \n", -50546);
	ft_putnbr_base( -50546,"0123456789abcdef");
	printf("%X", 4556);
	return 0;
}
