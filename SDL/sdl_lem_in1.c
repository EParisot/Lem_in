/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_lem_in1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:54:30 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/24 02:01:21 by eparisot         ###   ########.fr       */
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
	SDL_SetRenderDrawColor(win->renderer, 174, 154, 132, 255);
	SDL_RenderFillRect(win->renderer, &rect);
}

int			w_clear(t_win *win)
{
	SDL_Surface		*surface;
	SDL_Texture		*image;
	SDL_Rect		rect;

	surface = NULL;
	image = NULL;
	if (!(surface = SDL_LoadBMP("SDL/minecraft.bmp")))
		return (0);
	image = SDL_CreateTextureFromSurface(win->renderer, surface);
	rect.x = 0;
	rect.y = 0;
	rect.w = 1200;
	rect.h = 800;
	SDL_RenderCopy(win->renderer, image, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(image);
	SDL_RenderPresent(win->renderer);
	return (1);
}

void		w_destroy(t_win *win)
{
	SDL_Delay(5000);
	if (win)
	{
		SDL_DestroyRenderer(win->renderer);
		SDL_DestroyWindow(win->window);
		SDL_DestroyTexture(win->bg);
	}
	SDL_Quit();
}
