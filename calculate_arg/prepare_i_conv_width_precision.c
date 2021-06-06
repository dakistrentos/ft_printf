#include "../ft_printf.h"

static char	*prepare_min_width_positive_p_conv(t_arg *arg,
	char *arg_string_prec, int arg_string_prec_len)
{
	char	*arg_string_width;

	arg_string_width = (char *)malloc(arg->min_width + 1);
	ft_memset(arg_string_width, ' ', arg->min_width - arg_string_prec_len);
	ft_strlcpy(&arg_string_width[arg->min_width - arg_string_prec_len],
		arg_string_prec, arg_string_prec_len + 1);
	return (arg_string_width);
}

static char	*prepare_min_width_positive_ret(t_arg *arg, char *arg_string_prec,
	int precision)
{
	int		arg_string_prec_len;
	char	*arg_string_width;

	arg_string_prec_len = (int)ft_strlen(arg_string_prec);
	if (arg->type != 'p' && arg->min_width > precision && arg->precision != 0
		&& arg->min_width > arg_string_prec_len)
		arg_string_width = prepare_min_width_positive_p_conv(arg,
				arg_string_prec, arg_string_prec_len);
	else if (arg->type == 'p' && arg->min_width > precision)
		arg_string_width = prepare_min_width_positive_p_conv(arg,
				arg_string_prec, arg_string_prec_len);
	else if (arg->type != 'p' && arg->min_width > precision
		&& arg->precision == 0
		&& arg_string_prec_len < arg->min_width)
		arg_string_width = prepare_min_width_positive_p_conv(arg,
				arg_string_prec, arg_string_prec_len);
	else
	{
		arg_string_width = (char *)malloc(arg_string_prec_len + 1);
		ft_strlcpy(arg_string_width, arg_string_prec, arg_string_prec_len + 1);
	}
	return (arg_string_width);
}

char	*prepare_min_width_positive(t_arg *arg, char *arg_string_prec)
{
	int		precision;

	if (ft_strchr(arg_string_prec, '-'))
		precision = arg->precision + 1;
	else
		precision = arg->precision;
	return (prepare_min_width_positive_ret(arg, arg_string_prec, precision));
}

char	*prepare_min_width_negative(t_arg *arg, char *arg_string_prec)
{
	char	*arg_string_width;
	int		arg_string_prec_len;

	arg_string_prec_len = (int)ft_strlen(arg_string_prec);
	if (arg->min_width > arg->precision && arg->min_width > arg_string_prec_len)
	{
		arg_string_width = (char *)malloc(arg->min_width + 1);
		ft_strlcpy(arg_string_width, arg_string_prec, arg_string_prec_len + 1);
		ft_memset(&arg_string_width[arg_string_prec_len], ' ',
			arg->min_width - arg->precision);
		arg_string_width[arg->min_width] = '\0';
	}
	else
	{
		arg_string_width = (char *)malloc(arg_string_prec_len + 1);
		ft_strlcpy(arg_string_width, arg_string_prec, arg_string_prec_len + 1);
	}
	return (arg_string_width);
}
