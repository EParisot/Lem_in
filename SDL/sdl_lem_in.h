/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_lem_in.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:02:34 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/20 01:08:33 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_PUSHSWAP_H

# define SDL_PUSHSWAP_H

# include <SDL.h>
# include "../libft/libft.h"
# include "../printf/srcs/ft_printf.h"

SDL_Window			*w_init(void);
void				draw(SDL_Window *window, int x, int y);
void				w_clear(SDL_Window *window);
void				w_destroy(SDL_Window *window);

#endif
