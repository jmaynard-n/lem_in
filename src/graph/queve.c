/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 09:47:37 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/16 18:58:27 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

int				ft_queve(t_vert **q, int vert)
{
	t_vert *tmp;

	tmp = *q;
	if ((unsigned)vert > g_graph->size || vert < 0)
		return (0);
	if (!(*q))
	{
		if (!((*q) = (t_vert *)malloc(sizeof(t_vert))))
			return (0);
		(*q)->vert = vert;
		(*q)->next = NULL;
		return (1);
	}
	while (tmp->next)
	{
		if (tmp->vert == vert)
			return (0);
		tmp = tmp->next;
	}
	if (!(tmp->next = (t_vert *)malloc(sizeof(t_vert))))
		return (0);
	(tmp->next)->vert = vert;
	tmp = tmp->next;
	tmp->next = NULL;
	return (1);
}

static int		ft_help_qs(t_vert **q, int vert)
{
	if ((unsigned)vert > g_graph->size || vert < 0)
		return (0);
	if (!((*q) = (t_vert *)malloc(sizeof(t_vert))))
		return (0);
	(*q)->vert = vert;
	(*q)->next = NULL;
	return (1);
}

int				ft_queve_smart(t_vert **q, int *dis, int vert)
{
	t_vert *tmp;
	t_vert *prev;
	t_vert *new;

	tmp = *q;
	prev = NULL;
	if (!(*q))
		return (ft_help_qs(q, vert));
	if (!(new = (t_vert *)malloc(sizeof(t_vert))) ||
			(unsigned)vert > g_graph->size || vert < 0)
		return (0);
	new->vert = vert;
	while (tmp && dis[tmp->vert] >= dis[vert])
	{
		if (tmp->vert == vert)
			return (1);
		prev = tmp;
		tmp = tmp->next;
	}
	new->next = tmp;
	if (!prev)
		*q = new;
	else
		prev->next = new;
	return (1);
}

int				ft_enqueve(t_vert **q)
{
	t_vert *tmp;

	tmp = *q;
	if (*q)
	{
		*q = (*q)->next;
		free(tmp);
	}
	return (1);
}
