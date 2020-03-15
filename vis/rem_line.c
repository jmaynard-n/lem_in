/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:28:15 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/18 11:10:18 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_put_start_help(t_peaks *tmp, char **start)
{
	t_peaks	*prev;

	prev = g_par->head_peak;
	while (prev && prev->next && ft_strcmp((prev->next)->line, "##start"))
		prev = prev->next;
	tmp = prev->next->next;
	if (!(*start = ft_strdup(tmp->line)))
		return (-1);
	ft_strdel(&(prev->next)->line);
	ft_strdel(&((prev->next)->next)->line);
	tmp = tmp->next;
	free((prev->next)->next);
	free(prev->next);
	prev->next = tmp;
	return (0);
}

int		ft_put_start(void)
{
	char	*start;
	t_peaks	*tmp;
	t_peaks	*start_peak;

	if (!(tmp = g_par->head_peak))
		return (-1);
	while (tmp && ft_strcmp(tmp->line, "##start"))
		tmp = tmp->next;
	if (tmp == g_par->head_peak)
	{
		g_par->head_peak = tmp->next;
		ft_strdel(&(tmp->line));
		free(tmp);
		return (0);
	}
	if (ft_put_start_help(tmp, &start) == -1)
		return (-1);
	if (!(start_peak = (t_peaks *)malloc(sizeof(t_peaks))))
		return (-1);
	if (!(start_peak->line = ft_strdup(start)))
		return (-1);
	ft_strdel(&start);
	start_peak->next = g_par->head_peak;
	g_par->head_peak = start_peak;
	return (0);
}

int		ft_rem_line_help(char *line)
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

int		ft_rem_line_help_h(char *line, t_peaks **tmp)
{
	*tmp = g_par->head_peak;
	while (*tmp && (*tmp)->next)
		*tmp = (*tmp)->next;
	if (!((*tmp)->next = (t_peaks *)malloc(sizeof(t_peaks))))
		return (-1);
	*tmp = (*tmp)->next;
	if (!((*tmp)->line = ft_strdup(line)))
		return (-1);
	(*tmp)->next = NULL;
	return (0);
}

int		ft_rem_line(char *line, t_peaks **head_con)
{
	t_peaks *tmp;

	if (!line)
		return (-1);
	if ((ft_strchr(line, '#')) && (ft_strcmp(line, "##start")
				&& ft_strcmp(line, "##end")))
		return (0);
	if (g_par->head_peak == NULL)
	{
		if (ft_rem_line_help(line) == -1)
			return (-1);
	}
	else
	{
		tmp = NULL;
		if (ft_rem_line_help_h(line, &tmp) == -1)
			return (-1);
		if ((ft_heaven_or_hell(line) == 2) && (*head_con == NULL))
			*head_con = tmp;
	}
	return (0);
}
