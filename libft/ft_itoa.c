/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/14 17:04:31 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/05/17 18:20:25 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0 || n == -0)
		return (1);
	while (n)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static void	str_rev(char *s, int sign)
{
	int		count;
	int		len;
	int		i;
	char	ch;

	i = 0;
	len = ft_strlen(s);
	count = len - 1;
	if (sign == -1)
	{
		i++;
	}
	while (*s && i < count)
	{
		ch = s[i];
		s[i] = s[count];
		s[count] = ch;
		i++;
		count--;
	}
}

static char	*string_fill(char *str, int n, int sign)
{
	int		n2;
	int		j;
	char	c;

	n2 = n;
	j = 0;
	if (sign == -1)
	{
		*str = '-';
		str++;
	}
	while (n)
	{
		n2 = n % 10;
		c = n2 + '0';
		ft_memset(str, c, 1);
		n = n / 10;
		str++;
		j++;
	}
	*str = '\0';
	return (str);
}

static char	*finish(int n)
{
	char	*string_res;
	int		digits;
	int		sign;

	digits = count_digits(n);
	if (n >= 0)
		sign = 1;
	else
		sign = -1;
	if (n >= 0)
		string_res = (char *)malloc(digits + 1);
	else
	{
		string_res = (char *)malloc(digits + 2);
		n = n * (-1);
	}
	if (!string_res)
		return (NULL);
	string_fill(string_res, n, sign);
	str_rev(string_res, sign);
	return (string_res);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		n = n + 1;
		str = finish(n);
		str[10] = '8';
		return (str);
	}
	if (n == -0 || n == 0)
	{
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = finish(n);
	return (str);
}
