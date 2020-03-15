/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_end.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:15:01 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/18 11:12:09 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int				ft_turn(unsigned int ant, t_vert *mv)
{
	t_vert *tmp;

	tmp = mv;
	if (!mv)
		return (0);
	while (tmp && ant != 0)
	{
		if ((unsigned int)tmp->vert == ant)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int				ft_find_vert(int *dis, int *aval, t_vert *mv_ants,
								t_vert *prev_vert)
{
	unsigned int	i;
	int				max;
	int				ind;

	i = 0;
	ind = -1;
	max = -1;
	while (i < g_graph->size)
	{
		if (dis[i] > max && !ft_turn(aval[i], mv_ants) && !ft_turn(i, prev_vert)
			&& i != (unsigned)g_end && i != (unsigned)g_start && aval[i] != 0)
		{
			max = dis[i];
			ind = i;
		}
		i++;
	}
	return (ind);
}

static int		ft_get_vert(int *aval, t_vert **mv_ants, int *dis,
								t_vert **prev_vert)
{
	int vert;

	if ((vert = ft_find_vert(dis, aval, *mv_ants, *prev_vert)) == -1)
	{
		vert = ft_find_vert(dis, aval, *mv_ants, NULL);
		if (!ft_turn(vert, *prev_vert) && vert != -1)
			ft_free_mv(prev_vert);
		else if (ft_turn(vert, *prev_vert) || vert == -1)
		{
			if ((vert = ft_find_vert(dis, aval, NULL, *prev_vert)) == -1)
			{
				if ((vert = ft_find_vert(dis, aval, NULL, NULL)) == -1)
					return (-1);
				ft_free_mv(prev_vert);
				ft_free_mv(mv_ants);
				ft_printf("\n");
			}
			else
			{
				ft_free_mv(mv_ants);
				ft_printf("\n");
			}
		}
	}
	return (vert);
}

void			ft_move_to_end(int *aval, t_vert **mv_ants, int *dis, int ants)
{
	int		vert;
	int		res;
	t_vert	*prev_vert;

	res = 0;
	prev_vert = NULL;
	while (aval[g_end] < ants)
	{
		if ((vert = ft_get_vert(aval, mv_ants, dis, &prev_vert)) == -1)
			break ;
		if (aval[vert] != 0)
		{
			if ((res = ft_try_way(aval, vert, mv_ants)) == 2)
				ft_free_mv(&prev_vert);
			else
			{
				ft_queve(&prev_vert, vert);
				continue ;
			}
		}
	}
	ft_free_mv(mv_ants);
}
