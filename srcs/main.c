/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/19 15:58:38 by eparisot         ###   ########.fr       */
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

static void			del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

static void			del_ant_hill(t_ant_hill *ant_hill)
{
	ft_lstdel(&ant_hill->rooms, del);
	ft_lstdel(&ant_hill->tubes, del);
	free(ant_hill);
}

static void			lem_in(t_ant_hill *ant_hill)
{
	(void)ant_hill;
	//TODO : Obvious...
}

void				printlists(t_ant_hill *ant_hill)
{
	t_list	*tmp_rooms;
	t_list	*tmp_tubes;

	tmp_rooms = ant_hill->rooms;
	tmp_tubes = ant_hill->tubes;
	while (tmp_rooms->content)
	{
		ft_printf("%s, %s, %s\n", ((char**)tmp_rooms->content)[0], \
								((char**)tmp_rooms->content)[1], \
								((char**)tmp_rooms->content)[2]);
		tmp_rooms = tmp_rooms->next;
	}
	while (tmp_tubes->content)
	{
		ft_printf("%s, %s\n", ((char**)tmp_tubes->content)[0], \
								((char**)tmp_tubes->content)[1]);
		tmp_tubes = tmp_tubes->next;
	}
}

int					main(void)
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
	printlists(ant_hill);
	del_ant_hill(ant_hill);
	return (0);
}
