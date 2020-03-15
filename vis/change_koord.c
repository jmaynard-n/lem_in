/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_koord.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 15:03:52 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/18 10:38:13 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_stretch_graph(t_peaks *head_con)
{
	int		maxx;
	int		maxy;
	float	delx;
	float	dely;

	maxx = ft_find_max_x(g_par->head_peak, head_con);
	maxy = ft_find_max_y(g_par->head_peak, head_con);
	delx = (float)1000 / (float)maxx;
	dely = (float)600 / (float)maxy;
	if (ft_multiply_koord(g_par->head_peak, head_con, delx, dely) == -1)
		return (-1);
	return (0);
}

int		ft_move_from_begin(t_peaks *head_con)
{
	int midx;
	int midy;
	int miny;
	int maxx;
	int maxy;

	miny = ft_find_min_y(g_par->head_peak, head_con);
	maxx = ft_find_max_x(g_par->head_peak, head_con);
	maxy = ft_find_max_y(g_par->head_peak, head_con);
	midx = (ft_find_min_x(g_par->head_peak, head_con) + 1200 - maxx) / 2 -
			ft_find_min_x(g_par->head_peak, head_con);
	midy = (miny + 800 - maxy) / 2 - miny;
	if (ft_plus_xy_koord(g_par->head_peak, head_con, midx, midy) == -1)
		return (-1);
	return (0);
}

int		ft_change_koord_peaks(t_peaks *head_con)
{
	if (ft_move_to_begin(head_con) == -1)
		return (-1);
	if (ft_stretch_graph(head_con) == -1)
		return (-1);
	if (ft_move_from_begin(head_con) == -1)
		return (-1);
	return (0);
}

void	ft_init_init(void)
{
	g_par->mlx = NULL;
	g_par->win = NULL;
	g_par->raduga = NULL;
	g_par->muravey = NULL;
	g_par->obl_start = NULL;
	g_par->obl_us = NULL;
	g_par->obl_end = NULL;
	g_par->head_ants = NULL;
	g_par->head_peak = NULL;
}
