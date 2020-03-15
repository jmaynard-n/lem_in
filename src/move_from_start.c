/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_from_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:58:01 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/18 11:12:26 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

static void		ft_move_rest(int *dis, int *aval, t_vert **mv_ants,
								t_vert *prev_vert)
{
	int vert;
	int res;

	while ((vert = ft_find_vert(dis, aval, *mv_ants, prev_vert)) > -1)
	{
		if (aval[vert] == 0)
			continue;
		if ((res = ft_try_way(aval, vert, mv_ants)) == 2)
			ft_free_mv(&prev_vert);
		else
		{
			ft_queve(&prev_vert, vert);
			continue;
		}
	}
}

static void		ft_new_ant_move(int *i, int vert, t_vert **mv_ants, int *aval)
{
	ft_print_instr(*i, vert);
	ft_add_to_queve(mv_ants, *i);
	if (vert == g_end)
		aval[g_end]++;
	else
		aval[vert] = *i;
	aval[g_start]--;
	(*i)++;
}

static void		ft_start_new_turn(int start, t_vert **mv_ants, int *turn)
{
	if (start > 0)
	{
		ft_free_mv(mv_ants);
		ft_printf("\n");
		(*turn)--;
	}
}

void			ft_move_from_start(int *aval, int *dis,
			t_vert **mv_ants, t_vert **prev_vert)
{
	t_vert	*tmp;
	int		i;
	int		n;
	int		turn;

	i = 1;
	turn = ft_get_turn(aval[g_start], dis);
	while (aval[g_start] > 0)
	{
		tmp = g_graph->array[g_start];
		n = ft_sense(aval[g_start], dis, turn);
		while (tmp && aval[g_start] > 0)
		{
			ft_try_way(aval, tmp->vert, mv_ants);
			if ((aval[tmp->vert] == 0 || tmp->vert == g_end) && n)
			{
				ft_new_ant_move(&i, tmp->vert, mv_ants, aval);
				n--;
			}
			tmp = tmp->next;
		}
		ft_move_rest(dis, aval, mv_ants, *prev_vert);
		ft_start_new_turn(aval[g_start], mv_ants, &turn);
	}
}
