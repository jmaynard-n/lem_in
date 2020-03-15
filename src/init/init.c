/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:51:41 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/18 12:48:37 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

static int	ft_ants(void)
{
	char	*line;
	int		num;

	line = NULL;
	num = 0;
	if (get_next_line(0, &line))
	{
		if (!(num = ft_valid_ants(line)))
		{
			free(line);
			return (-1);
		}
		free(line);
		line = NULL;
	}
	return (num);
}

static int	ft_help_rooms(t_init *init, char *line, int num)
{
	if (!(g_graph = ft_graph_create(num)))
		return (ft_strdel(&line));
	if ((line) && (ft_strlen(line) == 0))
		return (ft_strdel(&line));
	if (line && ft_strchr(line, '-'))
	{
		if (!ft_valid_links(init, line))
			return (ft_strdel(&line));
		ft_add_link(init, line);
		ft_strdel(&line);
	}
	else if (line != NULL)
		return (ft_strdel(&line));
	return (num);
}

static int	ft_rooms(t_init *init)
{
	char	*line;
	int		num;

	line = NULL;
	num = 0;
	while (get_next_line(0, &line) &&
		(ft_strchr(line, ' ') || ft_strstr(line, "#")))
	{
		if (!ft_strcmp(line, "##start") && g_start != -1)
			return (ft_strdel(&line));
		else if (!(ft_strcmp(line, "##end")) && g_end != -1)
			return (ft_strdel(&line));
		if (!ft_valid_rooms(line))
			return (ft_strdel(&line));
		if ((num = ft_add_room(init, line)) < 0)
			return (ft_strdel(&line));
		if (!ft_strcmp(line, "##start") && g_start == -1)
			g_start = num - 1;
		else if (!(ft_strcmp(line, "##end")) && g_end == -1)
			g_end = num - 1;
		ft_strdel(&line);
	}
	return (ft_help_rooms(init, line, num));
}

static int	ft_links(t_init *init)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) &&
		(ft_strchr(line, '-') || ft_strstr(line, "#")))
	{
		if (!ft_valid_links(init, line))
			return (ft_strdel(&line));
		ft_add_link(init, line);
		ft_strdel(&line);
	}
	if (line)
		return (ft_strdel(&line));
	return (1);
}

int			ft_init_farm(t_init **init)
{
	int num;

	if (!((*init) = (t_init *)malloc(sizeof(t_init))))
		return (0);
	(*init)->the_links = NULL;
	(*init)->rooms = NULL;
	(*init)->the_rooms = NULL;
	if ((num = ft_ants()) <= 0)
		return (0);
	if (!ft_rooms(*init))
		return (0);
	if (!ft_links(*init))
		return (0);
	return (num);
}
