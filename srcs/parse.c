/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eparisot <eparisot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:01:21 by eparisot          #+#    #+#             */
/*   Updated: 2018/05/10 17:12:47 by eparisot         ###   ########.fr       */
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
	if (!ft_isdigit(tab[1][0]) || !ft_isdigit(tab[2][0]) || !ft_is_int(tab[1]) \
			|| !ft_is_int(tab[2]))
		return (NULL);
	return (tab);
}

char		**parse_rooms(char *line)
{
	char	**tab;

	if (!(tab = (char**)malloc(3 * sizeof(char*))))
		return (NULL);
	if (line[0] != 'L' && line[0] != '#' && ft_strchr(line, ' ') && \
		ft_strchr(line, ' ') != ft_strrchr(line, ' ') && !ft_strchr(line, '-'))
		return (parse_rooms_bis(line, tab));
	else
		return (NULL);
}

static char	**parse_tubes_bis(char *line, char **tab, int one_way)
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
	if (!ft_strcmp(tab[0], tab[1]) || !(tab[i] = ft_itoa(one_way)))
		return (NULL);
	return (tab);
}

char		**parse_tubes(char *line, int one_way)
{
	char	**tab;

	if (!(tab = (char**)malloc(3 * sizeof(char*))))
		return (NULL);
	if (line[0] != 'L' && line[0] != '#' && ft_strchr(line, '-') && \
			!ft_strchr(line, ' ') && ft_strlen(ft_strchr(line, '-')) > 1 && \
			(ft_strchr(line, '-') == ft_strrchr(line, '-')))
		return (parse_tubes_bis(line, tab, one_way));
	else
		return (NULL);
}
