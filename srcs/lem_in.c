/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:20:39 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/22 01:10:44 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list		*init_ants(t_ant_hill *ant_hill)
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
		curr_ant->room = ft_strdup(ant_hill->start);
		if (!(tmp_ant = ft_lstnew(curr_ant, sizeof(t_ant))))
			return (NULL);
		ft_lstadd(&ants, tmp_ant);
		free(curr_ant);
		n--;
	}
	return (ants);
}

static void	del1(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void		destroy_ants(t_list *ants)
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

int			lem_in(t_ant_hill *ant_hill, SDL_Window *window, int ac, char **av)
{
	t_list	*ants;

	ants = NULL;
	print_input(ant_hill);
	if (ac > 1 && !ft_strcmp(av[1], "-v"))
		window = visu(ant_hill);
	if (!(ants = init_ants(ant_hill)))
		return (0);
	//
	//TODO
	//
	if (window)
		w_destroy(window);
	destroy_ants(ants);
	return (1);
}
