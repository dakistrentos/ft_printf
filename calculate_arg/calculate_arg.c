#include "../ft_printf.h"

char	check_zero_flag(t_arg *arg)
{
	char	padding;

	if (arg->zero_flag_on == '0')
		padding = ' ';
	else
		padding = '0';
	return (padding);
}

void	calculate_arg(t_arg *arg)
{
	if (arg->type == 'd' || arg->type == 'i' || arg->type == 'x'
		|| arg->type == 'X' || arg->type == 'p' || arg->type == 'u')
		prepare_i_conv_main(arg);
	else if (arg->type == 's' || arg->type == 'c')
		prepare_s_conv_main(arg);
	else if (arg->type == '%')
		prepare_prc_conv_main(arg);
}
