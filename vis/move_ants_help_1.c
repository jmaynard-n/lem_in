/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants_help_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:35:50 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/14 22:46:32 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_delete_from_middle(void)
{
	t_ants *tmp;

	tmp = g_par->head_ants;
	while (tmp)
	{
		if (ft_strcmp(tmp->to, "-"))
			if (ft_delete_ants() == -1)
				return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_delete_from_begin(void)
{
	t_peaks		*end;
	char		*end_name;

	ft_find_list_end(&end);
	if (ft_find_peak_name_1(end, &end_name) == -1)
		return (-1);
	if (ft_delete_ants() == -1)
		return (-1);
	ft_strdel(&end_name);
	return (0);
}

int		ft_find_list_end_true(t_peaks *head, t_peaks **end)
{
	t_peaks *tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp && tmp->next && (ft_heaven_or_hell((tmp->next)->line) == 2))
		{
			*end = tmp;
			return (0);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		ft_move_ants(void)
{
	void *param;

	param = NULL;
	mlx_mouse_hook(g_par->win, &mouse_hook, param);
	return (0);
}
