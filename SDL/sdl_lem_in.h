/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_lem_in.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:02:34 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/20 03:08:10 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_PUSHSWAP_H

# define SDL_PUSHSWAP_H
# define abs_max(x, y) ((abs(x) > abs(y)) ? abs(x) : abs(y))

# include <SDL.h>
# include "../libft/libft.h"
# include "../printf/srcs/ft_printf.h"

typedef struct		s_2Dvector
{
	float			x;
	float			y;
}					t_2Dvector;

SDL_Window			*w_init(void);
void				draw(SDL_Window *window, int x, int y);
void				draw_line(SDL_Window *window, int *coords);
void				w_clear(SDL_Window *window);
void				w_destroy(SDL_Window *window);

#endif
