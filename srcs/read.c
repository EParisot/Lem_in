/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/23 17:50:38 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		tb = parse_rooms(line);
		if (!(tmp_lst = ft_lstnew(tb, 4 * sizeof(char*))))
			return (0);
		ft_lstadd(&(ant_hill->rooms), tmp_lst);
	}
	else if (line[0] != '#' && line[0] != 'L' && ft_strchr(line, '-'))
	{
		tb = parse_tubes(line);
		if (!(tmp_lst = ft_lstnew(tb, 3 * sizeof(char*))))
			return (0);
		ft_lstadd(&(ant_hill->tubes), tmp_lst);
	}
	free(tb);
	return (1);
}

static void	clean(char **tb, char **tmp)
{
	free(tb);
	free(*tmp);
	free(tmp);
}

static int	read2bis(t_ant_hill *ant_hill, char *line, t_list *tmp_lst)
{
	char		**tmp;
	char		**tb;

	tb = NULL;
	if (!(tmp = (char **)malloc(sizeof(char *))))
		return (0);
	get_next_line(0, tmp);
	if (!ft_strcmp(line, "##start"))
	{
		tb = parse_rooms(*tmp);
		if (!(tmp_lst = ft_lstnew(tb, 4 * sizeof(char*))) || *tmp[0] == 'L')
			return (0);
		ft_lstadd(&(ant_hill->rooms), tmp_lst);
		ant_hill->start = tb[0];
	}
	else if (!ft_strcmp(line, "##end"))
	{
		tb = parse_rooms(*tmp);
		if (!(tmp_lst = ft_lstnew(tb, 4 * sizeof(char*))) || *tmp[0] == 'L')
			return (0);
		ft_lstadd(&(ant_hill->rooms), tmp_lst);
		ant_hill->end = tb[0];
	}
	clean(tb, tmp);
	return (1);
}

static int	read2(t_ant_hill *ant_hill, char *line)
{
	t_list		*tmp_lst;

	tmp_lst = NULL;
	if (line[0] == '#' && line[1] == '#')
		if (!read2bis(ant_hill, line, tmp_lst))
			return (0);
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
