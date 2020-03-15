/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_peaks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:56:53 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/18 11:09:53 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_draw_lines_help(t_peaks **tmp_p1, t_peaks **tmp_p2,
			t_peaks **tmp_con, t_peaks **tmp)
{
	int f;

	f = ft_is_that_peak_1(*tmp_con, *tmp);
	if (f == -1)
		return (-1);
	if (f)
		*tmp_p1 = *tmp;
	f = ft_is_that_peak_2(*tmp_con, *tmp);
	if (f == -1)
		return (-1);
	if (f)
		*tmp_p2 = *tmp;
	*tmp = (*tmp)->next;
	return (0);
}

int		ft_draw_lines(t_peaks *head_con)
{
	t_peaks	*tmp_p1;
	t_peaks	*tmp_p2;
	t_peaks	*tmp;
	t_peaks	*tmp_con;

	tmp_con = head_con;
	while (tmp_con)
	{
		tmp = g_par->head_peak;
		tmp_p1 = NULL;
		tmp_p2 = NULL;
		while (tmp && (tmp_p1 == NULL || tmp_p2 == NULL))
			ft_draw_lines_help(&tmp_p1, &tmp_p2, &tmp_con, &tmp);
		if (ft_connect_peaks(tmp_p1, tmp_p2) == -1)
			return (-1);
		tmp_con = tmp_con->next;
	}
	ft_draw_obl();
	return (0);
}

int		ft_find_peaks_help(char *line, t_peaks **head_con, int *i)
{
	if (!ft_strcmp(line, "ERROR"))
	{
		ft_strdel(&line);
		ft_soon_exit();
	}
	if (!ft_strcmp(line, ""))
	{
		ft_strdel(&line);
		return (1);
	}
	if (*i == 0)
		g_ants = ft_atoi(line);
	if (*i != 0)
	{
		if (ft_rem_line(line, head_con) == -1)
			return (-1);
	}
	ft_strdel(&line);
	(*i)++;
	return (0);
}

int		ft_draw_obl(void)
{
	t_peaks *tmp;

	tmp = g_par->head_peak;
	while (tmp && (ft_heaven_or_hell(tmp->line) == 1))
	{
		ft_put_oblako(tmp);
		if (ft_put_name(tmp) == -1)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_find_peaks(void)
{
	int		i;
	char	*line;
	t_peaks	*head_con;
	int		ret;

	i = 0;
	head_con = NULL;
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ft_find_peaks_help(line, &head_con, &i) == 1)
			break ;
	}
	if (ret == -1)
		ft_soon_exit();
	if (ft_put_start() == -1)
		return (-1);
	if (ft_put_end() == -1)
		return (-1);
	if (ft_change_koord_peaks(head_con) == -1)
		return (-1);
	if (ft_draw_lines(head_con) == -1)
		return (-1);
	return (0);
}
