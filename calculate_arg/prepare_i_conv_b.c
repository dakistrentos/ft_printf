#include "../ft_printf.h"

static void	found_minus(t_arg *arg, char *arg_string, int arg_string_len)
{
	arg->result_arg_string = (char *)malloc(arg->min_width + 1);
	ft_memset(arg->result_arg_string, '0', arg->min_width - arg_string_len);
	ft_strlcpy(&arg->result_arg_string[arg->min_width - arg_string_len],
		arg_string, arg_string_len + 1);
}

static void	not_found_minus(t_arg *arg, char *arg_string, int arg_string_len)
{
	arg_string_len++;
	arg->result_arg_string = (char *)malloc(arg->min_width + 1);
	arg->result_arg_string[0] = '-';
	ft_memset(&arg->result_arg_string[1], '0', arg->min_width - arg_string_len);
	ft_strlcpy(&arg->result_arg_string[arg->min_width - arg_string_len + 1],
		&arg_string[1], arg_string_len + 1);
}

void	prepare_i_conv_plus_zero_no_prec(t_arg *arg, char *arg_string)
{
	int	arg_string_len;

	arg_string_len = (int)ft_strlen(arg_string);
	if (ft_strchr(arg_string, '-'))
		arg_string_len--;
	if (arg->min_width > arg_string_len)
	{
		if (!ft_strchr(arg_string, '-'))
			found_minus(arg, arg_string, arg_string_len);
		else
			not_found_minus(arg, arg_string, arg_string_len);
	}
	else
	{
		if (ft_strchr(arg_string, '-'))
			arg_string_len++;
		arg->result_arg_string = (char *)malloc(arg_string_len + 1);
		ft_strlcpy(arg->result_arg_string, arg_string, arg_string_len + 1);
	}
}
