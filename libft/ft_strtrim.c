/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 17:38:29 by mlamothe          #+#    #+#             */
/*   Updated: 2021/06/24 22:56:25 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_present(char const *set, char c)
{
	int	j;

	j = -1;
	while (set[++j])
		if (c == set[j])
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	int		j;
	char	*word;

	len = ft_strlen(s1);
	i = -1;
	while (is_present(set, s1[++i]))
		--len;
	i = ft_strlen(s1);
	if (len > 0)
		while (is_present(set, s1[--i]))
			--len;
	word = malloc((len + 1) * sizeof(char));
	if (!(word))
		return (NULL);
	i = 0;
	j = -1;
	while (is_present(set, s1[i]))
		++i;
	while (++j < len)
		word[j] = s1[i++];
	word[j] = 0;
	return (word);
}
