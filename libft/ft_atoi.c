/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/10 12:13:09 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/05/17 18:19:03 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strncomp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (n)
	{
		if (*s1 == '\0' && *s2 == '\0')
			return (i);
		if (*s1 != *s2)
		{
			i = *s1 - *s2;
			return (i);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}

static int	check_limits(const char *str)
{
	if (!ft_strncomp(str, "2147483647", 10))
		return (2147483647);
	if (!ft_strncomp(str, "-2147483648", 11))
		return (-2147483648);
	return (0);
}

static long long	conv_loop(const char *str)
{
	long long	num;
	long long	r;
	int			sign;

	num = 0;
	r = 0;
	sign = 1;
	if (*str == '+')
		str++;
	if (*str == '-')
	{
		str++;
		sign = (-1);
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		num = *str - '0';
		r = num + (r * 10);
		str++;
	}
	r = r * sign;
	return (r);
}

static int	conv_to_int(long long num)
{
	long long	min;
	long long	max;
	long long	def;
	int			res;

	res = (int)num;
	min = -2147483648;
	max = 2147483647;
	if (num < min)
	{
		def = min + (num * (-1));
		res = (((int)max - (int)def) + 1);
	}
	if (num > max)
	{
		def = num - max;
		res = (((int)min + (int)def) - 1);
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	long long	r;
	int			res;
	char		*s;

	s = (char *)str;
	if (*s == '+' || *s == '-')
	{
		s++;
		if (*s == '+' || *s == '-')
		{
			return (0);
		}
	}
	while ((*str == ' ' || *str == '\n')
		|| (*str == '\r' || *str == '\f') || (*str == '\v' || *str == '\t'))
		str++;
	r = 0;
	res = 0;
	if (check_limits(str))
		return (check_limits(str));
	r = conv_loop(str);
	res = conv_to_int(r);
	return (res);
}
