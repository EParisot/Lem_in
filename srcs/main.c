/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/18 23:49:50 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_ant_hill	*init_ant_hill(t_ant_hill *ant_hill)
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

void	del(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

void	del_ant_hill(t_ant_hill *ant_hill)
{
	ft_lstdel(&ant_hill->rooms, del);
	ft_lstdel(&ant_hill->tubes, del);
	free(ant_hill);
}

int		read_data(t_ant_hill *ant_hill, char *line)
{
	char		**start_stop;
	t_list		*tmp_lst;

	start_stop = NULL;
	tmp_lst = NULL;
	if (ft_isdigit(line[0]) && !ft_strchr(line, ' ') && !ft_strchr(line, '-'))
	{
		ant_hill->ant_nb = ft_atoi(line);
		ft_printf("ant_nb = %d\n", ant_hill->ant_nb);
	}
	else if (ft_strchr(line, ' '))
	{
		if (!(tmp_lst = ft_lstnew(line, ft_strlen(line) + 1)))
			return (0);
		ft_lstadd(&(ant_hill->rooms), tmp_lst);
		ft_printf("room = %s\n", (char*)((ant_hill->rooms)->content));
	}
	else if (ft_strchr(line, '-'))
	{
		if (!(tmp_lst = ft_lstnew(line, ft_strlen(line) + 1)))
			return (0);
		ft_lstadd(&(ant_hill->tubes), tmp_lst);
		ft_printf("tube = %s\n", (char*)((ant_hill->tubes)->content));
	}
	else if (line[0] == '#' && line[1] != '#')
		ft_printf("commentaire = %s\n", line);
	else if (line[0] == '#' && line[1] == '#')
	{
		ft_printf("instruction = %s\n", line);
		if ((start_stop = (char **)malloc(sizeof(char *))) == NULL)
			return (0);
		get_next_line(0, start_stop);
		if (!ft_strcmp(line, "##start"))
		{
			ant_hill->start = *start_stop;
			ft_printf("start = %s\n", ant_hill->start);
		}
		else if (!ft_strcmp(line, "##end"))
		{
			ant_hill->end = *start_stop;
			ft_printf("end = %s\n", ant_hill->end);
		}
		free(*start_stop);
		free(start_stop);
	}
	return (1);
}

int		check_ant_hill(t_ant_hill *ant_hill)
{
	if (ant_hill->ant_nb <= 0 || ft_lstcount(ant_hill->rooms) < 2 || \
	!ant_hill->tubes->content || !ant_hill->start || !ant_hill->end)
		return (0);
	//TODO : Check for rooms positions -> int
	//TODO : Check that tubes connects rooms, at least start and end
	return (1);
}

void	lem_in(t_ant_hill *ant_hill)
{
	(void)ant_hill;
	//TODO : Obvious...
}

int		main(void)
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
