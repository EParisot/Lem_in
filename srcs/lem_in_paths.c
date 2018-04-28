/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:20:39 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/28 06:07:10 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_in_lst(t_list *path, char *pos)
{
	t_list	*tmp;

	tmp = path;
	while (tmp)
	{
		if (!ft_strcmp(pos, (char*)tmp->content))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

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

static int	end(t_list **path, t_list **paths)
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

static int	check_tubes(t_ant_hill *ant_hill, t_list **path, t_list **paths, \
			char *pos)
{
	t_list	*tmp_tubes;
	t_list	*new_pos;
	t_list	*tmp_path;

	tmp_tubes = ant_hill->tubes;
	new_pos = NULL;
	tmp_path = NULL;
	while (tmp_tubes)
	{
		if (!ft_strcmp(pos, ((char**)tmp_tubes->content)[0]) && \
		!is_in_lst(*path, ((char**)tmp_tubes->content)[1]))
		{
			if (!(new_pos = ft_lstnew(((char**)tmp_tubes->content)[1], \
			ft_strlen(((char**)tmp_tubes->content)[1]) + 1)))
				return (0);
			if (!lst_cpy(&tmp_path, *path))
				return (0);
			ft_lstaddend(path, new_pos);
			get_paths(ant_hill, path, paths, ((char**)tmp_tubes->content)[1]);
			free(*path);
			*path = tmp_path;
		}
		tmp_tubes = tmp_tubes->next;
	}
	return (1);
}

int			get_paths(t_ant_hill *ant_hill, t_list **path, t_list **paths, \
			char *pos)
{
	if (!(*path))
		if (!(*path = ft_lstnew(ant_hill->start, \
		ft_strlen(ant_hill->start) + 1)))
			return (0);
	if (!ft_strcmp(pos, ant_hill->end))
	{
		if (!(end(path, paths)))
		{
			ft_lstdel(path, del1);
			return (0);
		}
		return (1);
	}
	else if (!(check_tubes(ant_hill, path, paths, pos)))
	{
		ft_lstdel(path, del1);
		return (0);
	}
	ft_lstdel(path, del1);
	return (1);
}
