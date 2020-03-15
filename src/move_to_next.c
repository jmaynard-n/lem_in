/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 14:34:52 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/14 20:24:28 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	ft_free_mv(t_vert **mv)
{
	t_vert *tmp;

	while (*mv)
	{
		tmp = (*mv)->next;
		free(*mv);
		*mv = tmp;
	}
	*mv = NULL;
}

int		ft_add_to_queve(t_vert **queve, int vert)
{
	t_vert *new;

	if (!(*queve))
	{
		*queve = (t_vert *)malloc(sizeof(t_vert));
		(*queve)->vert = vert;
		(*queve)->next = NULL;
	}
	else
	{
		new = (t_vert *)malloc(sizeof(t_vert));
		new->vert = vert;
		new->next = *queve;
		(*queve) = new;
	}
	return (0);
}

int		ft_moving(int *aval, int vert, int peak, t_vert **mv_ants)
{
	if (peak == g_end && aval[vert] != 0)
	{
		ft_print_instr(aval[vert], peak);
		ft_add_to_queve(mv_ants, aval[vert]);
		aval[g_end]++;
		aval[vert] = 0;
	}
	else if (aval[peak] == 0 && aval[vert] != 0)
	{
		ft_print_instr(aval[vert], peak);
		ft_add_to_queve(mv_ants, aval[vert]);
		aval[peak] = aval[vert];
		aval[vert] = 0;
	}
	else
		return (0);
	return (2);
}

int		ft_try_way(int *aval, int vert, t_vert **mv_ants)
{
	t_vert	*tmp;
	int		peak;
	int		res;

	res = 1;
	if (!(tmp = g_graph->array[vert]))
		return (0);
	if (vert == g_end)
		return (2);
	peak = tmp->vert;
	res = ft_move_to_next(aval, vert, peak, mv_ants);
	tmp = tmp->next;
	if (!tmp && res <= 1)
		return (res);
	return (res);
}

int		ft_move_to_next(int *aval, int vert, int peak, t_vert **mv_ants)
{
	int res;

	res = 0;
	if (peak != g_end && aval[peak] != 0 &&
		aval[vert] != 0 && !ft_turn(aval[peak], *mv_ants))
		ft_try_way(aval, peak, mv_ants);
	else if (peak != g_end && ft_turn(aval[peak], *mv_ants))
		return (1);
	else if (peak != g_end && aval[peak] != 0 &&
		aval[vert] == 0 && !ft_turn(aval[peak], *mv_ants))
		ft_try_way(aval, peak, mv_ants);
	if (ft_moving(aval, vert, peak, mv_ants))
		return (2);
	return (res);
}
