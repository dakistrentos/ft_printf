#include "../ft_printf.h"

void	prepare_s_conv_minus(t_arg *arg, char *arg_string)
{
	if (arg->min_width_on == '1')
	{
		if (arg->min_width <= (int)ft_strlen(arg_string))
		{
			arg->result_arg_string = (char *)malloc(ft_strlen(arg_string) + 1);
			ft_strlcpy(arg->result_arg_string, arg_string,
				ft_strlen(arg_string) + 1);
		}
		else if (arg->min_width > (int)ft_strlen(arg_string))
		{
			arg->result_arg_string = (char *)malloc(arg->min_width + 1);
			ft_strlcpy(arg->result_arg_string, arg_string,
				ft_strlen(arg_string) + 1);
			ft_memset(&arg->result_arg_string[ft_strlen(arg_string)], ' ',
				arg->min_width - ft_strlen(arg_string));
			arg->result_arg_string[arg->min_width] = '\0';
		}
	}
	else if (arg->min_width_on == '0')
	{
		arg->result_arg_string = (char *)malloc(ft_strlen(arg_string) + 1);
		ft_strlcpy(arg->result_arg_string, arg_string,
			ft_strlen(arg_string) + 1);
	}
}

static void	prepare_s_conv_precision(t_arg *arg, char *arg_string)
{
	if (arg->precision <= (int)ft_strlen(arg_string))
	{
		arg->result_arg_string = (char *)malloc(arg->precision + 1);
		ft_strlcpy(arg->result_arg_string, arg_string, arg->precision + 1);
	}
	else if (arg->precision > (int)ft_strlen(arg_string))
	{
		arg->result_arg_string = (char *)malloc(ft_strlen(arg_string) + 1);
		ft_strlcpy(arg->result_arg_string, arg_string,
			ft_strlen(arg_string) + 1);
	}
}

static void	prepare_s_conv_zero_prec(t_arg *arg)
{
	arg->result_arg_string = (char *)malloc(arg->min_width + 1);
	ft_memset(arg->result_arg_string, ' ', arg->min_width);
	arg->result_arg_string[arg->min_width] = '\0';
}

static void	prepare_s_conv_width_precision(t_arg *arg, char *arg_string)
{
	if (arg->precision == 0 && arg->min_width != 0)
		prepare_s_conv_zero_prec(arg);
	else if (arg->precision_minus == '1')
		precision_minus_one(arg, arg_string);
	else if (arg->minus_flag_on == '1')
		minus_flag_on_zero(arg, arg_string);
	else if (arg->minus_flag_on == '0' && arg->precision_minus == '0'
		&& arg->precision < (int)ft_strlen(arg->arg_string)
		&& arg->precision == arg->min_width)
	{
		arg->result_arg_string = (char *)malloc(arg->precision + 1);
		ft_strlcpy(arg->result_arg_string, arg->arg_string, arg->precision + 1);
	}
	else if (arg->min_width <= arg->precision
		&& (int)ft_strlen(arg->arg_string) < arg->precision)
		prepare_s_conv_plus(arg, arg_string);
	else if (arg->min_width <= arg->precision
		&& (int)ft_strlen(arg->arg_string) >= arg->precision)
		prepare_s_conv_plus(arg, arg_string);
	else if (arg->min_width > arg->precision && arg->minus_flag_on == '0')
		min_width_bigger_prec_plus(arg, arg_string);
	else if (arg->min_width > arg->precision && arg->minus_flag_on == '1')
		min_width_bigger_prec_minus(arg, arg_string);
}

void	prepare_s_conv_main(t_arg *arg)
{
	char	*arg_string;

	arg_string = arg->arg_string;
	if (arg->type == 'c' && arg->precision_on == '1' && arg->precision == 0)
		arg->precision_on = '0';
	if (arg->type == 'c' && arg->value == '\0')
		prepare_null_char(arg);
	if (ft_strncmp(arg_string, STR_NULL, ft_strlen(arg_string)) == 0
		&& arg->precision_minus == '1')
		prepare_null_str(arg);
	else if (arg->minus_flag_on == '0' && arg->precision_on == '0'
		&& arg->min_width_on == '0')
		malloc_copy_arg_result_string(arg, arg_string);
	else if (arg->minus_flag_on == '1' && arg->precision_on == '0')
		prepare_s_conv_minus(arg, arg_string);
	else if (arg->minus_flag_on == '0' && arg->precision == '0'
		&& arg->min_width_on == '1')
		prepare_s_conv_plus(arg, arg_string);
	else if (arg->precision_on == '1' && arg->min_width_on == '0')
		prepare_s_conv_precision(arg, arg_string);
	else if (arg->min_width_on == '1' && arg->minus_flag_on == '0'
		&& arg->precision_on == '0')
		prepare_s_conv_plus(arg, arg_string);
	else if (arg->min_width_on == '1' && arg->precision_on == '1')
		prepare_s_conv_width_precision(arg, arg_string);
}
