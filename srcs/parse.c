/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/04/29 17:56:46 by eparisot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char	**parse_rooms_bis(char *line, char **tab)
{
	int		n;
	int		i;
	int		j;

	n = 0;
	i = 0;
	j = 0;
	while (*line)
	{
		while (*(line + n) && *(line + n) != ' ')
			n++;
		if (!(tab[i] = (char*)malloc(n * sizeof(char) + 1)))
			return (NULL);
		while (*line && *line != ' ')
			tab[i][j++] = *(line++);
		tab[i][j] = '\0';
		n = 0;
		j = 0;
		i++;
		line++;
	}
	return (tab);
}

char		**parse_rooms(char *line)
{
	char	**tab;

	if (!(tab = (char**)malloc(3 * sizeof(char*))))
		return (NULL);
	return (parse_rooms_bis(line, tab));
}

static char	**parse_tubes_bis(char *line, char **tab)
{
	int		n;
	int		i;
	int		j;

	n = 0;
	i = 0;
	j = 0;
	while (*line)
	{
		while (*(line + n) && *(line + n) != '-')
			n++;
		if (!(tab[i] = (char*)malloc(n * sizeof(char) + 1)))
			return (NULL);
		while (*line && *line != '-')
			tab[i][j++] = *(line++);
		tab[i][j] = '\0';
		n = 0;
		j = 0;
		i++;
		line++;
	}
	return (tab);
}

char		**parse_tubes(char *line)
{
	char	**tab;

	if (!(tab = (char**)malloc(2 * sizeof(char*))))
		return (NULL);
	return (parse_tubes_bis(line, tab));
}
