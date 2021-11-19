/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 13:26:59 by mlamothe          #+#    #+#             */
/*   Updated: 2021/06/24 23:13:19 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	int	i;

	i = -1;
	while ((size_t)++i < n)
		((unsigned char *)dest)[i] = (unsigned char)c;
	return (dest);
}
