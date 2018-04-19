/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/19 15:49:04 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
