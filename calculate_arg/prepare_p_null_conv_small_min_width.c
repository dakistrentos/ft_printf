#include "../ft_printf.h"

void	prepare_p_null_conv_small_min_width(t_arg *arg)
{
	arg->result_arg_string = (char *)malloc(3);
	ft_strlcpy(arg->result_arg_string, &ZERO_X[0], 3);
}
