/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:23:25 by mlamothe          #+#    #+#             */
/*   Updated: 2021/06/24 23:20:31 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	ret;

	i = -1;
	ret = -1;
	while (s[++i])
		if (s[i] == c)
			ret = i;
	if (ret != -1)
		return ((char *)s + ret);
	if (c == 0)
		return ((char *)s + i);
	return (NULL);
}
