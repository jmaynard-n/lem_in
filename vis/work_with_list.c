/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 10:51:42 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/15 11:49:50 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

void	ft_find_list_end(t_peaks **tmp_p)
{
	t_peaks *t;

	if (!(g_par->head_peak))
	{
		*tmp_p = NULL;
		return ;
	}
	t = g_par->head_peak;
	while (t && t->next)
	{
		t = t->next;
	}
	*tmp_p = t;
}

int		ft_put_before_last_list_help(char *line)
{
	t_peaks *tmp;

	if (!(tmp = (t_peaks *)malloc(sizeof(t_peaks))))
		return (-1);
	if (!(tmp->line = ft_strdup(line)))
		return (-1);
	tmp->next = g_par->head_peak;
	g_par->head_peak = tmp;
	return (0);
}

int		ft_put_before_last_list_help_h(char *line)
{
	t_peaks *tmp;

	if (!(tmp = (t_peaks *)malloc(sizeof(t_peaks))))
		return (-1);
	if (!(tmp->line = ft_strdup(line)))
		return (-1);
	tmp->next = NULL;
	g_par->head_peak = tmp;
	return (0);
}

int		ft_put_before_last_list(char *line)
{
	t_peaks *tmp;
	t_peaks *peak;

	if (g_par->head_peak == NULL)
	{
		if (ft_put_before_last_list_help_h(line) == -1)
			return (-1);
		return (0);
	}
	else if (g_par->head_peak && (g_par->head_peak)->next == NULL)
	{
		if (ft_put_before_last_list_help(line) == -1)
			return (-1);
		return (0);
	}
	tmp = g_par->head_peak;
	while (tmp && tmp->next && (tmp->next)->next)
		tmp = tmp->next;
	if (!(peak = (t_peaks *)malloc(sizeof(t_peaks))))
		return (-1);
	if (!(peak->line = ft_strdup(line)))
		return (-1);
	peak->next = tmp->next;
	tmp->next = peak;
	return (0);
}

int		ft_put_after_first_list(char *line)
{
	t_peaks *tmp;

	if (g_par->head_peak == NULL)
	{
		if (!(tmp = (t_peaks *)malloc(sizeof(t_peaks))))
			return (-1);
		if (!(tmp->line = ft_strdup(line)))
			return (-1);
		tmp->next = NULL;
		return (0);
	}
	else
	{
		if (!(tmp = (t_peaks *)malloc(sizeof(t_peaks))))
			return (-1);
		if (!(tmp->line = ft_strdup(line)))
			return (-1);
		tmp->next = (g_par->head_peak)->next;
		(g_par->head_peak)->next = tmp;
	}
	return (0);
}
