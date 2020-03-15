/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:54:49 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/14 21:32:36 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_create_line_norm_help(char *str, int col, int x, int y)
{
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	double	error;

	ft_find_t0_first(str, &x0, &y0);
	ft_find_t0_sec(str, &x1, &y1);
	x = x0;
	y = y0;
	error = 0;
	while (x != x1)
	{
		mlx_pixel_put(g_par->mlx, g_par->win, x, y, col);
		error = error + (double)ft_abs(y1, y0) / (double)ft_abs(x1, x0);
		if (error >= 0.5)
		{
			y += ft_change_yx(y1, y0);
			error -= 1;
		}
		x += ft_change_yx(x1, x0);
	}
	return (0);
}

int		ft_create_line_norm(char *str, int col)
{
	int x;
	int y;

	x = 0;
	y = 0;
	ft_create_line_norm_help(str, col, x, y);
	return (0);
}

int		ft_create_line_rev_help(char *str, int col, int x, int y)
{
	int		x0;
	int		x1;
	int		y0;
	int		y1;
	double	error;

	ft_find_t0_first(str, &x0, &y0);
	ft_find_t0_sec(str, &x1, &y1);
	x = x0;
	y = y0;
	error = 0;
	while (y != y1)
	{
		mlx_pixel_put(g_par->mlx, g_par->win, x, y, col);
		error = error + (double)ft_abs(x1, x0) / (double)ft_abs(y1, y0);
		if (error >= 0.5)
		{
			x += ft_change_yx(x1, x0);
			error -= 1;
		}
		y += ft_change_yx(y1, y0);
	}
	return (0);
}

int		ft_create_line_rev(char *str, int col)
{
	int x;
	int y;

	x = 0;
	y = 0;
	ft_create_line_rev_help(str, col, x, y);
	return (0);
}

int		ft_create_line(char *str, int col)
{
	if (ft_create_line_var(str, col) == -1)
		return (-1);
	return (0);
}
