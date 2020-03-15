/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sence.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:53:17 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/14 19:56:48 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int		ft_get_turn(int ants, int *dis)
{
	t_vert	*tmp;
	int		len;
	int		res;
	int		k;
	int		t;

	k = 1;
	len = 0;
	res = 2147483647;
	tmp = g_graph->array[g_start];
	while (tmp)
	{
		len += dis[tmp->vert] + 1;
		if (((ants + len) % k) == 0)
			t = ((ants + len) / k) - 1;
		else
			t = (ants + len) / k;
		if (t < res)
			res = t;
		else
			break ;
		tmp = tmp->next;
		k++;
	}
	return (res);
}

int		ft_sense(int ants, int *dis, int turn)
{
	t_vert	*tmp;
	int		len;
	int		t;
	int		k;

	len = 0;
	k = 1;
	tmp = g_graph->array[g_start];
	while (tmp)
	{
		len += dis[tmp->vert] + 1;
		if (((ants + len) % k) == 0)
			t = ((ants + len) / k) - 1;
		else
			t = (ants + len) / k;
		if (t <= turn)
			break ;
		tmp = tmp->next;
		k++;
	}
	return (k);
}
