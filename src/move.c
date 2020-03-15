/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 10:27:22 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/16 16:46:29 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	ft_set(int **arr, size_t size)
{
	size_t i;

	i = 0;
	if (!arr || !(*arr))
		return ;
	while (arr && i < size)
	{
		(*arr)[i] = 0;
		i++;
	}
}

void	ft_set_1(int **arr, size_t size)
{
	size_t i;

	i = 0;
	if (!arr || !(*arr))
		return ;
	while (arr && i < size)
	{
		(*arr)[i] = -1;
		i++;
	}
}

void	ft_move(int *dis, int ants)
{
	int		*aval;
	t_vert	*mv_ants;
	t_vert	*prev_vert;

	if (!(aval = (int *)malloc(sizeof(int) * g_graph->size)))
		return ;
	ft_set(&aval, g_graph->size);
	aval[g_start] = ants;
	mv_ants = NULL;
	prev_vert = NULL;
	ft_move_from_start(aval, dis, &mv_ants, &prev_vert);
	dis[g_start] = -1;
	ft_move_to_end(aval, &mv_ants, dis, ants);
	ft_printf("\n");
	free(aval);
	aval = NULL;
}
