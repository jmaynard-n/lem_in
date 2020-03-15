/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_oblako.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:58:32 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/14 23:26:59 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_is_begin(t_peaks *p)
{
	if (p == g_par->head_peak)
		return (1);
	return (0);
}

int		ft_is_end(t_peaks *p)
{
	t_peaks *tmp;

	tmp = g_par->head_peak;
	while (tmp && tmp->next && (ft_heaven_or_hell((tmp->next)->line)) == 1)
		tmp = tmp->next;
	if (p == tmp)
		return (1);
	return (0);
}

int		ft_find_koord_obl(t_peaks *p1, int *x, int *y)
{
	*x = ft_find_x_koord(p1->line);
	*y = ft_find_y_koord(p1->line);
	*x -= 60;
	*y -= 30;
	if (ft_is_begin(p1))
		return (1);
	if (ft_is_end(p1))
		return (2);
	return (0);
}

int		ft_put_oblako(t_peaks *p1)
{
	int x;
	int y;
	int flag;

	flag = ft_find_koord_obl(p1, &x, &y);
	if (flag == -1)
		return (-1);
	if (flag == 0)
	{
		mlx_put_image_to_window(g_par->mlx, g_par->win, g_par->obl_start, x, y);
	}
	else if (flag == 1)
	{
		mlx_put_image_to_window(g_par->mlx, g_par->win, g_par->obl_us, x, y);
	}
	else if (flag == 2)
	{
		mlx_put_image_to_window(g_par->mlx, g_par->win, g_par->obl_end, x, y);
	}
	return (0);
}
