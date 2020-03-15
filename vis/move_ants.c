/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:57:46 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/14 23:24:17 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_put_to_begin_help(t_ants **tmp)
{
	t_peaks		*t;
	char		*name;
	int			x;
	int			y;

	t = g_par->head_peak;
	while (t)
	{
		if (ft_find_peak_name_1(t, &name) == -1)
			return (-1);
		if (!ft_strcmp(name, (*tmp)->from))
		{
			ft_strdel(&name);
			break ;
		}
		ft_strdel(&name);
		t = t->next;
	}
	ft_find_koord_obl(t, &x, &y);
	mlx_put_image_to_window(g_par->mlx, g_par->win,
							g_par->muravey, x + 25, y - 50);
	(*tmp)->pos = 1;
	return (0);
}

int		ft_put_to_begin(void)
{
	t_ants		*tmp;
	t_peaks		*end;
	char		*end_name;

	ft_find_list_end_true(g_par->head_peak, &end);
	if (ft_find_peak_name_1(end, &end_name) == -1)
		return (-1);
	tmp = g_par->head_ants;
	while (tmp)
	{
		if ((ft_strcmp(tmp->to, "-")) || (!(ft_strcmp(tmp->from, end_name))))
		{
			if (ft_put_to_begin_help(&tmp) == -1)
				return (-1);
		}
		tmp = tmp->next;
	}
	ft_strdel(&end_name);
	return (0);
}

int		ft_put_to_middle_help(t_ants **tmp, int *x, int *y)
{
	char		*name;
	t_peaks		*t;

	t = g_par->head_peak;
	while (t)
	{
		if (ft_find_peak_name_1(t, &name) == -1)
			return (-1);
		if (!ft_strcmp(name, (*tmp)->from))
		{
			ft_strdel(&name);
			break ;
		}
		ft_strdel(&name);
		t = t->next;
	}
	ft_find_koord_obl(t, x, y);
	return (0);
}

int		ft_put_to_middle_help_h(t_ants **tmp, int *x1, int *y1)
{
	char		*name;
	t_peaks		*te;

	te = g_par->head_peak;
	while (te)
	{
		if (ft_find_peak_name_1(te, &name) == -1)
			return (-1);
		if (!ft_strcmp(name, (*tmp)->to))
		{
			ft_strdel(&name);
			break ;
		}
		ft_strdel(&name);
		te = te->next;
	}
	ft_find_koord_obl(te, x1, y1);
	return (0);
}

int		ft_put_to_middle(void)
{
	t_ants		*tmp;
	int			x;
	int			y;
	int			x1;
	int			y1;

	tmp = g_par->head_ants;
	while (tmp)
	{
		if (ft_strcmp(tmp->to, "-"))
		{
			if (ft_put_to_middle_help(&tmp, &x, &y) == -1)
				return (-1);
			y += 30;
			if (ft_put_to_middle_help_h(&tmp, &x1, &y1) == -1)
				return (-1);
			x1 += 60;
			y1 += 30;
			mlx_put_image_to_window(g_par->mlx, g_par->win, g_par->muravey,
									(x + 60 + x1) / 2 - 35, (y + y1) / 2 - 80);
			tmp->pos = 2;
		}
		tmp = tmp->next;
	}
	return (0);
}
