/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_ant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:56:24 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/14 21:43:23 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_find_con(t_peaks **con)
{
	t_peaks *tmp;

	tmp = g_par->head_peak;
	while (tmp && (ft_heaven_or_hell(tmp->line) == 1))
		tmp = tmp->next;
	*con = tmp;
	return (0);
}

int		ft_find_peak_name_help(char **end_name)
{
	t_peaks		*end;

	ft_find_list_end_true(g_par->head_peak, &end);
	if (ft_find_peak_name_1(end, end_name) == -1)
		return (-1);
	return (0);
}

int		ft_find_peak_name_help_h(t_peaks **t, char **name, t_ants *tmp)
{
	*t = g_par->head_peak;
	while (*t)
	{
		if (ft_find_peak_name_1(*t, name) == -1)
			return (-1);
		if (!ft_strcmp(*name, tmp->from))
		{
			ft_strdel(name);
			break ;
		}
		ft_strdel(name);
		*t = (*t)->next;
	}
	return (0);
}

int		ft_put_certain_ants(int x, int y)
{
	t_ants		*tmp;
	t_peaks		*t;
	char		*name;
	char		*end_name;

	if (ft_find_peak_name_help(&end_name) == -1)
		return (-1);
	tmp = g_par->head_ants;
	name = NULL;
	while (tmp)
	{
		if (!(tmp->pos == 1 || tmp->pos == 2))
			if (ft_strcmp(tmp->to, "-") || (!(ft_strcmp(tmp->from, end_name))))
			{
				if (ft_find_peak_name_help_h(&t, &name, tmp) == -1)
					return (-1);
				ft_find_koord_obl(t, &x, &y);
				mlx_put_image_to_window(g_par->mlx, g_par->win,
						g_par->muravey, x - 25, y - 50);
			}
		tmp = tmp->next;
	}
	ft_strdel(&end_name);
	return (0);
}

int		ft_delete_ants(void)
{
	t_peaks *con;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx_clear_window(g_par->mlx, g_par->win);
	mlx_put_image_to_window(g_par->mlx, g_par->win, g_par->raduga, 0, 0);
	ft_find_con(&con);
	if (ft_draw_lines(con) == -1)
		return (-1);
	if (ft_put_certain_ants(x, y) == -1)
		return (-1);
	return (0);
}
