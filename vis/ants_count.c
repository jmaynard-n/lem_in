/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:21:38 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/14 20:51:18 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_print_ants(int ants)
{
	int		x;
	int		y;
	char	*number;
	char	*name;
	char	*tmp;

	if (!(number = ft_itoa(g_ants - ants)))
		return (-1);
	ft_find_koord_obl_name(g_par->head_peak, &x, &y);
	if (ft_find_peak_name_1(g_par->head_peak, &name) == -1)
		return (-1);
	if (!(tmp = ft_strjoin("(", number)))
		return (-1);
	ft_strdel(&number);
	if (!(number = ft_strjoin(tmp, ")")))
		return (-1);
	ft_strdel(&tmp);
	mlx_string_put(g_par->mlx, g_par->win, x, y + 20, 0x483d8b, number);
	ft_strdel(&number);
	ft_strdel(&name);
	return (0);
}

int		ft_print_ants_count(int *ants)
{
	t_ants		*tmp;
	char		*name;
	static int	i;

	if (i % 2 == 0)
	{
		tmp = g_par->head_ants;
		if (ft_find_peak_name_1(g_par->head_peak, &name) == -1)
			return (-1);
		while (tmp)
		{
			if (!ft_strcmp(tmp->from, name) && ft_strcmp(tmp->to, "-"))
				(*ants)++;
			tmp = tmp->next;
		}
		ft_strdel(&name);
	}
	i++;
	return (0);
}

int		ft_print_ants_end(int ants)
{
	int		x;
	int		y;
	char	*number;
	char	*tmp;

	if (!(number = ft_itoa(ants)))
		return (-1);
	if (ft_find_obl_koord_help(&x, &y) == -1)
		return (-1);
	if (!(tmp = ft_strjoin("(", number)))
		return (-1);
	ft_strdel(&number);
	if (!(number = ft_strjoin(tmp, ")")))
		return (-1);
	ft_strdel(&tmp);
	mlx_string_put(g_par->mlx, g_par->win, x, y + 20, 0x483d8b, number);
	ft_strdel(&number);
	return (0);
}

int		ft_print_ants_count_end(int *ants)
{
	t_ants		*tmp;
	char		*name;
	static int	i;
	t_peaks		*end;

	tmp = g_par->head_ants;
	ft_find_list_end_true(g_par->head_peak, &end);
	if (ft_find_peak_name_1(end, &name) == -1)
		return (-1);
	while (tmp)
	{
		if (!ft_strcmp(tmp->to, name))
			(*ants)++;
		tmp = tmp->next;
	}
	ft_strdel(&name);
	i++;
	return (0);
}

int		ft_is_end_ants(void)
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
		if (!(!ft_strcmp(tmp->from, "-") && !ft_strcmp(tmp->to, "-")))
		{
			ft_strdel(&end_name);
			return (0);
		}
		tmp = tmp->next;
	}
	ft_strdel(&end_name);
	return (1);
}
