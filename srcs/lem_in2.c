/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:20:39 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/23 18:19:06 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_move(t_ant *ant, char **dest, t_ant_hill *ant_hill)
{
	t_list	*tmp_tubes;

	tmp_tubes = ant_hill->tubes;
	while (tmp_tubes->content)
	{
		if (!ft_strcmp(((char**)tmp_tubes->content)[0], ant->room))
			if (!ft_strcmp(((char**)tmp_tubes->content)[1], dest[0]))
				break;
		tmp_tubes = tmp_tubes->next;
	}
	if (!tmp_tubes->content)
		return (0);
	return (1);
}

int		move_ant(t_ant *ant, char **dest, t_ant_hill *ant_hill,\
		t_win *win)
{
	int		*max;
	char	**src;
	t_list	*tmp;

	src = NULL;
	tmp = ant_hill->rooms;
	max = NULL;
	if (!check_move(ant, dest, ant_hill))
		return (0);
	while (tmp->content)
	{
		if (!ft_strcmp(ant->room, ((char**)tmp->content)[0]))
			src = ((char**)tmp->content);
		tmp = tmp->next;
	}
	free(ant->room);
	if (!(ant->room = ft_strdup(dest[0])))
		return (0);
	ft_printf("L%d-%s ", ant->id, ant->room);
	max = get_max(ant_hill);
	if (win)
		anim_ant(win, src, dest, max);
	free(max);
	return (1);
}

int		algo(t_list *ants, t_ant_hill *ant_hill, t_win *win)
{
	// MOVE TEST
	SDL_Delay(5000);
	char	*test[3] = {"3\0", "16\0", "3\0"};
	if (!move_ant(ants->content, test, ant_hill, win))
		return (0);
	//
	return (1);
}
