/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:16:31 by mlamothe          #+#    #+#             */
/*   Updated: 2021/06/24 22:57:21 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*ret;
	int		i;
	int		nbr;

	nbr = number * size;
	ret = malloc(nbr);
	if (!(ret))
		return (NULL);
	i = -1;
	while (++i < nbr)
		((char *)ret)[i] = 0;
	return (ret);
}
