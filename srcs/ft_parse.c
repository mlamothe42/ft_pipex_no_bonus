/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:21:12 by mlamothe          #+#    #+#             */
/*   Updated: 2021/11/14 16:08:37 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

char	*ft_join(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*str_ret;

	str_ret = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
	if (!str_ret)
		return (NULL);
	i = -1;
	while (++i < (int)ft_strlen(str1))
		str_ret[i] = str1[i];
	j = -1;
	while (++j < (int)ft_strlen(str2))
		str_ret[i + j] = str2[j];
	str_ret[i + j] = 0;
	return (str_ret);
}

int	ft_init(int argc, t_data *data)
{
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	data->param1 = NULL;
	data->param2 = NULL;
	if (argc != 5)
	{
		if (argc < 5)
			write(2, "parsing error : Not enough arguments\n", 37);
		else
			write(2, "parsing error : Too much arguments\n", 35);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	ft_acces_file(char **argv, t_data *data)
{
	if (access(argv[4], W_OK))
	{
		if (errno == ENOENT)
		{
			data->file2 = argv[4];
			return (0);
		}
		perror(argv[4]);
		ft_exit_nfree(data, 1);
	}
	data->file2 = argv[4];
	return (0);
}

int	ft_parse(int argc, char **argv, char **env, t_data *data)
{
	ft_init(argc, data);
	data->cmd1 = ft_get_cmd(argv[2], data, 1, env);
	if (!data->cmd1)
		ft_exit_nfree(data, 0);
	if (access(argv[1], R_OK))
	{
		perror(argv[1]);
		ft_exit_nfree(data, 0);
	}
	data->file1 = argv[1];
	data->cmd2 = ft_get_cmd(argv[3], data, 2, env);
	if (!data->cmd2)
		ft_exit_nfree(data, 127);
	data->param1[0] = data->cmd1;
	data->param2[0] = data->cmd2;
	return (ft_acces_file(argv, data));
}
