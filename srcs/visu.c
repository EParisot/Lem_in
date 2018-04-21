/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/21 02:46:10 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int			*get_max(t_ant_hill *ant_hill)
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
	while (tmp->content)
	{
		if (ft_atoi(((char**)tmp->content)[1]) > x_max)
			x_max = ft_atoi(((char**)tmp->content)[1]);
		if (ft_atoi(((char**)tmp->content)[2]) > y_max)
			y_max = ft_atoi(((char**)tmp->content)[2]);
		tmp = tmp->next;
	}
	tab[0] = x_max;
	tab[1] = y_max;
	return (tab);
}

static void			visu_rooms(t_ant_hill *ant_hill, SDL_Window *window)
{
	t_list			*tmp;
	int				*max;

	if (!(max = get_max(ant_hill)))
		return ;
	tmp = ant_hill->rooms;
	//draw_text((char**)tmp->content, max, window);
	while (tmp->content)
	{
		draw_text((char**)tmp->content, max, window);
		draw(window, 50 + (1000 * ft_atoi(((char**)tmp->content)[1]) / max[0]),\
					50 + (600 * ft_atoi(((char**)tmp->content)[2]) / max[1]));
		if (!ft_strcmp(((char**)tmp->content)[0], ant_hill->start))
			draw_flag(window, 50 + (1000 * ft_atoi(((char**)tmp->content)[1])\
		/ max[0]), 50 + (600 * ft_atoi(((char**)tmp->content)[2]) / max[1]), 1);
		else if (!ft_strcmp(((char**)tmp->content)[0], ant_hill->end))
			draw_flag(window, 50 + (1000 * ft_atoi(((char**)tmp->content)[1])\
		/ max[0]), 50 + (600 * ft_atoi(((char**)tmp->content)[2]) / max[1]), 2);
		tmp = tmp->next;
	}
	free(max);
}

static int			*get_coords(t_ant_hill *ant_hill, char **tube, int *tab)
{
	t_list	*tmp;
	int		*max;

	tmp = ant_hill->rooms;
	max = get_max(ant_hill);
	while (tmp->content)
	{
		if (!ft_strcmp(tube[0], ((char**)tmp->content)[0]))
		{
			tab[0] = 90 + (1000 * ft_atoi(((char**)tmp->content)[1]) / max[0]);
			tab[1] = 90 + (600 * ft_atoi(((char**)tmp->content)[2]) / max[1]);
		}
		tmp = tmp->next;
	}
	tmp = ant_hill->rooms;
	while (tmp->content)
	{
		if (!ft_strcmp(tube[1], ((char**)tmp->content)[0]))
		{
			tab[2] = 90 + (1000 * ft_atoi(((char**)tmp->content)[1]) / max[0]);
			tab[3] = 90 + (600 * ft_atoi(((char**)tmp->content)[2]) / max[1]);
		}
		tmp = tmp->next;
	}
	return (tab);
}

static SDL_Window	*visu_tubes(t_ant_hill *ant_hill, SDL_Window *window)
{
	t_list		*tmp;
	int			*coords;

	tmp = ant_hill->tubes;
	if (!(window = w_init()))
		return (NULL);
	if (!(coords = (int*)malloc(4 * sizeof(int))))
		return (NULL);
	w_clear(window);
	while (tmp->content)
	{
		coords = get_coords(ant_hill, (char**)tmp->content, coords);
		draw_line(window, coords);
		tmp = tmp->next;
	}
	free(coords);
	return (window);
}

void				visu(t_ant_hill *ant_hill)
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;

	window = NULL;
	renderer = NULL;
	if (!(window = visu_tubes(ant_hill, window)))
		return ;
	visu_rooms(ant_hill, window);
	//TODO
	draw_ant(window, 100, 100);
	//
	renderer = SDL_GetRenderer(window);
	SDL_RenderPresent(renderer);
	SDL_Delay(10000);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
