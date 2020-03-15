/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_peaks_help_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:47:31 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/15 15:21:43 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_find_first_peak_in_con(char **p1, char *line)
{
	int i;
	int len;

	len = 0;
	while (line && line[len] != '-')
		len++;
	if (!(*p1 = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	i = 0;
	while (i < len)
	{
		(*p1)[i] = line[i];
		i++;
	}
	(*p1)[i] = '\0';
	return (0);
}

int		ft_find_sec_peak_in_con(char **p1, char *line)
{
	int i;
	int len;
	int start;

	len = 0;
	i = 0;
	while (line && line[i] != '-')
		i++;
	start = i + 1;
	len = ft_strlen(line);
	if (!(*p1 = (char *)malloc(sizeof(char) * (i + 1))))
		return (-1);
	i = 0;
	while (start < len)
	{
		(*p1)[i] = line[start];
		i++;
		start++;
	}
	(*p1)[i] = '\0';
	return (0);
}

int		ft_heaven_or_hell(char *line)
{
	int space;
	int i;

	i = 0;
	space = 0;
	if (ft_strchr(line, '#'))
		return (1);
	while (line && line[i] != '\0')
	{
		if (line[i] == ' ')
			space++;
		i++;
	}
	if (space != 0)
		return (1);
	else
		return (2);
}

int		ft_same_peaks(char *line)
{
	char *p1;
	char *p2;

	if (ft_heaven_or_hell(line) == 1)
		return (0);
	if (ft_find_first_peak_in_con(&p1, line) == -1)
		return (-1);
	if (ft_find_sec_peak_in_con(&p2, line) == -1)
		return (-1);
	if (!ft_strcmp(p1, p2))
	{
		ft_strdel(&p1);
		ft_strdel(&p2);
		return (1);
	}
	ft_strdel(&p1);
	ft_strdel(&p2);
	return (0);
}

int		ft_find_peak_in_koord(char **p1, char *line)
{
	int i;
	int len;

	len = 0;
	while (line && line[len] != ' ')
		len++;
	if (!(*p1 = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	i = 0;
	while (i < len)
	{
		(*p1)[i] = line[i];
		i++;
	}
	(*p1)[i] = '\0';
	return (0);
}
