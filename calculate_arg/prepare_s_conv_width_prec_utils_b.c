#include "../ft_printf.h"

void	precision_minus_one(t_arg *arg, char *arg_string)
{
	if (arg->precision_minus == '1' && arg->minus_flag_on == '1')
		prepare_s_conv_minus(arg, arg_string);
	else if (arg->precision_minus == '1' && arg->minus_flag_on == '0')
		prepare_s_conv_plus(arg, arg_string);
}

void	minus_flag_on_zero(t_arg *arg, char *arg_string)
{
	if (arg->minus_flag_on == '1'
		&& arg->precision >= (int)ft_strlen(arg->arg_string))
		prepare_s_conv_minus(arg, arg_string);
	else if (arg->minus_flag_on == '1'
		&& arg->precision < (int)ft_strlen(arg->arg_string))
		prepare_s_conv_plus(arg, arg_string);
}
