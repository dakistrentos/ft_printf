#include "../ft_printf.h"

void	prepare_null_str(t_arg *arg)
{
	arg->result_arg_string = (char *)malloc(ft_strlen(STR_NULL) + 1);
	ft_strlcpy(arg->result_arg_string, STR_NULL, ft_strlen(STR_NULL) + 1);
}

void	prepare_null_char(t_arg *arg)
{
	if (arg->precision_on == '0' && arg->min_width_on == '0')
		printed_char_counter(1);
	if (arg->precision_on == '0' && arg->min_width_on == '1')
	{
		printed_char_counter(1);
		arg->min_width--;
	}
	else if (arg->precision_on == '1' && arg->precision == 0)
	{
		printed_char_counter(1);
		arg->min_width--;
	}
}
