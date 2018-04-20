/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/20 03:44:38 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void			print_input(t_ant_hill *ant_hill)
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
/*
static int			*get_max(t_ant_hill *ant_hill)
{
	t_list		*tmp;
	int			*tab;
	int			x_max;
	int			y_max;

	if (!(tab = (int*)malloc(2 * sizeof(int))))
		return (NULL);
	x_max = 0;
	y_max = 0;
	tmp = ant_hill->rooms;
	while (tmp->content)
	{
		if (ft_atoi(((char**)tmp->content)[1]) > x_max)
			x_max = ft_atoi(((char**)tmp->content)[1]);
		if (ft_atoi(((char**)tmp->content)[2]) > y_max)
			y_max = ft_atoi(((char**)tmp->content)[2]);
		tmp = tmp->next;
	}
	tab[0] = x_max;
	tab[1] = y_max;
	return (tab);
}

static void			visu_rooms(t_ant_hill *ant_hill, SDL_Window *window)
{
	t_list		*tmp;
	int			*max;

	if (!(max = get_max(ant_hill)))
		return ;
	tmp = ant_hill->rooms;
	while (tmp->content)
	{
		//TODO : Show Room'name
		//TODO : Add Start and End Flags
		draw(window, 50 + (1000 * ft_atoi(((char**)tmp->content)[1]) / max[0]),\
				50 + (600 * ft_atoi(((char**)tmp->content)[2]) / max[1]));
		tmp = tmp->next;
	}
	free(max);
}

static SDL_Window	*visu_tubes(t_ant_hill *ant_hill, SDL_Window *window)
{
	if (!(window = w_init()))
		return (NULL);
	w_clear(window);
	//TODO Turn tubes data into coords tab
	(void)ant_hill;
	//draw_line();
	return (window);
}
*/
void				visu(t_ant_hill *ant_hill)
{
	//SDL_Window	*window;

	//window = NULL;
	print_input(ant_hill);
	//if (!(window = visu_tubes(ant_hill, window)))
	//	return ;
	//visu_rooms(ant_hill, window);
	//SDL_Delay(10000);
	//w_destroy(window);
}
