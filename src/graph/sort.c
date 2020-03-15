/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:44:15 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/14 18:26:53 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

static void	ft_swap(t_vert *ptmp, t_vert *tmp)
{
	unsigned int	mp;

	mp = ptmp->vert;
	ptmp->vert = tmp->vert;
	tmp->vert = mp;
}

int			ft_list_len(t_vert *tmp)
{
	t_vert		*t;
	int			len;

	t = tmp;
	len = 0;
	while (t)
	{
		len++;
		t = t->next;
	}
	return (len);
}

void		ft_sort(int *dis)
{
	t_vert			*tmp;
	t_vert			*ptmp;
	unsigned int	i;
	int				j;
	int				len;

	i = -1;
	while (++i < g_graph->size)
	{
		tmp = g_graph->array[i];
		j = -1;
		len = ft_list_len(tmp);
		while (++j < len)
		{
			ptmp = g_graph->array[i];
			tmp = ptmp->next;
			while (tmp)
			{
				if (dis[ptmp->vert] > dis[tmp->vert])
					ft_swap(ptmp, tmp);
				ptmp = tmp;
				tmp = tmp->next;
			}
		}
	}
}
