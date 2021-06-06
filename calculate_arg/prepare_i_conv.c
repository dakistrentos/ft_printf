#include "../ft_printf.h"

static void	prepare_i_conv_minus(t_arg *arg, char *arg_string)
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

static void	prepare_i_conv_plus(t_arg *arg, char padding, char *arg_string)
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
			ft_memset(arg->result_arg_string, padding,
				arg->min_width - ft_strlen(arg_string));
			ft_strlcpy(
				&arg->result_arg_string[arg->min_width - ft_strlen(arg_string)],
				arg_string, ft_strlen(arg_string) + 1);
		}
	}
	else if (arg->min_width_on == '0')
	{
		arg->result_arg_string = (char *)malloc(ft_strlen(arg_string) + 1);
		ft_strlcpy(arg->result_arg_string, arg_string,
			ft_strlen(arg_string) + 1);
	}
}

static void	prepare_i_conv_precision(t_arg *arg, char *arg_string)
{
	char	*arg_string_prec;

	if (arg->type == 'p' && arg->precision_on == '1'
		&& ft_strncmp(arg->arg_string, ZERO_X, 2) == 0 && arg->precision == 0 )
	{
		arg->result_arg_string = (char *)malloc(3);
		ft_strlcpy(arg->result_arg_string, &ZERO_X[0], 3);
	}
	else if (ft_strlen(arg_string) == 1 && arg_string[0] == '0'
		&& arg->precision == 0)
	{
		arg->result_arg_string = (char *)malloc(1);
		arg->result_arg_string[0] = '\0';
	}
	else
	{
		arg_string_prec = prepare_precision(arg, arg_string);
		arg->result_arg_string = (char *)malloc(ft_strlen(arg_string_prec) + 1);
		ft_strlcpy(arg->result_arg_string, arg_string_prec,
			ft_strlen(arg_string_prec) + 1);
		free(arg_string_prec);
	}
}

static void	prepare_i_conv_main_util(t_arg *arg, char *arg_string, char padding)
{
	if (arg->type == 'p' && arg->precision_on == '1' && arg->min_width_on == '0'
		&& (int)ft_strlen(arg_string) > 3)
		arg->precision_on = '0';
	if (arg->type == 'p' && arg->precision_on == '1'
		&& ft_strncmp(&ZERO_X_X[0], arg->arg_string, 3) == 0
		&& arg->min_width <= 2 && arg->min_width >= -2)
		prepare_p_null_conv_small_min_width(arg);
	else if (arg->minus_flag_on == '1' && arg->precision_on == '0')
		prepare_i_conv_minus(arg, arg_string);
	else if (arg->zero_flag_on == '1' && arg->min_width_on == '1'
		&& arg->precision_on == '0')
		prepare_i_conv_plus_zero_no_prec(arg, arg_string);
	else if (arg->minus_flag_on == '0' && arg->precision_on == '0')
		prepare_i_conv_plus(arg, padding, arg_string);
	else if (arg->precision_on == '1' && arg->min_width_on == '0')
		prepare_i_conv_precision(arg, arg_string);
	else if (arg->min_width_on == '1' && arg->minus_flag_on == '0'
		&& arg->precision_on == '0')
		prepare_i_conv_plus(arg, ' ', arg_string);
	else if (arg->min_width_on == '1' && arg->precision_on == '1')
		prepare_i_conv_width_precision(arg, arg_string);
}

void	prepare_i_conv_main(t_arg *arg)
{
	char	*arg_string;
	char	padding;

	padding = check_zero_flag(arg);
	arg_string = arg->arg_string;
	prepare_i_conv_main_util(arg, arg_string, padding);
}
