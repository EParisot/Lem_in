/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:11:24 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/22 23:28:17 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H
# define ABS_MAX(x, y) ((abs(x) > abs(y)) ? abs(x) : abs(y))

# include <SDL.h>
# include <SDL_ttf.h>
# include "../libft/libft.h"
# include "../printf/srcs/ft_printf.h"
# include "../GNL/get_next_line.h"

typedef struct		s_ant_hill
{
	int				ant_nb;
	char			*start;
	char			*end;
	t_list			*rooms;
	t_list			*tubes;
}					t_ant_hill;

typedef struct		s_ant
{
	int				id;
	char			*room;
}					t_ant;

typedef struct		s_2dvector
{
	float			x;
	float			y;
}					t_2dvector;

typedef struct		s_win
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*bg;
}					t_win;

t_win*				w_init(void);
void				draw(t_win *win, int x, int y);
void				draw_text(t_win *win, char **room, int *max);
void				draw_flag(t_win *win, int x, int y, int flag);
void				draw_line(t_win *win, int *coords);
void				draw_ant(t_win *win, int x, int y);
void				anim_ant(t_win *win, char **src, char **dest, int* max);
void				w_clear(t_win *win);
void				w_destroy(t_win *win);

int					read_data(t_ant_hill *ant_hill, char *line);
int					check_ant_hill(t_ant_hill *ant_hill);
char				**parse_rooms(char *line);
char				**parse_tubes(char *line);
int					*get_max(t_ant_hill *ant_hill);
int					*get_coords(t_ant_hill *ant_hill, char **tube, int *tab);
t_win				*visu(t_ant_hill *ant_hill, t_win *win);
void				print_input(t_ant_hill *ant_hill);
int					lem_in(t_ant_hill *ant_hill, t_win *win, int ac, char **av);

#endif
