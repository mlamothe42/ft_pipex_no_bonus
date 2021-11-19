/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 18:50:19 by mlamothe          #+#    #+#             */
/*   Updated: 2021/06/24 23:20:28 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	int	i;

	if (ft_strlen(to_find) == 0)
		return (str);
	i = 0;
	while (str[i] && (size_t)i < n)
	{
		if (str[i] == to_find[0])
		{
			if (i + ft_strlen(to_find) >= n)
				return (NULL);
			if (ft_strncmp(&str[i], to_find, ft_strlen(to_find)) == 0)
				return (&str[i]);
		}
		++i;
	}
	return (NULL);
}
