/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_lem_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:54:30 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/20 22:40:53 by eparisot         ###   ########.fr       */
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

void		draw_flag(SDL_Window *window, int x, int y, int flag)
{
	SDL_Rect		rect;
	SDL_Renderer	*renderer;

	renderer = SDL_GetRenderer(window);
	rect.x = x;
	rect.y = y - 20;
	rect.h = 20;
	rect.w = 5;
	SDL_SetRenderDrawColor(renderer, 93, 77, 60, 255);
	SDL_RenderFillRect(renderer, &rect);
	rect.x = x + 5;
	rect.y = y - 20;
	rect.h = 10;
	rect.w = 10;
	if (flag == 1)
		SDL_SetRenderDrawColor(renderer, 204, 0, 0, 255);
	else if (flag == 2)
		SDL_SetRenderDrawColor(renderer, 0, 153, 0, 255);
	SDL_RenderFillRect(renderer, &rect);
}

void		draw_text(char **room, int *max, SDL_Window *window)
{(void)max;
	TTF_Font		*font;
	const SDL_Color	black = {0, 0, 0, 255};
	SDL_Surface		*surface;
	SDL_Texture		*text;
	SDL_Rect		rect;

	if (TTF_Init() == -1)
		return ;
	font = TTF_OpenFont("/Library/Fonts/Arial.ttf", 20);
	surface = TTF_RenderText_Solid(font, room[0], black);
	text = SDL_CreateTextureFromSurface(SDL_GetRenderer(window), surface);
	rect.x = 50 + (1000 * ft_atoi(room[1]) / max[0]);
	rect.y = 130 + (600 * ft_atoi(room[2]) / max[1]);
	rect.w = 20;
	rect.h = 20;
	SDL_RenderCopy(SDL_GetRenderer(window), text, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(text);
	TTF_CloseFont(font);
	TTF_Quit();
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
