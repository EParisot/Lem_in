/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_lem_in1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:54:30 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/22 22:57:34 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/lem_in.h"

t_win	*w_init(void)
{
	t_win			*win;

	if (!(win = (t_win*)malloc(sizeof(t_win*))))
		return (NULL);
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		ft_printf("SDL_ERROR\n");
		return (NULL);
	}
	win->window = SDL_CreateWindow("Lem-in", 0, 0, 1200, 800, 0);
	win->renderer = SDL_CreateRenderer(win->window, -1, \
		SDL_RENDERER_PRESENTVSYNC);
	win->bg = SDL_CreateTexture(win->renderer, SDL_PIXELFORMAT_RGBA8888, \
		SDL_TEXTUREACCESS_TARGET, 1200, 800);
	if (!win->window || !win->renderer || !win->bg)
	{
		ft_printf("SDL_ERROR\n");
		SDL_Quit();
		return (NULL);
	}
	return (win);
}

void		draw(t_win *win, int x, int y)
{
	SDL_Rect		rect;

	rect.x = x;
	rect.y = y;
	rect.h = 80;
	rect.w = 80;
	SDL_SetRenderDrawColor(win->renderer, 123, 103, 81, 255);
	SDL_RenderFillRect(win->renderer, &rect);
}

void		w_clear(t_win *win)
{
	SDL_SetRenderDrawColor(win->renderer, 242, 241, 223, 255);
	SDL_RenderClear(win->renderer);
}

void		w_destroy(t_win *win)
{
	SDL_Delay(5000);
	SDL_DestroyRenderer(win->renderer);
	SDL_DestroyWindow(win->window);
	SDL_DestroyTexture(win->bg);
	SDL_Quit();
	TTF_Quit();
}
