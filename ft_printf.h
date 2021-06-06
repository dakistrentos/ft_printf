/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/25 15:34:38 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/05/31 16:07:54 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# define DIGITSLO "0123456789abcdef"
# define DIGITSUP "0123456789ABCDEF"
# define FLAGS "-0.*123456789"
# define CONVS "cspdiuxX%"
# define ZERO "0"
# define ZERO_X "0x"
# define ZERO_X_X "0x0"
# define STR_NULL "(null)"
# define MAXBUF 32

typedef struct s_arg
{
	char	type;
	int		min_width;
	char	min_width_on;
	char	zero_flag_on;
	char	minus_flag_on;
	char	padding;
	int		precision;
	char	precision_on;
	char	precision_minus;
	char	value;
	char	*arg_string;
	char	*result_arg_string;
}	t_arg;

int		ft_printf(const char *str, ...);
int		printed_char_counter(int add);
void	string_reader(char *str, va_list list, t_arg *arg);
void	putchar_count(char c, int fd);
void	putstr_count(char *s, int fd);
void	conv_base_count(unsigned long int num, int base, char c, int fd);
void	print_pointer_count(void *ptr);
int		check_flag(char *flag, va_list list, t_arg *arg);
int		count_width(char *flag);
void	check_type_copy(char conv, va_list list, t_arg *arg);
char	*conv_base_str(unsigned long int num, int base, char c);
char	*pointer_str(unsigned long int num);
int		asterisk_flag(char *flag, va_list list, t_arg *arg);	
int		minus_flag(t_arg *arg);
int		min_width_flag(char *flag, t_arg *arg);
int		zero_flag(t_arg *arg);
int		precision_flag(char *flag, va_list list, t_arg *arg);
void	print_t_arg(t_arg *arg, char *index);
void	calculate_arg(t_arg *arg);
void	prepare_i_conv_main(t_arg *arg);
void	prepare_s_conv_main(t_arg *arg);
char	check_zero_flag(t_arg *arg);
void	init_arg(t_arg *arg);
void	d_conv(va_list list, t_arg *arg);
void	s_conv(va_list list, t_arg *arg);
void	c_conv(va_list list, t_arg *arg);
void	x_conv(va_list list, t_arg *arg);
void	u_x_conv(va_list list, t_arg *arg);
void	p_conv(va_list list, t_arg *arg);
void	u_conv(va_list list, t_arg *arg);
void	percentage_conv(t_arg *arg);
void	prepare_i_conv_width_precision(t_arg *arg, char *arg_string);
char	*prepare_precision(t_arg *arg, char *arg_string);
void	prepare_prc_conv_main(t_arg *arg);
void	prepare_null_str(t_arg *arg);
void	prepare_null_char(t_arg *arg);
void	min_width_bigger_prec_plus(t_arg *arg, char *arg_string);
void	min_width_bigger_prec_minus(t_arg *arg, char *arg_string);
void	prepare_i_conv_plus_zero_no_prec(t_arg *arg, char *arg_string);
void	malloc_copy_arg_result_string(t_arg *arg, char *arg_string);
void	prepare_s_conv_plus(t_arg *arg, char *arg_string);
void	prepare_i_conv_width_precision_ret(t_arg *arg, char *arg_string);
char	*prepare_min_width_positive(t_arg *arg, char *arg_string_prec);
char	*prepare_min_width_negative(t_arg *arg, char *arg_string_prec);
void	prepare_p_null_conv_small_min_width(t_arg *arg);
void	prepare_s_conv_plus_util(t_arg *arg, char *arg_string);
void	prepare_s_conv_plus_util_a(t_arg *arg, char *arg_string);
void	prepare_s_conv_plus_util_b(t_arg *arg, char *arg_string);
void	prepare_s_conv_plus_util_c(t_arg *arg, char *arg_string);
void	prepare_s_conv_plus_util_d(t_arg *arg, char *arg_string);
void	precision_minus_one(t_arg *arg, char *arg_string);
void	prepare_s_conv_minus(t_arg *arg, char *arg_string);
void	minus_flag_on_zero(t_arg *arg, char *arg_string);

#endif
