/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:45:18 by mlamothe          #+#    #+#             */
/*   Updated: 2021/06/24 23:19:11 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	l;

	if (size < ft_strlen(dest))
		j = size + ft_strlen(src);
	else
		j = ft_strlen(dest) + ft_strlen(src);
	if (size <= ft_strlen(dest))
		k = 0;
	else
		k = size - ft_strlen(dest) - 1;
	i = 0;
	l = ft_strlen(dest);
	while (src[i] && i < k)
	{
		dest[l] = src[i];
		++i;
		++l;
	}
	dest[l] = 0;
	return (j);
}
