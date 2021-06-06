#include "../ft_printf.h"

void	malloc_copy_arg_result_string(t_arg *arg, char *arg_string)
{
	arg->result_arg_string = (char *)malloc(ft_strlen(arg_string) + 1);
	ft_strlcpy(arg->result_arg_string, arg_string, ft_strlen(arg_string) + 1);
}
