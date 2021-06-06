# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: Vtrentos <Vtrentos@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/04 11:57:02 by Vtrentos      #+#    #+#                  #
#    Updated: 2021/06/03 08:39:31 by Vtrentos      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER_FILES = libft/libft.h ft_printf.h 
SRC_FILES = libft/ft_strlen.c libft/ft_strlcpy.c libft/ft_isalpha.c \
	libft/ft_memset.c libft/ft_memcpy.c \
	libft/ft_strchr.c libft/ft_strncmp.c \
	libft/ft_atoi.c libft/ft_isdigit.c libft/ft_isalnum.c \
	libft/ft_itoa.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c \
	libft/ft_putnbr_fd.c \
	ft_printf.c \
	print_t_arg/all_convs_a.c print_t_arg/all_convs_b.c \
	print_t_arg/print_t_arg.c \
	calculate_arg/calculate_arg.c calculate_arg/prepare_i_conv.c \
	calculate_arg/prepare_i_conv_b.c \
	calculate_arg/prepare_s_conv.c \
	calculate_arg/prepare_i_conv_width_precision.c \
	calculate_arg/prepare_prc_conv_main.c \
	calculate_arg/prepare_null_char.c \
	calculate_arg/prepare_s_conv_width_prec_utils_a.c \
	calculate_arg/prepare_i_conv_width_precision_b.c \
	calculate_arg/prepare_i_conv_width_precision_c.c \
	calculate_arg/prepare_s_conv_utils.c \
	calculate_arg/prepare_p_null_conv_small_min_width.c \
	calculate_arg/prepare_s_conv_plus.c \
	calculate_arg/prepare_s_conv_width_prec_utils_b.c \
	calculate_arg/prepare_s_conv_plus_util.c \
	flags/flags_width_main.c flags/flags_width_extras.c \
	flags/precision.c \
	puts/puts.c

all: $(NAME)

OBJ_FILES = $(SRC_FILES:.c=.o)

$(NAME): $(OBJ_FILES)
	ar -rc $(NAME) $(OBJ_FILES)

$(OBJ_FILES): $(SRC_FILES) $(HEADER_FILES)

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
