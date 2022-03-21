#include "ft_printf.h"

/*
// -1 finish of text
// 0 i element is not percent (for flag)
// 1 whene need to print only char
//
int checking_type_and_printing(char *form,int index)
{
	if(form[i + 1] == '\0')
		return (-1);
	if(form[i] == '%')
		return (0);
	if(form[i + 1] == 'c');
}
*/
void ft_print_pointer(char a)
{
	printf("%d",a);
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
				ft_print_pointer(va_arg(arguments, int));
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
			else if (form[i + 1] == 'x')
				//
			else if (form[i + 1] == '%')
				*/
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
	ft_printf("%pa%c___%s--%d",a, 'c',"asd" ,456,"asdasd", 'a');
	return 0;
}
