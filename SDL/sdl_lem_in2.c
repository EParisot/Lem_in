/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_lem_in2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:54:30 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/22 22:56:40 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/lem_in.h"

void		draw_flag(t_win *win, int x, int y, int flag)
{
	SDL_Rect		rect;

	rect.x = x;
	rect.y = y - 20;
	rect.h = 20;
	rect.w = 5;
	SDL_SetRenderDrawColor(win->renderer, 93, 77, 60, 255);
	SDL_RenderFillRect(win->renderer, &rect);
	rect.x = x + 5;
	rect.y = y - 20;
	rect.h = 10;
	rect.w = 10;
	if (flag == 1)
		SDL_SetRenderDrawColor(win->renderer, 204, 0, 0, 255);
	else if (flag == 2)
		SDL_SetRenderDrawColor(win->renderer, 0, 153, 0, 255);
	SDL_RenderFillRect(win->renderer, &rect);
}

void		draw_text(t_win *win, char **room, int *max)
{
	TTF_Font		*font;
	const SDL_Color	black = {0, 0, 0, 255};
	SDL_Surface		*surface;
	SDL_Texture		*text;
	SDL_Rect		rect;

	if (TTF_Init() == -1)
		return ;
	surface = NULL;
	text = NULL;
	if ((font = TTF_OpenFont("SDL/Arial.ttf", 20)))
	{
		surface = TTF_RenderText_Solid(font, room[0], black);
		text = SDL_CreateTextureFromSurface(win->renderer, surface);
		rect.x = 50 + (1000 * ft_atoi(room[1]) / max[0]);
		rect.y = 130 + (600 * ft_atoi(room[2]) / max[1]);
		rect.w = 20;
		rect.h = 20;
		SDL_RenderCopy(win->renderer, text, NULL, &rect);
	}
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(text);
	TTF_CloseFont(font);
	TTF_Quit();
}

static void	draw_dot(t_win *win, int x, int y)
{
	SDL_Rect		rect;

	rect.x = x;
	rect.y = y;
	rect.w = 10;
	rect.h = 10;
	SDL_SetRenderDrawColor(win->renderer, 166, 144, 118, 255);
	SDL_RenderFillRect(win->renderer, &rect);
}

void		draw_line(t_win *win, int *coords)
{
	int			div;
	int			i;
	t_2dvector	pos;
	t_2dvector	move;

	i = 0;
	pos.x = coords[0];
	pos.y = coords[1];
	move.x = coords[2] - coords[0];
	move.y = coords[3] - coords[1];
	div = ABS_MAX(coords[2] - coords[0], coords[3] - coords[1]);
	move.x = move.x / div;
	move.y = move.y / div;
	while (i < div)
	{
		draw_dot(win, (int)pos.x, (int)pos.y);
		pos.x += move.x;
		pos.y += move.y;
		i++;
	}
}

void		draw_ant(t_win *win, int x, int y)
{
	SDL_Surface		*surface;
	SDL_Texture		*image;
	SDL_Rect		rect;

	surface = NULL;
	image = NULL;
	if ((surface = SDL_LoadBMP("SDL/ant.bmp")))
	{
		image = SDL_CreateTextureFromSurface(win->renderer, surface);
		rect.x = x;
		rect.y = y;
		SDL_QueryTexture(image, NULL, NULL, &rect.w, &rect.h);
		SDL_RenderCopy(win->renderer, image, NULL, &rect);
		
	}
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(image);
	SDL_RenderPresent(win->renderer);
}
