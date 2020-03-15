/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 11:55:06 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/16 18:57:11 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

static int		ft_add_cond(int vert, int **dis, t_graph *gr, t_vert *tmp)
{
	if (vert != g_start && (*dis)[vert] < (*dis)[tmp->vert])
	{
		if (!(ft_del_link(vert, tmp->vert, g_graph)))
			return (0);
	}
	else if (!(ft_add_to_graph(gr, tmp->vert, vert)))
		return (0);
	return (1);
}

static int		ft_orient(int *visited, int *income, int **dis, t_graph *gr)
{
	int		vert;
	t_vert	*queve;
	t_vert	*t;

	queve = NULL;
	ft_queve(&queve, g_start);
	while (queve)
	{
		vert = queve->vert;
		visited[vert] = 1;
		ft_enqueve(&queve);
		t = g_graph->array[vert];
		while (t)
		{
			if (visited[t->vert] == 0 && t->vert != g_end)
				ft_queve_smart(&queve, *dis, t->vert);
			visited[t->vert] = 1;
			if (!(ft_del_link(t->vert, vert, g_graph))
				|| !(ft_add_cond(vert, dis, gr, t)))
				return (0);
			income[t->vert] = t->vert != g_end ? vert : income[t->vert] + 1;
			t = t->next;
		}
	}
	return (1);
}

static int		ft_direct_error(int *visited, int *income, t_graph *gr)
{
	if (income)
		free(income);
	if (visited)
		free(visited);
	if (gr)
		ft_graph_free(gr);
	return (0);
}

static int		ft_contin_dir(int *income, int **dis, t_graph *gr, int *visited)
{
	if (income[g_end] == 0)
		return (ft_direct_error(visited, income, gr));
	ft_clean_graph(g_end);
	free(*dis);
	if (!(ft_distance(gr, dis)))
		return (ft_direct_error(visited, income, gr));
	ft_sort(*dis);
	if ((*dis)[g_start] == 0)
		return (ft_direct_error(visited, income, gr));
	if (!(ft_path(dis, gr)))
		return (ft_direct_error(visited, income, gr));
	ft_graph_free(gr);
	free(visited);
	free(income);
	return (1);
}

int				ft_direct(int **dis)
{
	int		*visited;
	int		*income;
	t_graph *gr;

	gr = NULL;
	if (!(ft_distance(g_graph, dis)))
		return (0);
	ft_sort(*dis);
	if ((*dis)[g_start] == 0)
		return (0);
	if (!(visited = (int *)malloc(sizeof(int) * g_graph->size)))
		return (0);
	if (!(income = (int *)malloc(sizeof(int) * g_graph->size)))
		return (ft_direct_error(visited, income, gr));
	ft_set(&visited, g_graph->size);
	ft_set_1(&income, g_graph->size);
	income[g_end] = 0;
	if (!(gr = ft_graph_create(g_graph->size)))
		return (ft_direct_error(visited, income, gr));
	if (!(ft_orient(visited, income, dis, gr)))
		return (ft_direct_error(visited, income, gr));
	return (ft_contin_dir(income, dis, gr, visited));
}
