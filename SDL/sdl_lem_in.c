/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_lem_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:54:30 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/20 01:36:23 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_lem_in.h"

SDL_Window	*w_init(void)
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;

	window = NULL;
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
	SDL_Rect	r;

	r.x = x;
	r.y = y;
	r.h = 80;
	r.w = 80;
	SDL_SetRenderDrawColor(SDL_GetRenderer(window), 166, 144, 118, 255);
	SDL_RenderFillRect(SDL_GetRenderer(window), &r);
}

void			w_clear(SDL_Window *window)
{
	SDL_SetRenderDrawColor(SDL_GetRenderer(window), 242, 241, 223, 255);
	SDL_RenderClear(SDL_GetRenderer(window));
}

void			w_destroy(SDL_Window *window)
{
	SDL_DestroyRenderer(SDL_GetRenderer(window));
	SDL_DestroyWindow(window);
	SDL_Quit();
}
