/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_koord_help_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:56:12 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/18 10:26:21 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_find_max_y(t_peaks *head, t_peaks *head_con)
{
	t_peaks	*tmp;
	int		max;
	int		y;

	tmp = head;
	while (tmp != head_con)
	{
		y = ft_find_y_koord(tmp->line);
		if (tmp == head)
			max = y;
		else if (y > max)
			max = y;
		tmp = tmp->next;
	}
	return (max);
}

int		ft_find_peak_name(char *line, char **p)
{
	int len;
	int i;

	len = 0;
	while (line && line[len] != ' ')
		len++;
	if (!(*p = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	i = 0;
	while (i < len)
	{
		(*p)[i] = line[i];
		i++;
	}
	(*p)[i] = '\0';
	return (0);
}

int		ft_write_line(char **line, char *p, int x, int y)
{
	char *str1;
	char *str2;
	char *linex;

	if (!(str1 = ft_strjoin(p, " ")))
		return (-1);
	if (!(linex = ft_itoa(x)))
		return (-1);
	if (!(str2 = ft_strjoin(str1, linex)))
		return (-1);
	ft_strdel(&str1);
	ft_strdel(&linex);
	if (!(str1 = ft_strjoin(str2, " ")))
		return (-1);
	ft_strdel(&str2);
	if (!(linex = ft_itoa(y)))
		return (-1);
	if (!(str2 = ft_strjoin(str1, linex)))
		return (-1);
	ft_strdel(&str1);
	ft_strdel(&linex);
	if (!(*line = ft_strdup(str2)))
		return (-1);
	ft_strdel(&str2);
	return (0);
}

int		ft_minus_xy_koord(char **line, int minx, int miny)
{
	char	*p;
	int		x;
	int		y;

	p = NULL;
	if (ft_find_peak_name(*line, &p) == -1)
		return (-1);
	x = ft_find_x_koord(*line);
	y = ft_find_y_koord(*line);
	if (minx > 0)
		x -= minx;
	else
		x += -minx;
	if (miny > 0)
		y -= miny;
	else
		y += -miny;
	ft_strdel(line);
	if (ft_write_line(line, p, x, y) == -1)
		return (-1);
	ft_strdel(&p);
	return (0);
}

int		ft_plus_xy_koord_h(char **line, int minx, int miny)
{
	char	*p;
	int		x;
	int		y;

	if (ft_find_peak_name(*line, &p) == -1)
		return (-1);
	x = ft_find_x_koord(*line);
	y = ft_find_y_koord(*line);
	x += minx;
	y += miny;
	ft_strdel(line);
	if (ft_write_line(line, p, x, y) == -1)
		return (-1);
	ft_strdel(&p);
	return (0);
}
