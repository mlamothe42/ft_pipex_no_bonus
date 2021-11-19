/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:19:47 by mlamothe          #+#    #+#             */
/*   Updated: 2021/06/24 23:11:37 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t len)
{
	int	i;

	i = -1;
	while ((size_t)++i < len)
		if (((unsigned char *)b)[i] == (unsigned char)c)
			return ((unsigned char *)b + i);
	return (NULL);
}
