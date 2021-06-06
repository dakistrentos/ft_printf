#include "../ft_printf.h"

void	min_width_bigger_prec_plus(t_arg *arg, char *arg_string)
{
	int	len;

	if (arg->precision <= (int)ft_strlen(arg->arg_string))
		len = arg->precision;
	else
		len = ft_strlen(arg->arg_string);
	arg->result_arg_string = (char *)malloc(arg->min_width + 1);
	ft_memset(arg->result_arg_string, ' ', arg->min_width - len);
	ft_strlcpy(&arg->result_arg_string[arg->min_width - len],
		arg_string, arg->precision + 1);
}

void	min_width_bigger_prec_minus(t_arg *arg, char *arg_string)
{
	arg->result_arg_string = (char *)malloc(arg->min_width + 1);
	ft_strlcpy(arg->result_arg_string, arg_string, arg->precision + 1);
	ft_memset(&arg->result_arg_string[arg->precision], ' ',
		arg->min_width - arg->precision);
	arg->result_arg_string[arg->min_width] = '\0';
}
