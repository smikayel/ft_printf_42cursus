/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:15:34 by smikayel          #+#    #+#             */
/*   Updated: 2022/03/25 20:24:10 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *form, ...)
{
	va_list arguments;
	int i;
	int count;

	i = 0;
	count = 0;
	va_start(arguments, form);
	while (form[i] != '\0')
	{
        if (form[i + 1] && form[i] == '%')
                {
                        if (form[i + 1] == 'c')
                        { 
                                count += 1;
                                ft_putchar_fd(va_arg(arguments, int), 1);
                        }
                        else if (form[i + 1] == 's')
                                count += print_str(va_arg(arguments, char *));
                        else if (form[i + 1] == 'p')
                                count += ft_print_pointer(va_arg(arguments, unsigned long long));
                        else if (form[i + 1] == 'd' || form[i + 1] == 'i')
                                count += print_dec_int(va_arg(arguments, int));
                        else if (form[i + 1] == 'u')
                                count += ft_print_unsigned_int(va_arg(arguments, unsigned int));
                        else if (form[i + 1] == 'x' || form[i + 1] == 'X')
                                count += hex_print(va_arg(arguments, int) , 1, form[i + 1]);
                        else if (form[i + 1] == '%')
                        {
                                count += 1;
                                ft_putchar_fd('%', 1);
                        }
                        i++;
                }
                else
                {
                        count += 1;
                        ft_putchar_fd(form[i], 1);

                }
                i++;
	}
	va_end(arguments);
	return (count);
}
/*
int main()
{
	char *a;

	ft_printf("%p barev %d %x %X %% %i %u\n", a, 45, 154, 154 ,5, 5546546545);
	//ft_putnbr_base( -50546,"0123456789abcdef");
	printf("%p barev %d %x %X %% %i %u\n", a, 45, 154, 154, 5, 5546546545);
	return 0;
}*/
