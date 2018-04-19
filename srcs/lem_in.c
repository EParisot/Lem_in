/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/20 00:26:04 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_input(t_ant_hill *ant_hill)
{
	t_list	*tmp_rooms;
	t_list	*tmp_tubes;

	tmp_rooms = ant_hill->rooms;
	tmp_tubes = ant_hill->tubes;
	ft_printf("%d\n", ant_hill->ant_nb);
	while (tmp_rooms->content)
	{
		if (!ft_strcmp(((char**)tmp_rooms->content)[0], ant_hill->start))
			ft_printf("##start\n");
		else if (!ft_strcmp(((char**)tmp_rooms->content)[0], ant_hill->end))
			ft_printf("##end\n");
		ft_printf("%s %s %s\n", ((char**)tmp_rooms->content)[0], \
								((char**)tmp_rooms->content)[1], \
								((char**)tmp_rooms->content)[2]);
		tmp_rooms = tmp_rooms->next;
	}
	while (tmp_tubes->content)
	{
		ft_printf("%s-%s\n", ((char**)tmp_tubes->content)[0], \
								((char**)tmp_tubes->content)[1]);
		tmp_tubes = tmp_tubes->next;
	}
	ft_putchar('\n');
}

void		lem_in(t_ant_hill *ant_hill)
{
	print_input(ant_hill);
}
