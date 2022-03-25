#include "../ft_printf.h"

int print_str(char *string)
{
	int count_of_chars;

	count_of_chars = 0;
	count_of_chars = ft_strlen(string);
	ft_putstr_fd(string, 1);
	return (count_of_chars);
}
