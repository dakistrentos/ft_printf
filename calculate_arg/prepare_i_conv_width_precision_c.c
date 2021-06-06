#include "../ft_printf.h"

void	prepare_i_conv_width_precision_ret(t_arg *arg, char *arg_string)
{
	char	*arg_string_prec;
	char	*arg_string_width;
	int		string_len;

	arg_string_prec = prepare_precision(arg, arg_string);
	if (arg->type == 'p' && ft_strncmp(&ZERO_X[0], arg->arg_string, 2) == 0)
		arg_string_prec[2] = '\0';
	if (arg->minus_flag_on == '0')
		arg_string_width = prepare_min_width_positive(arg, arg_string_prec);
	else
		arg_string_width = prepare_min_width_negative(arg, arg_string_prec);
	string_len = (int)ft_strlen(arg_string_width);
	arg->result_arg_string = (char *)malloc(string_len + 1);
	ft_strlcpy(arg->result_arg_string, arg_string_width, string_len + 1);
	free(arg_string_prec);
	free(arg_string_width);
}

void	prepare_i_conv_width_precision(t_arg *arg, char *arg_string)
{
	if (ft_strlen(arg_string) == 1 && arg_string[0] == '0'
		&& arg->precision == 0)
	{
		arg->result_arg_string = (char *)malloc(arg->min_width + 1);
		ft_memset(arg->result_arg_string, ' ', arg->min_width);
		arg->result_arg_string[arg->min_width] = '\0';
	}
	else
		prepare_i_conv_width_precision_ret(arg, arg_string);
}
