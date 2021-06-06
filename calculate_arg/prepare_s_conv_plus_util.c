#include "../ft_printf.h"

void	prepare_s_conv_plus_util(t_arg *arg, char *arg_string)
{
	if (arg->min_width <= (int)ft_strlen(arg_string)
		&& arg->precision_on == '1'
		&& (int)ft_strlen(arg_string) > arg->precision)
		prepare_s_conv_plus_util_a(arg, arg_string);
	else if (arg->min_width <= (int)ft_strlen(arg_string))
	{
		arg->result_arg_string = (char *)malloc(ft_strlen(arg_string) + 1);
		ft_strlcpy(arg->result_arg_string, arg_string,
			ft_strlen(arg_string) + 1);
	}
	else if (arg->min_width > (int)ft_strlen(arg_string))
	{
		if (arg->precision_on == '0')
			prepare_s_conv_plus_util_b(arg, arg_string);
		else if (arg->precision_on == '1')
		{
			if (arg->minus_flag_on == '0')
				prepare_s_conv_plus_util_c(arg, arg_string);
			else if (arg->minus_flag_on == '1')
				prepare_s_conv_plus_util_d(arg, arg_string);
		}
	}
}
