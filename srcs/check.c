/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/20 12:57:36 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_rooms(t_ant_hill *ant_hill)
{
	t_list	*tmp_rooms;
	char	**tmp;
	int		i;
	int		j;

	tmp = NULL;
	tmp_rooms = ant_hill->rooms;
	while (tmp_rooms->content)
	{
		i = 1;
		tmp = (char**)tmp_rooms->content;
		while (tmp[i])
		{
			j = ft_strlen(tmp[i]);
			while (--j >= 0)
				if (!ft_isdigit(tmp[i][j]))
					return (0);
			i++;
		}
		tmp_rooms = tmp_rooms->next;
	}
	return (1);
}

static int	check_a(t_ant_hill *ant_hill, t_list *tmp_tubes)
{
	t_list	*tmp_rooms;

	tmp_rooms = ant_hill->rooms;
	while (tmp_rooms->content)
	{
		if (!ft_strcmp(((char**)tmp_tubes->content)[0], \
					((char**)tmp_rooms->content)[0]))
			break ;
		tmp_rooms = tmp_rooms->next;
	}
	if (!tmp_rooms->content)
		return (0);
	return (1);
}

static int	check_b(t_ant_hill *ant_hill, t_list *tmp_tubes)
{
	t_list	*tmp_rooms;

	tmp_rooms = ant_hill->rooms;
	while (tmp_rooms->content)
	{
		if (!ft_strcmp(((char**)tmp_tubes->content)[1], \
					((char**)tmp_rooms->content)[0]))
			break ;
		tmp_rooms = tmp_rooms->next;
	}
	if (!tmp_rooms->content)
		return (0);
	return (1);
}

static int	check_tubes(t_ant_hill *ant_hill)
{
	t_list	*tmp_tubes;

	tmp_tubes = ant_hill->tubes;
	while (tmp_tubes->content)
	{
		if (!check_a(ant_hill, tmp_tubes))
			return (0);
		if (!check_b(ant_hill, tmp_tubes))
			return (0);
		tmp_tubes = tmp_tubes->next;
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
