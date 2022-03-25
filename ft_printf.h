#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"
# include <stdbool.h>
# include <limits.h>

int	hex_print(unsigned int number, int fd, char upper_lower);
int	ft_print_unsigned_int(unsigned  int number);
int	ft_print_pointer(unsigned long long int nbr);
int	print_str(char *string);
int	print_dec_int(int nbr);

#endif
