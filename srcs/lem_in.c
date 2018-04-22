/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:20:39 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/23 01:19:01 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*init_ants(t_ant_hill *ant_hill)
{
	int		n;
	t_list	*ants;
	t_ant	*curr_ant;
	t_list	*tmp_ant;

	n = ant_hill->ant_nb;
	curr_ant = NULL;
	tmp_ant = NULL;
	if (!(ants = ft_lstnew(NULL, sizeof(t_ant*))))
		return (NULL);
	while (n)
	{
		if (!(curr_ant = (t_ant*)malloc(sizeof(t_ant*))))
			return (NULL);
		curr_ant->id = n;
		if (!(curr_ant->room = ft_strdup(ant_hill->start)))
			return (NULL);
		if (!(tmp_ant = ft_lstnew(curr_ant, sizeof(t_ant))))
			return (NULL);
		ft_lstadd(&ants, tmp_ant);
		free(curr_ant);
		n--;
	}
	return (ants);
}

static void		del1(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

static void		destroy_ants(t_list *ants)
{
	t_list	*tmp;

	tmp = ants;
	while (tmp->content)
	{
		free(((t_ant*)tmp->content)->room);
		tmp = tmp->next;
	}
	ft_lstdel(&ants, del1);
}

static int		check_move(t_ant *ant, char **dest, t_ant_hill *ant_hill)
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

static int		move_ant(t_ant *ant, char **dest, t_ant_hill *ant_hill,\
		t_win *win)
{
	int		*max;
	char	**src;
	t_list	*tmp;

	src = NULL;
	tmp = ant_hill->rooms;
	max = get_max(ant_hill);
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
	if (win)
		anim_ant(win, src, dest, max);
	free(max);
	return (1);
}

int			lem_in(t_ant_hill *ant_hill, t_win *win, int ac, char **av)
{
	t_list	*ants;

	ants = NULL;
	if (ac > 1 && !ft_strcmp(av[1], "-v"))
	{
		if (ant_hill->ant_nb < 100 && ft_lstcount(ant_hill->rooms) < 100)
			win = visu(ant_hill, win);
		else
			ft_printf("[-v] option ignored...\n");
	}
	print_input(ant_hill);
	if (!(ants = init_ants(ant_hill)))
		return (0);
	// MOVE_TEST
	SDL_Delay(5000);
	char	*test[3] = {"3\0", "16\0", "3\0"};
	if (!move_ant(ants->content, test, ant_hill, win))
		return (0);
	//
	if (win)
		w_destroy(win);
	destroy_ants(ants);
	return (1);
}
