/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 17:41:08 by mlamothe          #+#    #+#             */
/*   Updated: 2021/11/14 18:32:20 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

char	*ft_get_cmd_part(char *cmd)
{
	char	*str;
	int		j;
	int		i;

	j = 0;
	while (cmd[j] && cmd[j] != ' ')
		++j;
	str = malloc((2 + j) * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '/';
	i = -1;
	while (++i < j)
		str[i + 1] = cmd[i];
	str[i + 1] = 0;
	return (str);
}

char	*ft_loop_absolute_path(char	*str, char	**splt)
{
	int		i;
	char	*join;

	i = -1;
	while (splt[++i])
	{
		join = ft_join(splt[i], str);
		free(splt[i]);
		if (!access(join, R_OK))
		{
			free(str);
			while (splt[++i])
				free(splt[i]);
			free(splt);
			return (join);
		}
		else
			if (join)
				free(join);
	}
	free(splt);
	writerr("Command not found : ", str + 1);
	free(str);
	return (NULL);
}

char	*ft_get_cmd(char *cmd, t_data *data, int wich, char **env)
{
	char	*str;
	int		i;
	char	**splt;

	i = 0;
	while (cmd[i] && cmd[i] != ' ')
		++i;
	if (wich == 1)
		data->param1 = ft_split_params(cmd + i, ' ');
	else if (wich == 2)
		data->param2 = ft_split_params(cmd + i, ' ');
	if (!ft_strlen(cmd) && writerr("Command not found : ", cmd))
		return (NULL);
	if (!access(cmd, R_OK))
		return (ft_strdup(cmd));
	str = ft_get_cmd_part(cmd);
	i = 0;
	if (!str || !env[i])
		return (NULL);
	while (ft_strncmp("PATH", env[i], 4))
		++i;
	splt = ft_split(env[i] + 5, ':');
	if (!splt)
		return (NULL);
	return (ft_loop_absolute_path(str, splt));
}
