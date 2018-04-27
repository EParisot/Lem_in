/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_exec1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:39:14 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/27 22:43:50 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	exec2(t_ant_hill *a_h, t_list *paths, t_list *ants, size_t min)
{
	t_list	*p;

	while (paths)
	{
		p = paths->content;
		if (ft_lstcount((t_list*)paths->content) == min)
			while (p && p->next)
			{
				if (!ft_strcmp((char*)((t_ant*)ants->content)->room, \
				(char*)p->content))
					if (rie((char*)((t_list*)p->next)->content, a_h->ants) || \
					!ft_strcmp((char*)((t_list*)p->next)->content, a_h->end))
					{
						if (!move_ant(ants->content, \
						(char*)((t_list*)p->next)->content, a_h, a_h->win))
							return (-1);
						return (1);
					}
				p = p->next;
			}
		paths = paths->next;
	}
	return (0);
}

static int	exec1(t_ant_hill *ant_hill, t_list *paths, t_list *ants)
{
	size_t	min;
	size_t	max;
	int		ret;

	min = smallest_path_len(paths);
	max = biggest_path_len(paths);
	while (min <= max)
	{
		ret = exec2(ant_hill, paths, ants, min);
		if (ret == 1)
			return (1);
		else if (ret == -1)
			return (0);
		min++;
		paths = ant_hill->paths;
	}
	return (1);
}

int			exec(t_ant_hill *ant_hill)
{
	t_list	*tmp_ants;
	t_list	*tmp_paths;

	tmp_ants = ant_hill->ants;
	tmp_paths = NULL;
	while (!is_over(ant_hill, tmp_ants))
	{
		while (tmp_ants->content)
		{
			tmp_paths = ant_hill->paths;
			if (ft_strcmp((char*)((t_ant*)tmp_ants->content)->room, \
						ant_hill->end))
				if (!exec1(ant_hill, tmp_paths, tmp_ants))
					return (0);
			tmp_ants = tmp_ants->next;
		}
		tmp_ants = ant_hill->ants;
		ft_putchar('\n');
	}
	return (1);
}
