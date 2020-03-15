/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:40:13 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/14 23:25:53 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_find_koord_obl_name(t_peaks *p1, int *x, int *y)
{
	*x = ft_find_x_koord(p1->line);
	*y = ft_find_y_koord(p1->line);
	*x -= 15;
	*y += 30;
	return (0);
}

int		ft_find_peak_name_1(t_peaks *p, char **name)
{
	int i;
	int l;

	l = 0;
	while (p && (p->line)[l] != ' ')
		l++;
	if (!(*name = (char *)malloc(sizeof(char) * (l + 1))))
		return (-1);
	i = 0;
	while (i < l)
	{
		(*name)[i] = (p->line)[i];
		i++;
	}
	(*name)[i] = '\0';
	return (0);
}

int		ft_put_name(t_peaks *p1)
{
	int		x;
	int		y;
	char	*name;

	ft_find_koord_obl_name(p1, &x, &y);
	if (ft_find_peak_name_1(p1, &name) == -1)
		return (-1);
	mlx_string_put(g_par->mlx, g_par->win, x, y, 0x483d8b, name);
	ft_strdel(&name);
	return (0);
}
