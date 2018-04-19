/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/19 12:13:10 by eparisot         ###   ########.fr       */
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

static int	read2bis(t_ant_hill *ant_hill, char *line, t_list *tmp_lst)
{
	char		**start_stop;

	start_stop = NULL;
	if (!(start_stop = (char **)malloc(sizeof(char *))))
		return (0);
	get_next_line(0, start_stop);
	if (!ft_strcmp(line, "##start"))
	{
		if (!(tmp_lst = ft_lstnew(*start_stop, ft_strlen(*start_stop) + 1)))
			return (0);
		ft_lstadd(&(ant_hill->rooms), tmp_lst);
		ant_hill->start = *start_stop;
	}
	else if (!ft_strcmp(line, "##end"))
	{
		if (!(tmp_lst = ft_lstnew(*start_stop, ft_strlen(*start_stop) + 1)))
			return (0);
		ft_lstadd(&(ant_hill->rooms), tmp_lst);
		ant_hill->end = *start_stop;
	}
	free(*start_stop);
	free(start_stop);
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

static int	check_rooms(t_ant_hill *ant_hill)
{
	t_list	*rooms_lst;
	char	*tmp;

	tmp = NULL;
	rooms_lst = ant_hill->rooms;
	while ((char*)rooms_lst->content)
	{
		tmp = (char*)rooms_lst->content;
		while (*tmp)
		{
			if (*tmp == ' ')
			{
				tmp++;
				while (*tmp && *tmp != ' ')
				{
					if (!ft_isdigit(*tmp))
						return (0);
					tmp++;
				}
			}
			tmp++;
		}
		rooms_lst = rooms_lst->next;
	}
	return (1);
}

static int	check_tubes(t_ant_hill *ant_hill)
{
	t_list	*rooms_lst;
	t_list	*tubes_lst;
	char	*tmp;

	tmp = NULL;
	rooms_lst = ant_hill->rooms;
	tubes_lst = ant_hill->tubes;
	while ((char*)tubes_lst->content)
	{
		tmp = (char*)tubes_lst->content;
		//TODO Parsers
		tubes_lst = tubes_lst->next;
	}
	return (1);
}

int			check_ant_hill(t_ant_hill *ant_hill)
{
	if (ant_hill->ant_nb <= 0 || ft_lstcount(ant_hill->rooms) < 2 || \
	!ant_hill->tubes->content || !ant_hill->start || !ant_hill->end)
		return (0);
	if (!check_rooms(ant_hill))
		return (0);
	if (!check_tubes(ant_hill))
		return (0);
	return (1);
}
