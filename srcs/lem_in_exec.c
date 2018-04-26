/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 12:39:14 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/26 22:14:33 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	is_over(t_ant_hill *ant_hill, t_list *ants)
{
	t_list	*tmp_ants;

	tmp_ants = ants;
	while (tmp_ants->content)
	{
		if (ft_strcmp((char*)((t_ant*)tmp_ants->content)->room, ant_hill->end))
			return (0);
		tmp_ants = tmp_ants->next;
	}
	return (1);
}

static int	smallest_path_len(t_list *paths)
{
	size_t	min;
	t_list	*tmp;

	tmp = paths;
	min = ft_lstcount((t_list*)tmp->content);
	tmp = tmp->next;
	while (tmp)
	{
		if (ft_lstcount((t_list*)tmp->content) < min)
			min = ft_lstcount((t_list*)tmp->content);
		tmp = tmp->next;
	}
	return (min);
}

static int	biggest_path_len(t_list *paths)
{
	size_t	max;
	t_list	*tmp;

	tmp = paths;
	max = ft_lstcount((t_list*)tmp->content);
	tmp = tmp->next;
	while (tmp)
	{
		if (ft_lstcount((t_list*)tmp->content) > max)
			max = ft_lstcount((t_list*)tmp->content);
		tmp = tmp->next;
	}
	return (max);
}

static int	room_is_empty(char *room, t_list *ants)
{
	t_list	*tmp_ants;

	tmp_ants = ants;
	while (tmp_ants->content)
	{
		if (!ft_strcmp((char*)((t_ant*)tmp_ants->content)->room, room))
			return (0);
		tmp_ants = tmp_ants->next;
	}
	return (1);
}

int			exec(t_ant_hill *ant_hill, t_list *paths, t_list *ants, t_win *win)
{
	t_list	*tmp_ants;
	size_t	min;
	size_t	max;
	t_list	*tmp_paths;
	t_list	*tmp_path;
	int		moved;

	tmp_ants = ants;
	min = 0;
	tmp_paths = NULL;
	tmp_path = NULL;
	moved = 0;
	max = biggest_path_len(paths);
	//tant que pas fini
	while (!is_over(ant_hill, tmp_ants))
	{
		//loop sur ants
		while (tmp_ants->content)
		{
			min = smallest_path_len(paths);
			tmp_paths = paths;
			//si cette ant n'est pas a la fin
			if (ft_strcmp((char*)((t_ant*)tmp_ants->content)->room, ant_hill->end))
			{
				//loop sur paths
				while (min <= max)
				{
					while (tmp_paths)
					{
						tmp_path = tmp_paths->content;
						//si ce path est minimal
						if (ft_lstcount((t_list*)tmp_paths->content) == min)
						{
							//loop sur path
							while (tmp_path && tmp_path->next)
							{
								//si la room actuele est celle de ant
								if (!ft_strcmp((char*)((t_ant*)tmp_ants->content)->room, (char*)tmp_path->content))
								{
									// si next room est vide ou  si end
									if (room_is_empty((char*)((t_list*)tmp_path->next)->content, ants) || !ft_strcmp((char*)((t_list*)tmp_path->next)->content, ant_hill->end))
									{
										if (!move_ant(tmp_ants->content, (char*)((t_list*)tmp_path->next)->content, ant_hill, win))
											return (0);
										moved = 1;
										break ;
									}
								}
								tmp_path = tmp_path->next;
							}
						}
						if (moved)
							break ;
						tmp_paths = tmp_paths->next;
					}
					if (moved)
					{
						moved = 0;
						break ;
					}
					min++;
					tmp_paths = paths;
				}
			}
			tmp_ants = tmp_ants->next;
		}
		tmp_ants = ants;
		ft_putchar('\n');
	}
	return (1);
}
