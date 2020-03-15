/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 14:23:08 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/16 16:58:35 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static int	ft_help(t_vert *tmp, int *visited, t_graph *gr)
{
	t_vert	*path;
	t_vert	*t;
	int		vert;

	vert = tmp->vert;
	path = g_graph->array[tmp->vert];
	while (path)
	{
		if (path->vert == -1)
			break ;
		if (visited[path->vert] == 0 || path->vert == g_end)
		{
			visited[path->vert] = 1;
			vert = path->vert;
			path = g_graph->array[path->vert];
			continue ;
		}
		t = path->next;
		if (!(ft_del_link(vert, path->vert, g_graph)))
			return (0);
		if (!(ft_del_link(path->vert, vert, gr)))
			return (0);
		path = t;
	}
	return (1);
}

static int	ft_check_path(int *visited, t_graph *gr)
{
	t_vert	*tmp;

	tmp = g_graph->array[g_start];
	while (tmp)
	{
		if (!(ft_help(tmp, visited, gr)))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			ft_path(int **dis, t_graph *gr)
{
	t_vert	*tmp;
	int		*visited;

	if (!(visited = (int *)malloc(sizeof(int) * g_graph->size)))
		return (0);
	ft_set(&visited, g_graph->size);
	tmp = g_graph->array[g_start];
	while (tmp)
	{
		visited[tmp->vert] = 1;
		tmp = tmp->next;
	}
	if (!(ft_check_path(visited, gr)))
		return (0);
	free(visited);
	ft_clean_graph(g_end);
	free(*dis);
	if (!(ft_distance(gr, dis)))
		return (0);
	ft_sort(*dis);
	return (1);
}
