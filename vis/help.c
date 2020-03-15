/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:50:56 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/16 19:15:17 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_find_obl_koord_help(int *x, int *y)
{
	t_peaks	*end;
	char	*name;

	ft_find_list_end_true(g_par->head_peak, &end);
	ft_find_koord_obl_name(end, x, y);
	if (ft_find_peak_name_1(end, &name) == -1)
		return (-1);
	ft_strdel(&name);
	return (0);
}

int		ft_change_yx(int y1, int y0)
{
	if (y1 >= y0)
		return (1);
	else
		return (-1);
}

int		key_hook(int keycode, void *param)
{
	param = NULL;
	if (keycode == 53)
	{
		mlx_destroy_window(g_par->mlx, g_par->win);
	}
	ft_free_peaks();
	ft_free_ants();
	ft_free_par();
	exit(EXIT_SUCCESS);
	return (0);
}
