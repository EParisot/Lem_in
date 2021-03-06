/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:20:39 by eparisot          #+#    #+#             */
/*   Updated: 2018/05/10 15:29:34 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_move(t_ant *ant, char *dest, t_ant_hill *ant_hill)
{
	t_list	*tmp_tubes;

	tmp_tubes = ant_hill->tubes;
	while (tmp_tubes)
	{
		if (!ft_strcmp(((char**)tmp_tubes->content)[0], ant->room))
			if (!ft_strcmp(((char**)tmp_tubes->content)[1], dest))
				break ;
		if (((char**)tmp_tubes->content)[2][0] == '0' && \
			!ft_strcmp(((char**)tmp_tubes->content)[1], ant->room))
			if (!ft_strcmp(((char**)tmp_tubes->content)[0], dest))
				break ;
		tmp_tubes = tmp_tubes->next;
	}
	if (!tmp_tubes)
		return (0);
	return (1);
}

int			move_ant(t_ant *ant, char *dest, t_ant_hill *ant_hill,\
		t_win *win)
{
	int		*max;
	char	**src;
	char	**dest_tb;
	t_list	*tmp;

	if (!check_move(ant, dest, ant_hill))
		return (0);
	tmp = ant_hill->rooms;
	while (tmp && ft_strcmp(ant->room, ((char**)tmp->content)[0]))
		tmp = tmp->next;
	src = ((char**)tmp->content);
	tmp = ant_hill->rooms;
	while (tmp && ft_strcmp(dest, ((char**)tmp->content)[0]))
		tmp = tmp->next;
	dest_tb = ((char**)tmp->content);
	free(ant->room);
	if (!(ant->room = ft_strdup(dest)))
		return (0);
	ft_printf("L%d-%s ", ant->id, ant->room);
	max = get_max(ant_hill);
	if (win)
		anim_ant(win, src, dest_tb, max);
	free(max);
	return (1);
}

void		free_paths(t_list **paths)
{
	t_list	*path;
	t_list	*tmp;

	path = NULL;
	tmp = NULL;
	while (*paths)
	{
		path = (t_list*)((*paths)->content);
		ft_lstdel(&path, del1);
		tmp = *paths;
		*paths = (*paths)->next;
		free(tmp);
	}
}

static int	shortcut(t_ant_hill *ant_hill, t_list *path)
{
	t_list	*tmp;
	t_list	*new;

	tmp = ant_hill->tubes;
	while (tmp)
	{
		if ((!ft_strcmp(((char**)tmp->content)[0], ant_hill->start) && \
			!ft_strcmp(((char**)tmp->content)[1], ant_hill->end)) || \
			(((char**)tmp->content)[2][0] == '0' && \
			!ft_strcmp(((char**)tmp->content)[1], ant_hill->start) && \
			!ft_strcmp(((char**)tmp->content)[0], ant_hill->end)))
		{
			if (!(path = ft_lstnew(ant_hill->start, ft_strlen(ant_hill->start) \
				* sizeof(char) + 1)) || !(new = ft_lstnew(ant_hill->end, \
				ft_strlen(ant_hill->end) * sizeof(char) + 1)))
				return (0);
			ft_lstaddend(&path, new);
			if (!(ant_hill->paths = ft_lstnew(path, 3 * sizeof(t_list*))))
				return (0);
			free(path);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int			algo(t_ant_hill *ant_hill, t_win *win)
{
	t_list	*path;

	path = NULL;
	if (ant_hill->start && ant_hill->end && !(shortcut(ant_hill, path)))
	{
		if (!(get_paths(ant_hill, &path, &ant_hill->paths, ant_hill->start)) ||\
				!ant_hill->paths)
		{
			ft_lstdel(&path, del1);
			return (0);
		}
	}
	if (win)
		SDL_Delay(2000);
	if (ant_hill->paths)
		if (!exec(ant_hill))
		{
			ft_lstdel(&path, del1);
			return (0);
		}
	ft_lstdel(&path, del1);
	return (1);
}
