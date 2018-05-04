/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:20:39 by eparisot          #+#    #+#             */
/*   Updated: 2018/05/04 16:21:49 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			lst_cpy(t_list **dest, t_list *src)
{
	t_list	*tmp;
	t_list	*new;

	tmp = src;
	new = NULL;
	if (!(*dest = ft_lstnew(tmp->content, ft_strlen(tmp->content) + 1)))
		return (0);
	tmp = tmp->next;
	while (tmp)
	{
		if (!(new = ft_lstnew(tmp->content, ft_strlen(tmp->content) + 1)))
			return (0);
		ft_lstaddend(dest, new);
		tmp = tmp->next;
	}
	return (1);
}

int			end(t_list **path, t_list **paths)
{
	t_list	*new_path;

	new_path = NULL;
	if (!(*paths))
	{
		if (!(*paths = ft_lstnew(*path, ft_lstcount(*path) * \
						sizeof(t_list*))))
			return (0);
	}
	else
	{
		if (!(new_path = ft_lstnew(*path, ft_lstcount(*path) * \
						sizeof(t_list*))))
			return (0);
		ft_lstaddend(paths, new_path);
	}
	return (1);
}
