/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 16:33:07 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/16 18:56:29 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static int		ft_null_vert(int end)
{
	unsigned int	k;
	t_vert			*tmp;

	k = 0;
	while (k < g_graph->size)
	{
		if (k == (unsigned int)end)
		{
			k++;
			continue ;
		}
		tmp = g_graph->array[k];
		if (!tmp)
			return (k);
		k++;
	}
	return (0);
}

void			ft_clean_graph(int end)
{
	unsigned int	i;
	unsigned int	j;
	t_vert			*tmp;

	i = 0;
	while ((i = ft_null_vert(end)))
	{
		tmp = g_graph->array[i];
		if (!tmp)
		{
			j = 0;
			while (j < g_graph->size)
			{
				ft_del_link(j, i, g_graph);
				j++;
			}
			ft_add_to_graph(g_graph, i, -1);
		}
	}
}
