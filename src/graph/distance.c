/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:49:20 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/14 16:59:14 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

static void		ft_calc(t_graph *graph, int **dis, int *visited, t_vert *queve)
{
	int		vert;
	t_vert	*tmp;

	while (queve)
	{
		vert = queve->vert;
		visited[vert] = 1;
		ft_enqueve(&queve);
		tmp = graph->array[vert];
		while (tmp)
		{
			if (visited[tmp->vert] == 0)
			{
				if (tmp->vert != g_start)
					ft_queve(&queve, tmp->vert);
				visited[tmp->vert] = 1;
			}
			if ((*dis)[tmp->vert] == 0 && tmp->vert != g_end)
				(*dis)[tmp->vert] = (*dis)[vert] + 1;
			else if ((*dis)[vert] + 1 < (*dis)[tmp->vert] && tmp->vert != g_end)
				(*dis)[tmp->vert] = (*dis)[vert] + 1;
			tmp = tmp->next;
		}
	}
}

int				ft_distance(t_graph *graph, int **dis)
{
	int		*visited;
	t_vert	*queve;

	if (!(*dis = (int *)malloc(sizeof(int) * graph->size)))
		return (0);
	if (!(visited = (int *)malloc(sizeof(int) * graph->size)))
		return (0);
	ft_set(&visited, graph->size);
	ft_set(dis, graph->size);
	queve = NULL;
	ft_queve(&queve, g_end);
	ft_calc(graph, dis, visited, queve);
	free(visited);
	return (1);
}
