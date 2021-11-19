/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 15:31:40 by mlamothe          #+#    #+#             */
/*   Updated: 2021/11/14 16:34:45 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H

# define FT_PIPEX_H

# include "../libft/libft.h"

# include <sys/types.h>

# include <unistd.h>

# include <stdio.h>

# include <fcntl.h>

# include <errno.h>

# include <sys/wait.h>

# include <string.h>

# define BUFFER_SIZE 40

# define PIPE_R 0

# define PIPE_W 1

typedef struct s_data
{
	char	*file1;
	char	*file2;
	char	*cmd1;
	char	*cmd2;
	char	**param1;
	char	**param2;
}				t_data;

int		ft_parse(int argc, char **argv, char **env, t_data *data);

char	*ft_get_cmd(char *cmd, t_data *data, int wich, char **env);

char	*ft_join(char *str1, char *str2);

char	**ft_split_params(char *str, char c);

int		ft_perror(int ret);

int		ft_err_nfree(int ret, t_data *data, int do_exit);

int		ft_free_data(t_data *data);

void	ft_exit_nfree(t_data *data, int ext);

int		writerr(char *err, char *str);

#endif