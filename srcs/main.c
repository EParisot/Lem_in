/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/05/09 22:35:41 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_ant_hill	*init_ant_hill(t_ant_hill *ant_hill)
{
	int		nb;

	nb = 0;
	if (!(ant_hill = (t_ant_hill *)malloc(sizeof(t_ant_hill))))
		return (NULL);
	ant_hill->ants = NULL;
	ant_hill->paths = NULL;
	ant_hill->instru = NULL;
	ant_hill->ant_nb = nb;
	ant_hill->rooms = NULL;
	ant_hill->tubes = NULL;
	ant_hill->start = NULL;
	ant_hill->end = NULL;
	ant_hill->win = NULL;
	return (ant_hill);
}

static void			del(void *content, size_t content_size)
{
	char	**tab;
	int		n;

	n = content_size / sizeof(char*);
	if (!content)
		return ;
	tab = (char**)content;
	while (--n >= 0)
		free(tab[n]);
	free(content);
}

static void			del_ant_hill(t_ant_hill *ant_hill)
{
	ft_lstdel(&ant_hill->rooms, del);
	ft_lstdel(&ant_hill->tubes, del);
	if (ant_hill->instru)
		ft_lstdel(&ant_hill->instru, del1);
	if (ant_hill->ants)
		destroy_ants(ant_hill->ants);
	if (ant_hill->paths)
		free_paths(&ant_hill->paths);
	if (ant_hill->win)
		w_destroy(ant_hill->win);
	free(ant_hill);
}

void				print_input(t_ant_hill *ant_hill)
{
	t_list		*instru;

	instru = ant_hill->instru;
	while (instru)
	{
		ft_printf("%s\n", (char*)instru->content);
		instru = instru->next;
	}
}

int					main(int ac, char **av)
{
	char			**line;
	t_ant_hill		*ant_hill;

	ant_hill = NULL;
	if (!(ant_hill = init_ant_hill(ant_hill)))
		return (0);
	if (!(line = (char **)malloc(sizeof(char *))))
		return (0);
	while (get_next_line(0, line) > 0)
	{
		if (!read_data(ant_hill, *line) || !ft_strcmp(*line, ""))
			break ;
		free(*line);
	}
	free(*line);
	free(line);
	if (!check_ant_hill(ant_hill))
		ft_printf("INPUT_ERROR\n");
	if (!lem_in(ant_hill, ac, av))
		ft_printf("EXEC_ERROR\n");
	del_ant_hill(ant_hill);
	return (0);
}
