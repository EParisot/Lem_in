/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/19 00:00:11 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_ant_hill	*init_ant_hill(t_ant_hill *ant_hill)
{
	if ((ant_hill = (t_ant_hill *)malloc(sizeof(t_ant_hill))) == NULL)
		return (NULL);
	ant_hill->ant_nb = 0;
	if ((ant_hill->rooms = ft_lstnew(NULL, sizeof(char*))) == NULL)
		return (NULL);
	if ((ant_hill->tubes = ft_lstnew(NULL, sizeof(char*))) == NULL)
		return (NULL);
	ant_hill->start = NULL;
	ant_hill->end = NULL;
	return (ant_hill);
}

static void		del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

static void		del_ant_hill(t_ant_hill *ant_hill)
{
	ft_lstdel(&ant_hill->rooms, del);
	ft_lstdel(&ant_hill->tubes, del);
	free(ant_hill);
}

static void		lem_in(t_ant_hill *ant_hill)
{
	(void)ant_hill;
	//TODO : Obvious...
}

int			main(void)
{
	char			**line;
	t_ant_hill		*ant_hill;

	ant_hill = NULL;
	if (!(ant_hill = init_ant_hill(ant_hill)))
		return (0);
	if ((line = (char **)malloc(sizeof(char *))) == NULL)
		return (0);
	while (get_next_line(0, line))
	{
		if (!read_data(ant_hill, *line) || !ft_strcmp(*line, ""))
			break ;
		free(*line);
	}
	free(*line);
	free(line);
	if (check_ant_hill(ant_hill))
		lem_in(ant_hill);
	else
		ft_printf("ERROR\n");
	del_ant_hill(ant_hill);
	return (0);
}
