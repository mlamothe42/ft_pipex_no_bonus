/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:25:07 by mlamothe          #+#    #+#             */
/*   Updated: 2021/06/24 23:11:46 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	int	i;

	i = -1;
	while ((size_t)++i < len)
		if (((unsigned char *)b1)[i] != ((unsigned char *)b2)[i])
			return (((unsigned char *)b1)[i] - ((unsigned char *)b2)[i]);
	return (0);
}
