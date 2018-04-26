/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_lem_in3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 02:47:23 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/26 19:09:09 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/lem_in.h"

static int	*move_coords(char **src, char **dest, int *max)
{
	int		*coords;

	if (!(coords = (int*)malloc(4 * sizeof(int))))
		return (NULL);
	coords[0] = 75 + (1000 * ft_atoi(src[1]) / max[0]);
	coords[1] = 75 + (600 * ft_atoi(src[2]) / max[1]);
	coords[2] = 75 + (1000 * ft_atoi(dest[1]) / max[0]);
	coords[3] = 75 + (600 * ft_atoi(dest[2]) / max[1]);
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
	while (div--)
	{
		clip.x = pos.x - 8;
		clip.y = pos.y - 8;
		clip.w = 52;
		clip.h = 52;
		draw_ant(win, (int)pos.x, (int)pos.y);
		pos.x += move.x;
		pos.y += move.y;
		(div) ? SDL_RenderCopy(win->renderer, win->bg, &clip, &clip) : 0;
	}
}

int			draw_ant(t_win *win, int x, int y)
{
	static SDL_Surface		*surface;
	SDL_Texture				*image;
	SDL_Rect				rect;

	image = NULL;
	if (!(surface = SDL_LoadBMP("SDL/ant.bmp")))
		return (0);
	image = SDL_CreateTextureFromSurface(win->renderer, surface);
	rect.x = x;
	rect.y = y;
	SDL_QueryTexture(image, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(win->renderer, image, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(image);
	SDL_RenderPresent(win->renderer);
	return (1);
}
