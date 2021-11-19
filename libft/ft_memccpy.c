/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 14:49:16 by mlamothe          #+#    #+#             */
/*   Updated: 2021/06/24 23:11:28 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int	i;

	i = -1;
	while ((size_t)++i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		if (((char *)dest)[i] == (char)c)
			return (dest + i + 1);
	}
	return (NULL);
}
