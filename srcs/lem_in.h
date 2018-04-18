/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:11:24 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/18 22:56:54 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

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

#endif

