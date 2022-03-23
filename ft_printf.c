#include "ft_printf.h"

void	hex_print(int number, int fd)
{
	char	hex;
	while (number != 0)
	{
		
		hex = number % 16;
		if (hex < 10)
		{
			hex += '0';
		}
		else if(hex > 10)
		{
			hex += 87;
		}

		ft_putchar_fd(hex, 1);
		number /= 16;
	}
}

void	ft_print_pointer(void *a)
{
	int	tmp;

	tmp = (unsigned int)&a;
	printf("%d", (unsigned int)&a);
	printf("%p", a);
	printf("%llu", tmp);
}

int ft_printf(const char *form, ...)
{
	va_list arguments;
	int response;
	int i;
	int count_of_chr;

	i = 0;
	count_of_chr = 0;
	va_start(arguments, form);
	while (form[i] != '\0')
	{
		if (form[i] && form[i] == '%')
		{
			if (form[i + 1] == 'c')
			{
				count_of_chr += 1; 
				ft_putchar_fd(va_arg(arguments, int), 1);
			}
			else if (form[i + 1] == 's')
			{
				ft_putstr_fd(va_arg(arguments, char *), 1);
			//	count_of_chr += ft_strlen(va_arg(arguments, char *));
			}
			else if (form[i + 1] == 'p')
			{
				ft_print_pointer(va_arg(arguments, void *));
			}
			else if (form[i + 1] == 'd')
			{
				ft_putnbr_fd(va_arg(arguments, int), 1);
			}
			/*
			else if (form[i + 1] == 'i')
				// amboxj tiv
			else if (form[i + 1] == 'u')
				//
				*/
			
			else if (form[i + 1] == 'x')
			{
				hex_print(va_arg(arguments, int) , 1);
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
	char *a;
	//ft_printf("aasdasd%c___%s--", 'l',"barev Serg");
	ft_printf("%x\n %%", 154);
	//printf("%x",-77994779);
	return 0;
}
