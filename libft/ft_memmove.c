/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 16:39:56 by mlamothe          #+#    #+#             */
/*   Updated: 2021/06/24 23:13:07 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp;
	int		i;

	tmp = malloc(len);
	i = -1;
	while ((size_t)++i < len)
		tmp[i] = ((char *)src)[i];
	i = -1;
	while ((size_t)++i < len)
		((char *)dst)[i] = tmp[i];
	return (dst);
}
