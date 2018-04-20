/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_lem_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:54:30 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/20 15:41:09 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_lem_in.h"

SDL_Window	*w_init(void)
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;

	window = NULL;
	renderer = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		ft_printf("SDL_ERROR\n");
		return (NULL);
	}
	window = SDL_CreateWindow("Lem-in", 0, 0, 1200, 800, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (!window || !renderer)
	{
		ft_printf("SDL_ERROR\n");
		SDL_Quit();
		return (NULL);
	}
	return (window);
}

void		draw(SDL_Window *window, int x, int y)
{
	SDL_Rect		rect;
	SDL_Renderer	*renderer;

	renderer = SDL_GetRenderer(window);
	rect.x = x;
	rect.y = y;
	rect.h = 80;
	rect.w = 80;
	SDL_SetRenderDrawColor(renderer, 123, 103, 81, 255);
	SDL_RenderFillRect(renderer, &rect);
}

static void	draw_dot(SDL_Window *window, int x, int y)
{
	SDL_Rect		rect;
	SDL_Renderer	*renderer;

	renderer = SDL_GetRenderer(window);
	rect.x = x;
	rect.y = y;
	rect.w = 10;
	rect.h = 10;
	SDL_SetRenderDrawColor(renderer, 166, 144, 118, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void		draw_line(SDL_Window *win, int *coords)
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

void		w_clear(SDL_Window *window)
{
	SDL_SetRenderDrawColor(SDL_GetRenderer(window), 242, 241, 223, 255);
	SDL_RenderClear(SDL_GetRenderer(window));
}
