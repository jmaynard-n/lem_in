/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:20:10 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/15 15:36:18 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static int		ft_node_handler(t_graph *graph, t_vert *node, const int dst)
{
	t_vert			*tmp;

	if (graph->array[dst] != NULL)
	{
		tmp = graph->array[dst];
		while (tmp)
		{
			if (tmp->vert == node->vert)
			{
				free(node);
				return (1);
			}
			tmp = tmp->next;
		}
		node->next = graph->array[dst];
		graph->array[dst] = node;
	}
	else
	{
		node->next = NULL;
		graph->array[dst] = node;
	}
	return (1);
}

int				ft_add_to_graph(t_graph *graph, const int dst, const int src)
{
	t_vert *node;

	if (!graph || dst == src)
		return (0);
	if (!(node = malloc(sizeof(t_vert))))
		return (0);
	node->vert = src;
	ft_node_handler(graph, node, dst);
	return (1);
}

void			print_graph(void)
{
	unsigned int	i;
	t_vert			*tmp;
	unsigned int	size;

	i = 0;
	size = g_graph->size;
	while (i < size)
	{
		tmp = g_graph->array[i];
		ft_printf("[ %d ]", i);
		if (!tmp)
			ft_printf(" -> (null)");
		while (tmp)
		{
			ft_printf(" -> %d", tmp->vert);
			tmp = tmp->next;
		}
		ft_printf("\n");
		i++;
	}
}
