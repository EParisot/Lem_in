/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 11:05:50 by eparisot          #+#    #+#             */
/*   Updated: 2018/05/04 11:37:58 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read3(t_ant_hill *ant_hill, char *tmp, t_list *tmp_lst, char **tb)
{
	tb = parse_tubes(tmp, 1);
	if (!ant_hill->tubes)
	{
		if (!(ant_hill->tubes = ft_lstnew(tb, 3 * sizeof(char*))))
			return (0);
	}
	else
	{
		if (!(tmp_lst = ft_lstnew(tb, 3 * sizeof(char*))))
			return (0);
		ft_lstaddend(&(ant_hill->tubes), tmp_lst);
	}
	free(tb);
	return (1);
}
