/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:20:39 by eparisot          #+#    #+#             */
/*   Updated: 2018/05/04 16:22:02 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_good_move(t_list *path, char *pos, t_ant_hill *ant_hill)
{
	t_list	*tmp;
	t_list	*tmp_tubes;

	tmp = path;
	tmp_tubes = ant_hill->tubes;
	if (!ft_strcmp(pos, ant_hill->end))
		return (1);
	while (tmp)
	{
		if (!ft_strcmp(pos, (char*)tmp->content))
			return (0);
		tmp = tmp->next;
	}
	while (tmp_tubes)
	{
		if (!ft_strcmp(pos, ((char**)tmp_tubes->content)[0]))
			return (1);
		if (((char**)tmp_tubes->content)[2][0] == '0' && \
				!ft_strcmp(pos, ((char**)tmp_tubes->content)[1]))
			return (1);
		tmp_tubes = tmp_tubes->next;
	}
	if (!tmp_tubes)
		return (0);
	return (1);
}

static int	check_tubes2(t_ant_hill *ant_hill, t_list **path, t_list **paths, \
		char *tmp)
{
	t_list	*new_pos;
	t_list	*tmp_path;

	if (!(new_pos = ft_lstnew(tmp, ft_strlen(tmp) + 1)))
		return (0);
	if (!lst_cpy(&tmp_path, *path))
		return (0);
	ft_lstaddend(path, new_pos);
	get_paths(ant_hill, path, paths, tmp);
	free(*path);
	*path = tmp_path;
	return (1);
}

static int	check_tubes(t_ant_hill *ant_hill, t_list **path, t_list **paths, \
		char *pos)
{
	t_list	*tmp_tubes;

	tmp_tubes = ant_hill->tubes;
	while (tmp_tubes)
	{
		if (!ft_strcmp(pos, ((char**)tmp_tubes->content)[0]) && \
				is_good_move(*path, ((char**)tmp_tubes->content)[1], ant_hill))
		{
			if (!check_tubes2(ant_hill, path, paths, \
						((char**)tmp_tubes->content)[1]))
				return (0);
		}
		else if (((char**)tmp_tubes->content)[2][0] == '0' && !ft_strcmp(pos, \
					((char**)tmp_tubes->content)[1]) && is_good_move(*path, \
					((char**)tmp_tubes->content)[0], ant_hill))
		{
			if (!check_tubes2(ant_hill, path, paths, \
						((char**)tmp_tubes->content)[0]))
				return (0);
		}
		tmp_tubes = tmp_tubes->next;
	}
	return (1);
}

int			get_paths(t_ant_hill *ant_hill, t_list **path, t_list **paths, \
		char *pos)
{
	if (!(*path))
		if (!ant_hill->rooms || !ant_hill->start || !ant_hill->end || !(*path =\
					ft_lstnew(ant_hill->start, ft_strlen(ant_hill->start) + 1)))
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
	if (!(check_tubes(ant_hill, path, paths, pos)))
	{
		ft_lstdel(path, del1);
		return (0);
	}
	ft_lstdel(path, del1);
	return (1);
}
