/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/18 12:44:23 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		read_data(t_ant_hill *ant_hill)
{
	(void)ant_hill;
	return (1);
}

int		main(void)
{
	char		**line;
	t_ant_hill	*ant_hill;

	if ((line = (char **)malloc(sizeof(char *))) == NULL)
		return (0);
	if ((ant_hill = (t_ant_hill *)malloc(sizeof(t_ant_hill *))) == NULL)
		return (0);
	while (get_next_line(0, line))
	{
		if (!read_data(ant_hill))
			break ;
		free(*line);
	}
	free(*line);
	free(line);
	free(ant_hill);
	return (0);
}
