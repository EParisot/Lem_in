/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:39:14 by eparisot          #+#    #+#             */
/*   Updated: 2018/05/04 20:11:57 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_ants(t_ant_hill *ant_hill)
{
	t_list	*tmp;
	t_list	*tmp_rooms;
	int		*max;

	max = get_max(ant_hill);
	tmp = ant_hill->ants;
	while (tmp)
	{
		tmp_rooms = ant_hill->rooms;
		while (tmp_rooms)
		{
			if (!ft_strcmp(((char**)tmp_rooms->content)[0], \
						((t_ant*)tmp->content)->room))
			{
				SDL_SetRenderTarget(ant_hill->win->renderer, ant_hill->win->bg);
				draw_ant(ant_hill->win, 76 + (1000 * ft_atoi(((char**)\
				tmp_rooms->content)[1]) / max[0]), 126 + (600 * \
				ft_atoi(((char**)tmp_rooms->content)[2]) / max[1]));
				SDL_SetRenderTarget(ant_hill->win->renderer, NULL);
			}
			tmp_rooms = tmp_rooms->next;
		}
		tmp = tmp->next;
	}
	free(max);
}

static int	find_move(t_ant_hill *a_h, t_list *paths, t_list *ants, size_t min)
{
	t_list	*path;

	while (paths)
	{
		path = paths->content;
		if (ft_lstcount((t_list*)paths->content) == min)
			while (path && path->next)
			{
				if (!ft_strcmp((char*)((t_ant*)ants->content)->room, \
					(char*)path->content))
					if (rie((char*)((t_list*)path->next)->content, a_h->ants) \
						|| !ft_strcmp((char*)((t_list*)path->next)->content, \
								a_h->end))
					{
						if (!move_ant(ants->content, \
						(char*)((t_list*)path->next)->content, a_h, a_h->win))
							return (-1);
						(a_h->win) ? print_ants(a_h) : 0;
						return (1);
					}
				path = path->next;
			}
		paths = paths->next;
	}
	return (0);
}

static int	select_path(t_ant_hill *ant_hill, t_list *paths, t_list *ants)
{
	size_t	min;
	size_t	max;
	int		ret;

	min = smallest_path_len(paths);
	max = biggest_path_len(paths);
	while (min <= max)
	{
		ret = find_move(ant_hill, paths, ants, min);
		if (ret == 1)
			return (1);
		else if (ret == -1)
			return (0);
		min++;
		paths = ant_hill->paths;
	}
	return (1);
}

int			exec(t_ant_hill *ant_hill)
{
	t_list	*tmp_ants;
	t_list	*tmp_paths;

	tmp_ants = ant_hill->ants;
	tmp_paths = NULL;
	while (!is_over(ant_hill, tmp_ants))
	{
		while (tmp_ants)
		{
			tmp_paths = ant_hill->paths;
			if (ft_strcmp((char*)((t_ant*)tmp_ants->content)->room, \
						ant_hill->end))
				if (!select_path(ant_hill, tmp_paths, tmp_ants))
					return (0);
			tmp_ants = tmp_ants->next;
		}
		tmp_ants = ant_hill->ants;
		ft_putchar('\n');
	}
	return (1);
}
