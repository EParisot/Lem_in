/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:20:39 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/25 22:51:22 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_move(t_ant *ant, char **dest, t_ant_hill *ant_hill)
{
	t_list	*tmp_tubes;

	tmp_tubes = ant_hill->tubes;
	while (tmp_tubes)
	{
		if (!ft_strcmp(((char**)tmp_tubes->content)[0], ant->room))
			if (!ft_strcmp(((char**)tmp_tubes->content)[1], dest[0]))
				break;
		tmp_tubes = tmp_tubes->next;
	}
	if (!tmp_tubes)
		return (0);
	return (1);
}

int			move_ant(t_ant *ant, char **dest, t_ant_hill *ant_hill,\
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
	while (tmp)
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

void		free_paths(t_list **paths)
{
	t_list	*path;
	t_list	*tmp;

	path = NULL;
	tmp = NULL;
	while (*paths)
	{
		path = (t_list*)((*paths)->content);
		ft_lstdel(&path, del1);
		tmp = *paths;
		*paths = (*paths)->next;
		free(tmp);
	}
}

//////////DEBUG
void	path_print(t_list *path)
{
	t_list	*tmp;

	tmp = path;
	while (tmp)
	{
		ft_printf("pos = %s\n", (char*)(tmp->content));
		tmp = tmp->next;
	}
}
void	paths_print(t_list *paths)
{
	t_list	*tmp;

	tmp = paths;
	while (tmp)
	{
		path_print(tmp->content);
		ft_printf("\n");
		tmp = tmp->next;
	}
}
/////////////////

int			algo(t_list *ants, t_ant_hill *ant_hill, t_win *win)
{
	t_list	*paths;
	t_list	*path;

	path = NULL;
	paths = NULL;
	if (!(get_paths(ant_hill, &path, &paths, ant_hill->start)) || !paths)
	{
		ft_lstdel(&path, del1);
		free_paths(&paths);
		ft_printf("NO_PATH_");
		return (0);
	}
// DEBUG
paths_print(paths);
// TODO : execute lists instructions
// MOVE TEST
	SDL_Delay(5000);
	char	*test[3] = {"2\0", "5\0", "0\0"};
	if (!move_ant(ants->content, test, ant_hill, win))
	{
		ft_lstdel(&path, del1);
		free_paths(&paths);
		return (0);
	}
	SDL_Delay(5000);
	char	*test2[3] = {"1\0", "9\0", "2\0"};
	if (!move_ant(ants->content, test2, ant_hill, win))
	{
		ft_lstdel(&path, del1);
		free_paths(&paths);
		return (0);
	}
///////
	ft_lstdel(&path, del1);
	free_paths(&paths);
	return (1);
}
