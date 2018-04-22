/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_lem_in3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 02:47:23 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/22 22:42:58 by eparisot         ###   ########.fr       */
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
	div = ABS_MAX(coords[2] - coords[0], coords[3] - coords[1]);
	move.x = move.x / div;
	move.y = move.y / div;
	while (div--)
	{
		clip.x = pos.x;
		clip.y = pos.y;
		clip.h = 32;;
		clip.w = 32;
		//SDL_RenderSetClipRect(SDL_GetRenderer(window), &clip);

		draw_ant(win, (int)pos.x, (int)pos.y);
		pos.x += move.x;
		pos.y += move.y;
		SDL_Delay(10);
	}
}
