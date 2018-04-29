/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/29 18:39:56 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int				*get_max(t_ant_hill *ant_hill)
{
	t_list		*tmp;
	int			*tab;
	int			x_max;
	int			y_max;

	if (!(tab = (int*)malloc(2 * sizeof(int))))
		return (NULL);
	x_max = 0;
	y_max = 0;
	tmp = ant_hill->rooms;
	while (tmp)
	{
		if (ft_atoi(((char**)tmp->content)[1]) > x_max)
			x_max = ft_atoi(((char**)tmp->content)[1]);
		if (ft_atoi(((char**)tmp->content)[2]) > y_max)
			y_max = ft_atoi(((char**)tmp->content)[2]);
		tmp = tmp->next;
	}
	if (x_max == 0)
		x_max = 1;
	if (y_max == 0)
		y_max = 1;
	tab[0] = x_max;
	tab[1] = y_max;
	return (tab);
}

static int		visu_rooms(t_ant_hill *ant_hill,  t_win *win)
{
	t_list			*tmp;
	int				*max;

	if (!(max = get_max(ant_hill)))
		return (0);
	tmp = ant_hill->rooms;
	while (tmp)
	{
		if (!draw(win, 50 + (1000 * ft_atoi(((char**)tmp->content)[1]) / \
		max[0]), 100 + (600 * ft_atoi(((char**)tmp->content)[2]) / max[1]), 80)\
		|| !draw_text(win, (char**)tmp->content, max))
		{
			free(max);
			return (0);
		}
		if (!ft_strcmp(((char**)tmp->content)[0], ant_hill->start))
			draw_flag(win, 50 + (1000 * ft_atoi(((char**)tmp->content)[1]) / \
		max[0]), 100 + (600 * ft_atoi(((char**)tmp->content)[2]) / max[1]), 1);
		else if (!ft_strcmp(((char**)tmp->content)[0], ant_hill->end))
			draw_flag(win, 50 + (1000 * ft_atoi(((char**)tmp->content)[1]) / \
		max[0]), 100 + (600 * ft_atoi(((char**)tmp->content)[2]) / max[1]), 2);
		tmp = tmp->next;
	}
	free(max);
	return (1);
}

int				*get_coords(t_ant_hill *ant_hill, char **tube, int *tab)
{
	t_list	*tmp;
	int		*max;

	tmp = ant_hill->rooms;
	max = get_max(ant_hill);
	while (tmp)
	{
		if (!ft_strcmp(tube[0], ((char**)tmp->content)[0]))
		{
			tab[0] = 90 + (1000 * ft_atoi(((char**)tmp->content)[1]) / max[0]);
			tab[1] = 140 + (600 * ft_atoi(((char**)tmp->content)[2]) / max[1]);
		}
		tmp = tmp->next;
	}
	tmp = ant_hill->rooms;
	while (tmp)
	{
		if (!ft_strcmp(tube[1], ((char**)tmp->content)[0]))
		{
			tab[2] = 90 + (1000 * ft_atoi(((char**)tmp->content)[1]) / max[0]);
			tab[3] = 140 + (600 * ft_atoi(((char**)tmp->content)[2]) / max[1]);
		}
		tmp = tmp->next;
	}
	return (tab);
}

static t_win	*visu_tubes(t_ant_hill *ant_hill, t_win *win)
{
	t_list		*tmp;
	int			*coords;

	tmp = ant_hill->tubes;
	if (!(win = w_init()))
		return (NULL);
	SDL_SetRenderTarget(win->renderer, win->bg);
	if (!(coords = (int*)malloc(4 * sizeof(int))))
		return (NULL);
	if (!w_clear(win))
	{
		free(coords);
		return (NULL);
	}
	while (tmp)
	{
		coords = get_coords(ant_hill, (char**)tmp->content, coords);
		draw_line(win, coords);
		tmp = tmp->next;
	}
	free(coords);
	return (win);
}

t_win			*visu(t_ant_hill *ant_hill, t_win *win)
{
	t_list		*tmp;
	SDL_Rect	rect;

	rect.x = 0;
	rect.y = 0;
	tmp = ant_hill->rooms;
	if (!(win = visu_tubes(ant_hill, win)))
		return (NULL);
	if (!visu_rooms(ant_hill, win))
		return (NULL);
	SDL_SetRenderTarget(win->renderer, NULL);
	SDL_QueryTexture(win->bg, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(win->renderer, win->bg, NULL, &rect);
	SDL_RenderPresent(win->renderer);
	return (win);
}
