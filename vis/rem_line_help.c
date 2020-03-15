/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_line_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:35:02 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/16 16:56:55 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_put_end_help(char **end, t_peaks **tmp)
{
	if (!(*end = ft_strdup(((*tmp)->next)->line)))
		return (-1);
	g_par->head_peak = ((*tmp)->next)->next;
	ft_strdel(&((*tmp)->line));
	ft_strdel(&(((*tmp)->next)->line));
	free((*tmp)->next);
	free(*tmp);
	return (0);
}

int		ft_put_end_help_h(t_peaks **prev, char **end, t_peaks **tmp)
{
	*prev = g_par->head_peak;
	while (*prev && (*prev)->next && ft_strcmp(((*prev)->next)->line, "##end"))
		*prev = (*prev)->next;
	*tmp = (((*prev)->next)->next)->next;
	if (!(*end = ft_strdup((((*prev)->next)->next)->line)))
		return (-1);
	ft_strdel(&(((*prev)->next)->line));
	ft_strdel(&((((*prev)->next)->next)->line));
	free(((*prev)->next)->next);
	free((*prev)->next);
	(*prev)->next = *tmp;
	return (0);
}

int		ft_put_end_help_hh(t_peaks **tmp, char **end, t_peaks **prev)
{
	ft_find_list_end_true(g_par->head_peak, prev);
	if (!(*tmp = (t_peaks *)malloc(sizeof(t_peaks))))
		return (-1);
	if (!((*tmp)->line = ft_strdup(*end)))
		return (-1);
	ft_strdel(end);
	(*tmp)->next = (*prev)->next;
	(*prev)->next = *tmp;
	return (0);
}

int		ft_put_end(void)
{
	char	*end;
	t_peaks	*tmp;
	t_peaks	*prev;

	end = NULL;
	prev = NULL;
	tmp = g_par->head_peak;
	while (tmp && ft_strcmp(tmp->line, "##end"))
		tmp = tmp->next;
	if (tmp == g_par->head_peak)
	{
		if (ft_put_end_help(&end, &tmp) == -1)
			return (-1);
	}
	else
	{
		if (ft_put_end_help_h(&prev, &end, &tmp) == -1)
			return (-1);
	}
	if (ft_put_end_help_hh(&tmp, &end, &prev) == -1)
		return (-1);
	return (0);
}
