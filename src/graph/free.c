/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:47:39 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/18 11:11:07 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static void		ft_free_array(t_graph *graph)
{
	unsigned int	i;
	t_vert			*tmp;
	t_vert			*vert;

	i = 0;
	while (i < graph->size)
	{
		vert = graph->array[i];
		if (vert)
		{
			while (vert)
			{
				tmp = vert->next;
				free(vert);
				vert = tmp;
			}
			free(vert);
		}
		i++;
	}
}

void			ft_graph_free(t_graph *graph)
{
	t_room			*r;
	t_room			*room;

	if (!graph)
		return ;
	ft_free_array(graph);
	room = graph->rooms;
	while (room)
	{
		r = room->next;
		free(room->line);
		free(room);
		room = r;
	}
	free(graph->array);
	free(graph);
	graph = NULL;
}
