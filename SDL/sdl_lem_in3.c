/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_lem_in3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 02:47:23 by eparisot          #+#    #+#             */
/*   Updated: 2018/05/03 12:46:35 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/lem_in.h"

static int	*move_coords(char **src, char **dest, int *max)
{
	int		*coords;

	if (!(coords = (int*)malloc(4 * sizeof(int))))
		return (NULL);
	coords[0] = 75 + (1000 * ft_atoi(src[1]) / max[0]);
	coords[1] = 125 + (600 * ft_atoi(src[2]) / max[1]);
	coords[2] = 75 + (1000 * ft_atoi(dest[1]) / max[0]);
	coords[3] = 125 + (600 * ft_atoi(dest[2]) / max[1]);
	return (coords);
}

void		anim_ant(t_win *win, char **src, char **dest, int *max)
{
	int		*coords;
	int			div;
	t_2dvector	pos;
	t_2dvector	move;
	SDL_Rect	clip;

	coords = move_coords(src, dest, max);
	pos.x = coords[0];
	pos.y = coords[1];
	move.x = coords[2] - coords[0];
	move.y = coords[3] - coords[1];
	div = ABS_MAX(coords[2] - coords[0], coords[3] - coords[1]) / 4;
	move.x = move.x / div;
	move.y = move.y / div;
	while (div-- && draw_ant(win, (int)pos.x, (int)pos.y))
	{
		clip.x = pos.x - 8;
		clip.y = pos.y - 8;
		clip.w = 52;
		clip.h = 52;
		pos.x += move.x;
		pos.y += move.y;
		(div) ? SDL_RenderCopy(win->renderer, win->bg, &clip, &clip) : 0;
	}
	free(coords);
}

int			draw_ant(t_win *win, int x, int y)
{
	SDL_Rect				rect;

	rect.x = x;
	rect.y = y;
	SDL_QueryTexture(win->ant, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(win->renderer, win->ant, NULL, &rect);
	SDL_RenderPresent(win->renderer);
	return (1);
}
