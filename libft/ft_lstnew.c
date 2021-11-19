/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlamothe <mlamothe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 10:58:15 by mlamothe          #+#    #+#             */
/*   Updated: 2021/06/24 23:11:05 by mlamothe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!(newlist))
		return (NULL);
	newlist->content = malloc(sizeof(content));
	if (!(newlist))
		return (NULL);
	newlist->content = content;
	newlist->next = NULL;
	return (newlist);
}
