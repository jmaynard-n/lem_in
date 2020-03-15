/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refill_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:52:21 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/14 22:52:48 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_refill_struct_help(t_ants **tmp)
{
	char *to;
	char *from;

	if (!(to = ft_strdup((*tmp)->to)))
		return (-1);
	if (!(from = ft_strdup((*tmp)->from)))
		return (-1);
	ft_strdel(&((*tmp)->to));
	ft_strdel(&((*tmp)->from));
	if (!((*tmp)->to = ft_strdup(from)))
		return (-1);
	if (!((*tmp)->from = ft_strdup(to)))
		return (-1);
	ft_strdel(&to);
	ft_strdel(&from);
	return (0);
}

int		ft_refill_struct_help_h(t_ants **tmp, char *end_name)
{
	ft_strdel(&((*tmp)->to));
	if (!((*tmp)->to = ft_strdup("-")))
		return (-1);
	ft_strdel(&((*tmp)->from));
	if (!((*tmp)->from = ft_strdup(end_name)))
		return (-1);
	return (0);
}

int		ft_refill_struct_help_hh(t_ants **tmp)
{
	ft_strdel(&((*tmp)->from));
	if (!((*tmp)->from = ft_strdup("-")))
		return (-1);
	return (0);
}

int		ft_refill_struct(void)
{
	t_ants		*tmp;
	char		*end_name;
	t_peaks		*end;

	ft_find_list_end_true(g_par->head_peak, &end);
	if (ft_find_peak_name_1(end, &end_name) == -1)
		return (-1);
	tmp = g_par->head_ants;
	while (tmp)
	{
		if (!ft_strcmp(tmp->to, end_name))
		{
			if (ft_refill_struct_help_h(&tmp, end_name) == -1)
				return (-1);
		}
		else if ((!ft_strcmp(tmp->from, end_name)) &&
					(ft_refill_struct_help_hh(&tmp) == -1))
			return (-1);
		else if ((ft_strcmp(tmp->to, "-")) &&
					(ft_refill_struct_help(&tmp) == -1))
			return (-1);
		tmp = tmp->next;
	}
	ft_strdel(&end_name);
	return (0);
}
