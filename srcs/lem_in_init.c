/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:20:39 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/28 17:39:32 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		init_ant_bis(t_ant_hill *ant_hill, t_ant *curr_ant, \
		t_list *tmp_ant, int n)
{
	while (n)
	{
		if (!(curr_ant = (t_ant*)malloc(sizeof(t_ant))))
			return (0);
		curr_ant->id = n;
		if (!ant_hill->start || !(curr_ant->room = ft_strdup(ant_hill->start)))
		{
			free(curr_ant);
			return (0);
		}
		if (!ant_hill->ants)
		{
			if (!(ant_hill->ants = ft_lstnew(curr_ant, sizeof(t_ant))))
				return (0);
		}
		else
		{
			if (!(tmp_ant = ft_lstnew(curr_ant, sizeof(t_ant))))
				return (0);
			ft_lstadd(&(ant_hill->ants), tmp_ant);
		}
		free(curr_ant);
		n--;
	}
	return (1);
}

static t_list	*init_ants(t_ant_hill *ant_hill)
{
	int		n;
	t_ant	*curr_ant;
	t_list	*tmp_ant;

	n = ant_hill->ant_nb;
	curr_ant = NULL;
	tmp_ant = NULL;
	if (!init_ant_bis(ant_hill, curr_ant, tmp_ant, n))
		return (NULL);
	return (ant_hill->ants);
}

void			del1(void *content, size_t content_size)
{
	(void)content_size;
	if (content)
		free(content);
}

void			destroy_ants(t_list *ants)
{
	t_list	*tmp;

	tmp = ants;
	while (tmp)
	{
		free(((t_ant*)tmp->content)->room);
		tmp = tmp->next;
	}
	ft_lstdel(&ants, del1);
}

int				lem_in(t_ant_hill *ant_hill, int ac, char **av)
{
	if (ac > 1 && !ft_strcmp(av[1], "-v"))
	{
		if (ant_hill->ant_nb < 100 && ft_lstcount(ant_hill->rooms) < 80)
			ant_hill->win = visu(ant_hill, ant_hill->win);
		else
			ft_printf("[-v] option ignored...\n");
	}
	print_input(ant_hill);
	if (!(init_ants(ant_hill)) || !(algo(ant_hill, ant_hill->win)))
		return (0);
	return (1);
}
