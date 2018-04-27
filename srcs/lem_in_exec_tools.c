/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_exec2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:39:14 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/27 22:37:33 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_over(t_ant_hill *ant_hill, t_list *ants)
{
	t_list	*tmp_ants;

	tmp_ants = ants;
	while (tmp_ants->content)
	{
		if (ft_strcmp((char*)((t_ant*)tmp_ants->content)->room, ant_hill->end))
			return (0);
		tmp_ants = tmp_ants->next;
	}
	return (1);
}

int		smallest_path_len(t_list *paths)
{
	size_t	min;
	t_list	*tmp;

	tmp = paths;
	min = ft_lstcount((t_list*)tmp->content);
	tmp = tmp->next;
	while (tmp)
	{
		if (ft_lstcount((t_list*)tmp->content) < min)
			min = ft_lstcount((t_list*)tmp->content);
		tmp = tmp->next;
	}
	return (min);
}

int		biggest_path_len(t_list *paths)
{
	size_t	max;
	t_list	*tmp;

	tmp = paths;
	max = ft_lstcount((t_list*)tmp->content);
	tmp = tmp->next;
	while (tmp)
	{
		if (ft_lstcount((t_list*)tmp->content) > max)
			max = ft_lstcount((t_list*)tmp->content);
		tmp = tmp->next;
	}
	return (max);
}

int	rie(char *room, t_list *ants)
{
	t_list	*tmp_ants;

	tmp_ants = ants;
	while (tmp_ants->content)
	{
		if (!ft_strcmp((char*)((t_ant*)tmp_ants->content)->room, room))
			return (0);
		tmp_ants = tmp_ants->next;
	}
	return (1);
}
