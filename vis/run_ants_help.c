/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 23:30:52 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/16 18:08:38 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_cut_line(char *line, char **part, int start, int end)
{
	int i;
	int j;

	if (!(*part = (char *)malloc(sizeof(char) * (end - start + 1))))
		return (-1);
	i = start;
	j = 0;
	while (i < end)
	{
		(*part)[j] = line[i];
		i++;
		j++;
	}
	(*part)[j] = '\0';
	return (0);
}

int		ft_find_num(char *part)
{
	int num;

	num = ft_atoi(part + 1);
	return (num);
}

int		ft_find_name_to(char **name, char *part)
{
	int i;
	int j;

	i = 0;
	while (part && part[i] != '-')
		i++;
	i++;
	if (!(*name = (char *)malloc(sizeof(char) * (ft_strlen(part) - i + 1))))
		return (-1);
	j = 0;
	while (part && part[i] != '\0')
	{
		(*name)[j] = part[i];
		i++;
		j++;
	}
	(*name)[j] = '\0';
	return (0);
}

int		ft_analyse_part(t_ants *head, char *part)
{
	int		num;
	char	*name;
	t_ants	*tmp;

	num = ft_find_num(part);
	if (ft_find_name_to(&name, part) == -1)
		return (-1);
	tmp = head;
	while (tmp && tmp->num != num)
		tmp = tmp->next;
	ft_strdel(&(tmp->to));
	if (!(tmp->to = ft_strdup(name)))
		return (-1);
	ft_strdel(&name);
	return (0);
}
