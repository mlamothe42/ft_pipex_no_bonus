/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:35:42 by mlamothe          #+#    #+#             */
/*   Updated: 2021/11/14 16:36:59 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

int	ft_do_child1(t_data *data, int *pipefd, char **env)
{
	int		fd;

	close(pipefd[PIPE_W]);
	fd = open(data->file2, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1)
	{
		perror(data->file2);
		ft_exit_nfree(data, 1);
	}
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (ft_err_nfree(1, data, 1));
	close(fd);
	if (dup2(pipefd[PIPE_R], STDIN_FILENO) == -1)
		return (ft_err_nfree(1, data, 1));
	close(pipefd[PIPE_R]);
	execve(data->cmd2, data->param2, env);
	return (ft_err_nfree(1, data, 1));
}

int	ft_do_child2(t_data *data, int *pipefd, char **env)
{
	int	fd;

	close(pipefd[PIPE_R]);
	fd = open(data->file1, O_RDONLY);
	if (fd == -1)
	{
		perror(data->file1);
		ft_exit_nfree(data, 1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		return (ft_err_nfree(1, data, 1));
	close(fd);
	if (dup2(pipefd[PIPE_W], STDOUT_FILENO) == -1)
		return (ft_err_nfree(1, data, 1));
	close(pipefd[PIPE_W]);
	execve(data->cmd1, data->param1, env);
	return (ft_err_nfree(1, data, 1));
}

int	do_pipex(t_data *data, int *pipefd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (ft_err_nfree(1, data, 1));
	if (pid == 0)
	{
		if (ft_do_child1(data, pipefd, env))
			return (ft_err_nfree(1, data, 1));
	}
	else
	{
		pid = fork();
		if (pid == -1)
			return (ft_err_nfree(1, data, 1));
		if (pid == 0)
			if (ft_do_child2(data, pipefd, env))
				return (ft_err_nfree(1, data, 1));
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		status1;
	int		status2;
	int		pipefd[2];

	ft_parse(argc, argv, env, &data);
	if (pipe(pipefd) == -1)
		return (ft_err_nfree(1, &data, 1));
	do_pipex(&data, pipefd, env);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &status1, WUNTRACED);
	waitpid(-1, &status2, WUNTRACED);
	if (WEXITSTATUS(status1) && !WEXITSTATUS(status2))
		ft_exit_nfree(&data, 0);
	if (WEXITSTATUS(status2))
		ft_exit_nfree(&data, 1);
	return (ft_free_data(&data));
}
