/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:41:54 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/16 16:25:52 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int		ft_del_link(const int where, const int what, t_graph *graph)
{
	t_vert *prev;
	t_vert *curr;
	t_vert *next;

	if ((unsigned)where > g_graph->size
		|| (unsigned)what > g_graph->size || !graph)
		return (0);
	curr = graph->array[where];
	prev = NULL;
	next = NULL;
	while (curr && curr->vert != what)
	{
		prev = curr;
		curr = curr->next;
	}
	if (!curr)
		return (1);
	next = curr->next;
	free(curr);
	if (prev)
		prev->next = next;
	else
		graph->array[where] = next;
	return (1);
}
