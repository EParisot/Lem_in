/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:05:50 by eparisot          #+#    #+#             */
/*   Updated: 2018/05/09 19:00:58 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read3(t_ant_hill *ant_hill, char *tmp, t_list *tmp_lst, char **tb)
{
	if (!(tb = parse_tubes(tmp, 1)))
		return (0);
	if (!ant_hill->tubes)
	{
		if (!(ant_hill->tubes = ft_lstnew(tb, 3 * sizeof(char*))))
			return (0);
	}
	else if (!tube_exists(ant_hill, tb))
	{
		if (!(tmp_lst = ft_lstnew(tb, 3 * sizeof(char*))))
			return (0);
		ft_lstaddend(&(ant_hill->tubes), tmp_lst);
	}
	free(tb);
	return (1);
}

int		room_exists(t_ant_hill *ant_hill, char **tb)
{
	t_list	*tmp;

	tmp = ant_hill->rooms;
	while (tmp)
	{
		if (!ft_strcmp(tb[0], ((char**)tmp->content)[0]))
		{
			ft_memcpy(tmp->content, tb, 3 * sizeof(char*));
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		tube_exists(t_ant_hill *ant_hill, char **tb)
{
	t_list	*tmp;

	tmp = ant_hill->tubes;
	while (tmp)
	{
		if (!ft_strcmp(tb[0], ((char**)tmp->content)[0]) && \
		!ft_strcmp(tb[1], ((char**)tmp->content)[1]))
		{
			ft_memcpy(tmp->content, tb, 3 * sizeof(char*));
			return (1);
		}
		else if (!ft_strcmp(tb[0], ((char**)tmp->content)[1]) && \
		!ft_strcmp(tb[1], ((char**)tmp->content)[0]))
		{
			if (((char**)tmp->content)[2][0] == '1' && tb[2][0] == '1')
				tb[2][0] = '0';
			ft_memcpy(tmp->content, tb, 3 * sizeof(char*));
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		p_c(t_ant_hill *ant_hill, char **line)
{
	while (*line[0] == '#')
	{
		if (!read_data(ant_hill, *line))
			return (0);
		get_next_line(0, line);
	}
	return (1);
}
