/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 13:51:23 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/05/17 18:20:44 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char	*str1;
	char	*str2;

	if (!dest && !src)
		return (NULL);
	str1 = dest;
	str2 = (char *)src;
	while (len > 0)
	{
		*str1 = *str2;
		str1++;
		str2++;
		len--;
	}
	return (dest);
}
