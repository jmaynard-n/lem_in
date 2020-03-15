/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_rooms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 14:29:35 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/16 18:50:09 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

static t_room	*ft_new_node(t_room *rooms)
{
	char	*line;
	t_room	*tmp;

	if (!(tmp = (t_room *)malloc(sizeof(t_room))))
		return (0);
	tmp->x_coord = rooms->x_coord;
	tmp->y_coord = rooms->y_coord;
	tmp->index = rooms->index;
	if (!(line = ft_strdup(rooms->line)))
		return (0);
	tmp->line = line;
	return (tmp);
}

int				ft_copy_rooms(t_room *rooms)
{
	t_room	*tmp;
	t_room	*t;

	t = rooms;
	if (!g_graph->rooms)
	{
		if (!(tmp = ft_new_node(t)))
			return (0);
		tmp->next = NULL;
		g_graph->rooms = tmp;
		t = t->next;
	}
	while (t)
	{
		if (!(tmp = ft_new_node(t)))
			return (0);
		tmp->next = g_graph->rooms;
		g_graph->rooms = tmp;
		t = t->next;
	}
	return (1);
}
