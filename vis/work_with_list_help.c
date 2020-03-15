/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_list_help.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:41:30 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/16 18:09:52 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_put_to_begin_list(char *line)
{
	t_peaks *tmp;

	if (g_par->head_peak == NULL)
	{
		if (!((g_par->head_peak) = (t_peaks *)malloc(sizeof(t_peaks))))
			return (-1);
		if (!((g_par->head_peak)->line = ft_strdup(line)))
			return (-1);
		(g_par->head_peak)->next = NULL;
	}
	else
	{
		if (!((tmp) = (t_peaks *)malloc(sizeof(t_peaks))))
			return (-1);
		if (!((tmp)->line = ft_strdup(line)))
			return (-1);
		tmp->next = g_par->head_peak;
		g_par->head_peak = tmp;
	}
	return (0);
}

int		ft_put_to_end_list(char *line)
{
	t_peaks *tmp;

	if (g_par->head_peak == NULL)
	{
		if (!((g_par->head_peak) = (t_peaks *)malloc(sizeof(t_peaks))))
			return (-1);
		if (!((g_par->head_peak)->line = ft_strdup(line)))
			return (-1);
		(g_par->head_peak)->next = NULL;
	}
	else
	{
		tmp = g_par->head_peak;
		while (tmp && tmp->next)
			tmp = tmp->next;
		if (!((tmp->next) = (t_peaks *)malloc(sizeof(t_peaks))))
			return (-1);
		tmp = tmp->next;
		if (!((tmp)->line = ft_strdup(line)))
			return (-1);
		tmp->next = NULL;
	}
	return (0);
}
