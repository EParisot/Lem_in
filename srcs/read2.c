/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/24 21:30:24 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	read2_bis(t_ant_hill *ant_hill, char *line, t_list *tmp_lst, \
		char **tb)
{
	tb = parse_rooms(line);
	if (!ant_hill->rooms->content)
	{
		ant_hill->rooms->content = tb;
		ant_hill->start = tb[0];
	}
	else
	{
		if (!(tmp_lst = ft_lstnew(tb, 4 * sizeof(char*))) || line[0] == 'L')
			return (0);
		ft_lstaddend(&(ant_hill->rooms), tmp_lst);
		ant_hill->start = tb[0];
		free(tb);
	}
	return (1);
}

static int	read2_ter(t_ant_hill *ant_hill, char *line, t_list *tmp_lst, \
		char **tb)
{
	tb = parse_rooms(line);
	if (!ant_hill->rooms->content)
	{
		ant_hill->rooms->content = tb;
		ant_hill->end = tb[0];
	}
	else
	{
		if (!(tmp_lst = ft_lstnew(tb, 4 * sizeof(char*))) || line[0] == 'L')
			return (0);
		ft_lstaddend(&(ant_hill->rooms), tmp_lst);
		ant_hill->end = tb[0];
		free(tb);
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
		if (!(read2_bis(ant_hill, *tmp, tmp_lst, tb)))
			return (0);
	}
	else if (!ft_strcmp(line, "##end"))
	{
		if (!(read2_ter(ant_hill, *tmp, tmp_lst, tb)))
			return (0);
	}
	free(*tmp);
	free(tmp);
	return (1);
}

int			read2(t_ant_hill *ant_hill, char *line)
{
	t_list		*tmp_lst;

	tmp_lst = NULL;
	if (line[0] == '#' && line[1] == '#')
		if (!read2bis(ant_hill, line, tmp_lst))
			return (0);
	return (1);
}
