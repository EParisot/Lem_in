/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_lem_in1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 18:54:30 by eparisot          #+#    #+#             */
/*   Updated: 2018/05/04 20:23:33 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../srcs/lem_in.h"

static int	load_img(t_win *win)
{
	SDL_Surface	*surf1;
	SDL_Surface	*surf2;
	SDL_Surface	*surf3;

	if (!(surf1 = SDL_LoadBMP("SDL/room.bmp")))
		return (0);
	if (!(win->room = SDL_CreateTextureFromSurface(win->renderer, surf1)))
		return (0);
	if (!(surf2 = SDL_LoadBMP("SDL/ant.bmp")))
		return (0);
	if (!(win->ant = SDL_CreateTextureFromSurface(win->renderer, surf2)))
		return (0);
	if (!(surf3 = SDL_LoadBMP("SDL/sign.bmp")))
		return (0);
	if (!(win->sign = SDL_CreateTextureFromSurface(win->renderer, surf3)))
		return (0);
	return (1);
}

t_win		*w_init(void)
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
	if (!win->window || !win->renderer || !win->bg || !load_img(win))
	{
		SDL_Quit();
		return (NULL);
	}
	SDL_SetRenderTarget(win->renderer, win->bg);
	if (!w_clear(win))
		return (NULL);
	return (win);
}

int			w_clear(t_win *win)
{
	SDL_Surface		*surface;
	SDL_Texture		*image;
	SDL_Rect		rect;

	if (!(surface = SDL_LoadBMP("SDL/minecraft.bmp")))
		return (0);
	image = SDL_CreateTextureFromSurface(win->renderer, surface);
	rect.x = 0;
	rect.y = 0;
	SDL_QueryTexture(image, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(win->renderer, image, NULL, &rect);
	SDL_RenderPresent(win->renderer);
	SDL_DestroyTexture(image);
	SDL_FreeSurface(surface);
	return (1);
}

int			draw(t_win *win, int x, int y, int w)
{
	SDL_Rect		rect;

	rect.x = x;
	rect.y = y;
	rect.h = w;
	rect.w = w;
	SDL_RenderCopy(win->renderer, win->room, NULL, &rect);
	SDL_RenderPresent(win->renderer);
	return (1);
}

void		w_destroy(t_win *win)
{
	SDL_Delay(2000);
	if (win)
	{
		SDL_DestroyTexture(win->sign);
		SDL_DestroyTexture(win->room);
		SDL_DestroyTexture(win->ant);
		SDL_DestroyTexture(win->bg);
		SDL_DestroyRenderer(win->renderer);
		SDL_DestroyWindow(win->window);
	}
	SDL_Quit();
}
