# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smikayel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 20:10:50 by smikayel          #+#    #+#              #
#    Updated: 2022/03/26 13:22:21 by smikayel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =	ft_printf.c \
		sources/ft_hex_print.c \
		sources/ft_print_str.c \
		sources/ft_print_unsigned_int.c \
		sources/ft_print_pointer.c \
		sources/print_dec_int.c \
		
SURPL_O = ft_printf.o \
		sources/ft_hex_print.o \
		sources/ft_print_str.o \
		sources/ft_print_unsigned_int.o \
		sources/ft_print_pointer.o \
		sources/print_dec_int.o \
		

CC = cc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
