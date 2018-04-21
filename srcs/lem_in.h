/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:11:24 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/21 01:15:44 by eparisot         ###   ########.fr       */
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
	t_list			*path;
}					t_ant;

int					read_data(t_ant_hill *ant_hill, char *line);
int					check_ant_hill(t_ant_hill *ant_hill);
char				**parse_rooms(char *line);
char				**parse_tubes(char *line);
void				visu(t_ant_hill *ant_hill);

#endif
