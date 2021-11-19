/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:11:28 by mlamothe          #+#    #+#             */
/*   Updated: 2021/06/24 23:13:45 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	long	nbtmp;

	nbtmp = nb;
	if (nbtmp < 0)
	{
		nbtmp = nbtmp * -1;
		write(fd, "-", 1);
	}
	if (nbtmp > 9)
	{
		ft_putnbr_fd(nbtmp / 10, fd);
		ft_putnbr_fd(nbtmp % 10, fd);
	}
	else
	{
		nbtmp = 48 + nbtmp;
		write(fd, &nbtmp, 1);
	}
}
