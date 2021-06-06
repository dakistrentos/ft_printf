/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Vtrentos <Vtrentos@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 11:27:28 by Vtrentos      #+#    #+#                 */
/*   Updated: 2021/05/17 18:22:19 by Vtrentos      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	len;

	if (!src || !dst)
		return (0);
	len = ft_strlen(src);
	if (size == 0)
		return (len);
	else if (size > len + 1)
		ft_memcpy(dst, src, len + 1);
	else if (len != 0)
		ft_memcpy(dst, src, size - 1);
	dst[size - 1] = '\0';
	return (len);
}
