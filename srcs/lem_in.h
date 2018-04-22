/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:11:24 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/22 18:47:02 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "../libft/libft.h"
# include "../printf/srcs/ft_printf.h"
# include "../GNL/get_next_line.h"
# include "../SDL/sdl_lem_in.h"

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

int					read_data(t_ant_hill *ant_hill, char *line);
int					check_ant_hill(t_ant_hill *ant_hill);
char				**parse_rooms(char *line);
char				**parse_tubes(char *line);
int					*get_max(t_ant_hill *ant_hill);
int					*get_coords(t_ant_hill *ant_hill, char **tube, int *tab);
SDL_Window			*visu(t_ant_hill *ant_hill);
void				print_input(t_ant_hill *ant_hill);
int					lem_in(t_ant_hill *ant_hill, SDL_Window *Window, int ac, \
							char **av);

#endif
