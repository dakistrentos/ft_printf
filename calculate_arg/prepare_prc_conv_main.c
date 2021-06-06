#include "../ft_printf.h"

static void	prepare_prc_positive_width(t_arg *arg)
{
	arg->result_arg_string = (char *)malloc(arg->min_width + 1);
	ft_memset(arg->result_arg_string, ' ', arg->min_width);
	arg->result_arg_string[arg->min_width - 1] = '%';
	arg->result_arg_string[arg->min_width] = '\0';
}

static void	prepare_prc_positive_width_zero(t_arg *arg)
{
	arg->result_arg_string = (char *)malloc(arg->min_width + 1);
	ft_memset(arg->result_arg_string, '0', arg->min_width);
	arg->result_arg_string[arg->min_width - 1] = '%';
	arg->result_arg_string[arg->min_width] = '\0';
}

static void	prepare_prc_negative_width(t_arg *arg)
{
	arg->result_arg_string = (char *)malloc(arg->min_width + 1);
	arg->result_arg_string[0] = '%';
	ft_memset(&arg->result_arg_string[1], ' ', arg->min_width - 1);
	arg->result_arg_string[arg->min_width] = '\0';
}

void	prepare_prc_conv_main(t_arg *arg)
{
	if (arg->min_width_on == '0' && arg->zero_flag_on == '1')
	{
		arg->result_arg_string = (char *)malloc(2);
		ft_strlcpy(arg->result_arg_string, arg->arg_string, 2);
	}
	if (arg->min_width_on == '0' && arg->zero_flag_on == '0'
		&& arg->minus_flag_on == '0')
	{
		arg->result_arg_string = (char *)malloc(2);
		arg->result_arg_string[0] = '%';
		arg->result_arg_string[1] = '\0';
	}
	else if (arg->min_width_on == '1' && arg->zero_flag_on == '0'
		&& arg->minus_flag_on == '0')
		prepare_prc_positive_width(arg);
	else if (arg->min_width_on == '0' && arg->zero_flag_on == '0'
		&& arg->minus_flag_on == '0')
		prepare_prc_positive_width(arg);
	else if (arg->min_width_on == '1' && arg->zero_flag_on == '1'
		&& arg->minus_flag_on == '0')
		prepare_prc_positive_width_zero(arg);
	else if (arg->min_width_on == '1' && arg->minus_flag_on == '1')
		prepare_prc_negative_width(arg);
}
