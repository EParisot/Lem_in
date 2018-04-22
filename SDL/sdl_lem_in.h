/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_lem_in.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:02:34 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/22 13:33:38 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_LEM_IN_H

# define SDL_LEM_IN_H
# define ABS_MAX(x, y) ((abs(x) > abs(y)) ? abs(x) : abs(y))

# include <SDL.h>
# include <SDL_ttf.h>
# include "../libft/libft.h"
# include "../printf/srcs/ft_printf.h"
# include "../srcs/lem_in.h"

typedef struct		s_2dvector
{
	float			x;
	float			y;
}					t_2dvector;

SDL_Window			*w_init(void);
void				draw(SDL_Window *window, int x, int y);
void				draw_text(char **room, int *max, SDL_Window *window);
void				draw_flag(SDL_Window *window, int x, int y, int flag);
void				draw_line(SDL_Window *window, int *coords);
void				draw_ant(SDL_Window *window, int x, int y);
void				anim_ant(SDL_Window *window, char **src, char **dest, \
							int* max);
void				w_clear(SDL_Window *window);
void				w_destroy(SDL_Window *window);

#endif
