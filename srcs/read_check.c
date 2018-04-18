/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/19 00:11:59 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	read1(t_ant_hill *ant_hill, char *line)
{
	t_list		*tmp_lst;

	tmp_lst = NULL;
	if (ft_isdigit(line[0]) && !ft_strchr(line, ' ') && !ft_strchr(line, '-'))
		ant_hill->ant_nb = ft_atoi(line);
	else if (ft_strchr(line, ' '))
	{
		if (!(tmp_lst = ft_lstnew(line, ft_strlen(line) + 1)))
			return (0);
		ft_lstadd(&(ant_hill->rooms), tmp_lst);
	}
	else if (ft_strchr(line, '-'))
	{
		if (!(tmp_lst = ft_lstnew(line, ft_strlen(line) + 1)))
			return (0);
		ft_lstadd(&(ant_hill->tubes), tmp_lst);
	}
	return (1);
}

static int	read2(t_ant_hill *ant_hill, char *line)
{
	char		**start_stop;

	start_stop = NULL;
	if (line[0] == '#' && line[1] == '#')
	{
		if ((start_stop = (char **)malloc(sizeof(char *))) == NULL)
			return (0);
		get_next_line(0, start_stop);
		if (!ft_strcmp(line, "##start"))
			ant_hill->start = *start_stop;
		else if (!ft_strcmp(line, "##end"))
			ant_hill->end = *start_stop;
		free(*start_stop);
		free(start_stop);
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

int			check_ant_hill(t_ant_hill *ant_hill)
{
	if (ant_hill->ant_nb <= 0 || ft_lstcount(ant_hill->rooms) < 2 || \
	!ant_hill->tubes->content || !ant_hill->start || !ant_hill->end)
		return (0);
	//TODO : Check for rooms positions -> int
	//TODO : Check that tubes connects rooms, at least start and end
	return (1);
}
