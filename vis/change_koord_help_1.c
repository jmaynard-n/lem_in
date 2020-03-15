/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_koord_help_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:55:58 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/14 20:59:45 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_find_x_koord(char *line)
{
	int x;

	while (line && *line != ' ')
		line++;
	x = ft_atoi(line);
	return (x);
}

int		ft_find_y_koord(char *line)
{
	int y;

	while (line && *line != ' ')
		line++;
	line++;
	while (line && *line != ' ')
		line++;
	y = ft_atoi(line);
	return (y);
}

int		ft_find_min_x(t_peaks *head, t_peaks *head_con)
{
	t_peaks		*tmp;
	int			min;
	int			x;

	tmp = head;
	while (tmp != head_con)
	{
		x = ft_find_x_koord(tmp->line);
		if (tmp == head)
			min = x;
		else if (x < min)
			min = x;
		tmp = tmp->next;
	}
	return (min);
}

int		ft_find_min_y(t_peaks *head, t_peaks *head_con)
{
	t_peaks	*tmp;
	int		min;
	int		y;

	tmp = head;
	while (tmp != head_con)
	{
		y = ft_find_y_koord(tmp->line);
		if (tmp == head)
			min = y;
		else if (y < min)
			min = y;
		tmp = tmp->next;
	}
	return (min);
}

int		ft_find_max_x(t_peaks *head, t_peaks *head_con)
{
	t_peaks	*tmp;
	int		max;
	int		x;

	tmp = head;
	while (tmp != head_con)
	{
		x = ft_find_x_koord(tmp->line);
		if (tmp == head)
			max = x;
		else if (x > max)
			max = x;
		tmp = tmp->next;
	}
	return (max);
}
