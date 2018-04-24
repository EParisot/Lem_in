/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/24 20:51:52 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	read1_bis(t_ant_hill *ant_hill, char *line, t_list *tmp_lst, \
		char **tb)
{
	tb = parse_rooms(line);
	if (!ant_hill->rooms->content)
		ant_hill->rooms->content = tb;
	else
	{
		if (!(tmp_lst = ft_lstnew(tb, 4 * sizeof(char*))))
			return (0);
		ft_lstaddend(&(ant_hill->rooms), tmp_lst);
		free(tb);
	}
	return (1);
}

static int	read1_ter(t_ant_hill *ant_hill, char *line, t_list *tmp_lst, \
		char **tb)
{
	tb = parse_tubes(line);
	if (!ant_hill->tubes->content)
		ant_hill->tubes->content = tb;
	else
	{
		if (!(tmp_lst = ft_lstnew(tb, 3 * sizeof(char*))))
			return (0);
		ft_lstaddend(&(ant_hill->tubes), tmp_lst);
		free(tb);
	}
	return (1);
}

static int	read1(t_ant_hill *ant_hill, char *line)
{
	t_list		*tmp_lst;
	char		**tb;

	tmp_lst = NULL;
	tb = NULL;
	if (line[0] != '#' && line[0] != 'L' && ft_isdigit(line[0]) && \
	!ft_strchr(line, ' ') && !ft_strchr(line, '-'))
		ant_hill->ant_nb = ft_atoi(line);
	else if (line[0] != '#' && line[0] != 'L' && ft_strchr(line, ' '))
	{
		if (!(read1_bis(ant_hill, line, tmp_lst, tb)))
			return (0);
	}
	else if (line[0] != '#' && line[0] != 'L' && ft_strchr(line, '-'))
	{
		if (!(read1_ter(ant_hill, line, tmp_lst, tb)))
			return (0);
	}
	return (1);
}

int			read_data(t_ant_hill *ant_hill, char *line)
{
	if (!(read1(ant_hill, line)))
		return (0);
	if (!(read2(ant_hill, line)))
		return (0);
	return (1);
}
