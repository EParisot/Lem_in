/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/20 12:37:07 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	read1(t_ant_hill *ant_hill, char *line)
{
	t_list		*tmp_lst;
	char		**tb;

	tmp_lst = NULL;
	tb = NULL;
	if (line[0] != '#' && ft_isdigit(line[0]) && !ft_strchr(line, ' ') && \
		!ft_strchr(line, '-'))
		ant_hill->ant_nb = ft_atoi(line);
	else if (line[0] != '#' && ft_strchr(line, ' '))
	{
		if (!(tmp_lst = ft_lstnew((tb = parse_rooms(line)), 4 * sizeof(char*))))
			return (0);
		free(tb);
		ft_lstadd(&(ant_hill->rooms), tmp_lst);
	}
	else if (line[0] != '#' && ft_strchr(line, '-'))
	{
		if (!(tmp_lst = ft_lstnew((tb = parse_tubes(line)), 3 * sizeof(char*))))
			return (0);
		free(tb);
		ft_lstadd(&(ant_hill->tubes), tmp_lst);
	}
	return (1);
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
		if (!(tmp_lst = ft_lstnew((tb = parse_rooms(*tmp)), 4 * sizeof(char*))))
			return (0);
		ft_lstadd(&(ant_hill->rooms), tmp_lst);
		ant_hill->start = tb[0];
	}
	else if (!ft_strcmp(line, "##end"))
	{
		if (!(tmp_lst = ft_lstnew((tb = parse_rooms(*tmp)), 4 * sizeof(char*))))
			return (0);
		ft_lstadd(&(ant_hill->rooms), tmp_lst);
		ant_hill->end = tb[0];
	}
	free(tb);
	free(*tmp);
	free(tmp);
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
