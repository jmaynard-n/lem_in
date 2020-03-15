/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_koord_help_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:56:16 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/18 10:38:32 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_change_xy_koord(t_peaks *head, t_peaks *head_con, int minx, int miny)
{
	t_peaks *tmp;

	tmp = head;
	while (tmp != head_con)
	{
		if (ft_minus_xy_koord(&(tmp->line), minx, miny) == -1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_plus_xy_koord(t_peaks *head, t_peaks *head_con, int minx, int miny)
{
	t_peaks *tmp;

	tmp = head;
	while (tmp != head_con)
	{
		if (ft_plus_xy_koord_h(&(tmp->line), minx, miny) == -1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_move_to_begin(t_peaks *head_con)
{
	int minx;
	int miny;

	minx = ft_find_min_x(g_par->head_peak, head_con);
	miny = ft_find_min_y(g_par->head_peak, head_con);
	if (ft_change_xy_koord(g_par->head_peak, head_con, minx, miny) == -1)
		return (-1);
	return (0);
}

int		ft_mult_koord(char **line, float delx, float dely)
{
	char	*p;
	int		x;
	int		y;

	if (ft_find_peak_name(*line, &p) == -1)
		return (-1);
	x = ft_find_x_koord(*line);
	y = ft_find_y_koord(*line);
	if (delx < dely)
	{
		x *= delx;
		y *= delx;
	}
	else
	{
		x *= dely;
		y *= dely;
	}
	ft_strdel(line);
	if (ft_write_line(line, p, x, y) == -1)
		return (-1);
	ft_strdel(&p);
	return (0);
}

int		ft_multiply_koord(t_peaks *head, t_peaks *head_con,
	float delx, float dely)
{
	t_peaks *tmp;

	tmp = head;
	while (tmp != head_con)
	{
		if (ft_mult_koord(&(tmp->line), delx, dely) == -1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
