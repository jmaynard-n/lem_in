/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:30:08 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/14 23:38:31 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_init_struct_ants_help(t_ants **t, int *i)
{
	char *name;

	if (!(*t = (t_ants *)malloc(sizeof(t_ants))))
		return (-1);
	(*t)->next = NULL;
	(*t)->num = *i;
	ft_find_peak_name_1(g_par->head_peak, &name);
	if (!((*t)->from = ft_strdup(name)))
		return (-1);
	ft_strdel(&name);
	if (!((*t)->to = ft_strdup("-")))
		return (-1);
	(*t)->pos = 0;
	g_par->head_ants = *t;
	return (0);
}

int		ft_init_struct_ants_help_h(t_ants **t, int *i)
{
	char *name;

	if (!((*t)->next = (t_ants *)malloc(sizeof(t_ants))))
		return (-1);
	*t = (*t)->next;
	(*t)->next = NULL;
	(*t)->num = *i;
	ft_find_peak_name_1(g_par->head_peak, &name);
	if (!((*t)->from = ft_strdup(name)))
		return (-1);
	ft_strdel(&name);
	if (!((*t)->to = ft_strdup("-")))
		return (-1);
	(*t)->pos = 0;
	return (0);
}

int		ft_init_struct_ants(void)
{
	int		i;
	t_ants	*t;

	i = 1;
	while (i <= g_ants)
	{
		if (g_par->head_ants == NULL)
		{
			if (ft_init_struct_ants_help(&t, &i) == -1)
				return (-1);
		}
		else
		{
			if (ft_init_struct_ants_help_h(&t, &i) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

int		ft_analyse_line_out(char *line)
{
	int		i;
	int		j;
	char	*part;

	i = 0;
	while (line && line[i] != '\0')
	{
		if (!ft_strcmp(line, "\n"))
			return (-1);
		j = i;
		while (line && line[j] != '\0' && line[j] != ' ')
			j++;
		if (ft_cut_line(line, &part, i, j) == -1)
			return (-1);
		if (ft_analyse_part(g_par->head_ants, part) == -1)
			return (-1);
		ft_strdel(&part);
		if (j != (int)ft_strlen(line))
			i = j + 1;
		else
			i = j;
	}
	return (0);
}

int		ft_run_ants(void)
{
	void *param;

	if (g_ants > 0)
	{
		if (ft_init_struct_ants() == -1)
			return (-1);
		if (ft_move_ants() == -1)
			return (-1);
	}
	param = NULL;
	mlx_key_hook(g_par->win, &key_hook, param);
	return (0);
}
