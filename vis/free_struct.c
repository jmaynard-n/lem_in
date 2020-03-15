/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:16:36 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/18 10:03:39 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

void	ft_free_peaks(void)
{
	t_peaks		*tmp;
	void		*t;

	if (!g_par)
		return ;
	tmp = g_par->head_peak;
	while (tmp)
	{
		ft_strdel(&tmp->line);
		t = tmp->next;
		free(tmp);
		tmp = t;
	}
}

void	ft_free_ants(void)
{
	t_ants		*tmp;
	void		*t;

	if (!g_par)
		return ;
	tmp = g_par->head_ants;
	while (tmp)
	{
		ft_strdel(&(tmp->from));
		ft_strdel(&(tmp->to));
		t = tmp->next;
		free(tmp);
		tmp = t;
	}
}

void	ft_free_par(void)
{
	if (!g_par)
		return ;
	if (g_par->mlx)
		free(g_par->mlx);
	if (g_par->raduga)
		free(g_par->raduga);
	if (g_par->muravey)
		free(g_par->muravey);
	if (g_par->obl_start)
		free(g_par->obl_start);
	if (g_par->obl_us)
		free(g_par->obl_us);
	if (g_par->obl_end)
		free(g_par->obl_end);
	if (g_par)
		free(g_par);
}
