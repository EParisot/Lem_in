/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 22:20:39 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/25 22:14:47 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			check_move(t_ant *ant, char **dest, t_ant_hill *ant_hill)
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

static int	is_in_lst(t_list *path, char *pos)
{
	t_list	*tmp;

	tmp = path;
	while (tmp)
	{
		if (!ft_strcmp(pos, (char*)tmp->content))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		lst_cpy(t_list **dest, t_list *src)
{
	t_list	*tmp;
	t_list	*new;

	tmp = src;
	new = NULL;
	if (!(*dest = ft_lstnew(tmp->content, ft_strlen(tmp->content) + 1)))
		return (0);
	tmp = tmp->next;
	while (tmp)
	{
		if (!(new = ft_lstnew(tmp->content, ft_strlen(tmp->content) + 1)))
			return (0);
		ft_lstaddend(dest, new);
		tmp = tmp->next;
	}
	return (1);
}

static void	del2(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

static void	free_paths(t_list **paths)
{
	t_list	*path;
	t_list	*tmp;

	path = NULL;
	tmp = NULL;
	while (*paths)
	{
		path = (t_list*)((*paths)->content);
		ft_lstdel(&path, del2);
		tmp = *paths;
		*paths = (*paths)->next;
		free(tmp);
	}
	
}

int		get_paths(t_ant_hill *ant_hill, t_list **path, t_list **paths, \
			char *pos)
{
	t_list	*tmp_tubes;
	t_list	*new_pos;
	t_list	*new_path;
	t_list	*tmp_path;

	tmp_tubes = ant_hill->tubes;
	new_pos = NULL;
	new_path = NULL;
	tmp_path = NULL;
	if (!(*path))
		if (!(*path = ft_lstnew(ant_hill->start, \
		ft_strlen(ant_hill->start) + 1)))
			return (0);
	if (!ft_strcmp(pos, ant_hill->end))
	{
		if (!(*paths))
		{
			if (!(*paths = ft_lstnew(*path, (ft_lstcount(*path) + 1) * \
			sizeof(t_list*))))
				return (0);
		}
		else
		{
			if (!(new_path = ft_lstnew(*path, (ft_lstcount(*path) + 1) * \
			sizeof(t_list*))))
				return (0);
			ft_lstaddend(paths, new_path);
		}
		return (1);
	}
	else
		while (tmp_tubes)
		{
			if (!ft_strcmp(pos, ((char**)tmp_tubes->content)[0]) && \
			!is_in_lst(*path, ((char**)tmp_tubes->content)[1]))
			{
				if (!(new_pos = ft_lstnew(((char**)tmp_tubes->content)[1], \
				ft_strlen(((char**)tmp_tubes->content)[1]) + 1)))
					return (0);
				if (!lst_cpy(&tmp_path, *path))
					return (0);
				ft_lstaddend(path, new_pos);
				get_paths(ant_hill, path, paths, \
					((char**)tmp_tubes->content)[1]);
				free(*path);
				*path = tmp_path;
			}
			tmp_tubes = tmp_tubes->next;
		}
	ft_lstdel(path, del2);
	return (1);
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
		ft_lstdel(&path, del2);
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
		ft_lstdel(&path, del2);
		free_paths(&paths);
		return (0);
	}
	SDL_Delay(5000);
	char	*test2[3] = {"1\0", "9\0", "2\0"};
	if (!move_ant(ants->content, test2, ant_hill, win))
	{
		ft_lstdel(&path, del2);
		free_paths(&paths);
		return (0);
	}
///////
	ft_lstdel(&path, del2);
	free_paths(&paths);
	return (1);
}
