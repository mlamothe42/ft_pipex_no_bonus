/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:46:46 by mlamothe          #+#    #+#             */
/*   Updated: 2021/06/24 23:19:53 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*word;

	word = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!(word))
		return (NULL);
	i = 0;
	while (s[i])
	{
		word[i] = f(i, s[i]);
		++i;
	}
	return (word);
}
