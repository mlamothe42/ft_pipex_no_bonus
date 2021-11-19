/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_nfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 12:57:28 by mlamothe          #+#    #+#             */
/*   Updated: 2021/11/14 16:34:41 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

void	ft_exit_nfree(t_data *data, int ext)
{
	ft_free_data(data);
	exit(ext);
}

int	ft_free_data(t_data *data)
{
	int	i;

	if (data->cmd1)
		free(data->cmd1);
	if (data->cmd2)
		free(data->cmd2);
	if (data->param1)
	{
		i = 0;
		while (data->param1[++i] != NULL)
			free(data->param1[i]);
		free(data->param1);
	}
	if (data->param2)
	{
		i = 0;
		while (data->param2[++i] != NULL)
			free(data->param2[i]);
		free(data->param2);
	}
	return (0);
}

int	ft_perror(int ret)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	return (ret);
}

int	ft_err_nfree(int ret, t_data *data, int do_exit)
{
	ft_free_data(data);
	ft_perror(ret);
	if (do_exit)
		exit(ret);
	return (ret);
}

int	writerr(char *err, char *str)
{
	write(2, err, ft_strlen(err));
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	return (1);
}
