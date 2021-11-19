/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 19:16:55 by mlamothe          #+#    #+#             */
/*   Updated: 2021/08/09 18:28:11 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

int	calc_mots_params(char *str, char c)
{
	int		i;
	int		nb;
	char	ctemp;

	i = -1;
	nb = 0;
	while (str[++i])
	{
		while (str[i] && str[i] == c)
			++i;
		while (str[i] && str[i] != c)
		{
			if (str[i] == '\'' || str[i] == '\"')
			{
				ctemp = str[i++];
				while (str[i] && str[i] != ctemp)
					++i;
			}
			++i;
		}
		if (str[i] == 0)
			i--;
		++nb;
	}
	return (nb + 1);
}

int	size_mot_params(char *str, char c, int i)
{
	char	ctemp;
	int		smot;

	smot = 0;
	while (str[i] && str[i] != c)
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			ctemp = str[i];
			++i;
			while (str[i] && str[i] != ctemp)
			{
				++smot;
				++i;
			}
			--smot;
		}
		++smot;
		++i;
	}
	return (smot);
}

char	handle_quotes(char *str, int *i, int *j, char *mot)
{
	char	ctemp;

	ctemp = str[*i];
	(*i)++;
	while (str[*i] && str[*i] != ctemp)
	{
		mot[*j] = str[*i];
		++(*i);
		++(*j);
	}
	return (ctemp);
}

char	*crea_mot_params(char *str, char c, int *i)
{
	char	*mot;
	int		smot;
	int		j;
	char	ctemp;

	smot = size_mot_params(str, c, *i);
	mot = malloc((smot + 1) * sizeof(char));
	if (!(mot))
		return (NULL);
	j = 0;
	while (j < smot)
	{
		ctemp = 0;
		if (str[*i] == '\'' || str[*i] == '\"')
			ctemp = handle_quotes(str, i, &j, mot);
		if (str[*i] != ctemp)
		{
			mot[j] = str[*i];
			++j;
		}
		(*i)++;
	}
	mot[j] = 0;
	return (mot);
}

char	**ft_split_params(char *str, char c)
{
	int		i;
	char	**tous;
	int		nbmots;

	i = -1;
	nbmots = 1;
	tous = (char **)malloc((calc_mots_params(str, c) + 1) * sizeof(char *));
	if (str == NULL || !(tous))
		return (NULL);
	while (str[++i])
	{
		while (str[i] == c)
			++i;
		if (str[i])
		{
			tous[nbmots] = crea_mot_params(str, c, &i);
			if (!(tous[nbmots]))
				return (NULL);
			nbmots++;
		}
		i--;
	}
	tous[nbmots] = 0;
	return (tous);
}
