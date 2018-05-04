/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:11:24 by eparisot          #+#    #+#             */
/*   Updated: 2018/05/04 16:23:02 by eparisot         ###   ########.fr       */
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

typedef struct		s_win
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*bg;
	SDL_Texture		*room;
	SDL_Texture		*ant;
}					t_win;

typedef struct		s_ant
{
	int				id;
	char			*room;
}					t_ant;

typedef struct		s_ant_hill
{
	int				ant_nb;
	char			*start;
	char			*end;
	t_list			*instru;
	t_list			*rooms;
	t_list			*tubes;
	t_list			*ants;
	t_list			*paths;
	t_win			*win;
}					t_ant_hill;

typedef struct		s_2dvector
{
	float			x;
	float			y;
}					t_2dvector;

t_win				*w_init(void);
int					draw(t_win *win, int x, int y, int w);
int					draw_text(t_win *win, char **room, int *max);
void				draw_flag(t_win *win, int x, int y, int flag);
void				draw_line(t_win *win, int *coords, char *one_way);
int					draw_ant(t_win *win, int x, int y);
void				anim_ant(t_win *win, char **src, char **dest, int *max);
int					w_clear(t_win *win);
void				w_destroy(t_win *win);
int					read_data(t_ant_hill *ant_hill, char *line);
int					save_instru(t_ant_hill *ant_hill, char *instru);
int					read2(t_ant_hill *ant_hill, char *line);
int					read3(t_ant_hill *ant_hill, char *tmp, t_list *tmp_lst, \
		char **tb);
void				del1(void *content, size_t content_size);
int					check_ant_hill(t_ant_hill *ant_hill);
char				**parse_rooms(char *line);
char				**parse_tubes(char *line, int one_way);
int					*get_max(t_ant_hill *ant_hill);
int					*get_coords(t_ant_hill *ant_hill, char **tube, int *tab, \
		int *max);
t_win				*visu(t_ant_hill *ant_hill, t_win *win);
void				print_input(t_ant_hill *ant_hill);
void				destroy_ants(t_list *ants);
int					lem_in(t_ant_hill *ant_hill, int ac, char **av);
int					algo(t_ant_hill *ant_hill, t_win *win);
int					move_ant(t_ant *ant, char *dest, t_ant_hill *ant_hill, \
		t_win *win);
int					get_paths(t_ant_hill *ant_hill, t_list **path, \
		t_list **paths, char *pos);
int					lst_cpy(t_list **dest, t_list *src);
int					end(t_list **path, t_list **paths);
int					is_over(t_ant_hill *ant_hill, t_list *ants);
int					smallest_path_len(t_list *paths);
int					biggest_path_len(t_list *paths);
int					rie(char *room, t_list *ants);
int					exec(t_ant_hill *ant_hill);
void				free_paths(t_list **paths);

#endif
