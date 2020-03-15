/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:54:09 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/16 19:05:54 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_mouse_hook_h(int *ants, int *end)
{
	if (ft_delete_from_begin() == -1)
		return (-1);
	if (ft_print_ants_count(ants) == -1)
		return (-1);
	if (ft_put_to_middle() == -1)
		return (-1);
	if (ft_print_ants(*ants) == -1)
		return (-1);
	if (ft_print_ants_end(*end) == -1)
		return (-1);
	if (ft_print_ants_count_end(end) == -1)
		return (-1);
	return (0);
}

int		ft_mouse_hook_hh(int *ants, int *end)
{
	char *line;

	if (get_next_line(0, &line) > 0)
	{
		if (ft_analyse_line_out(line) == -1)
			return (-1);
		ft_strdel(&line);
	}
	if (ft_put_to_begin() == -1)
		return (-1);
	if (ft_print_ants(*ants) == -1)
		return (-1);
	if (ft_print_ants_end(*end) == -1)
		return (-1);
	if (ft_print_ants_count(ants) == -1)
		return (-1);
	return (0);
}

void	ft_useless(int *button, int *x, int *y, void **param)
{
	int f;

	if (*button)
	{
		f = *x;
		f = *y;
	}
	*param = NULL;
}

int		ft_mouse_hook_hhh(int *i, int *ants, int *end)
{
	if ((*i == 2) && (ft_delete_from_middle() == -1))
		return (-1);
	if ((*i == 6) || (*i == 2))
	{
		if (ft_refill_struct() == -1)
			return (-1);
		*i = 0;
	}
	if (ft_mouse_hook_hh(ants, end) == -1)
		return (-1);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *param)
{
	static int		i;
	static int		ants;
	static int		end;

	ft_useless(&button, &x, &y, &param);
	if ((i == 0) || (i == 2))
	{
		if (ft_mouse_hook_hhh(&i, &ants, &end) == -1)
			return (-1);
		if (ft_is_end_ants())
			return (0);
	}
	else if (i == 1)
	{
		if (ft_mouse_hook_h(&ants, &end) == -1)
			return (-1);
	}
	else if (i == 2)
	{
		if (ft_delete_from_middle() == -1)
			return (-1);
	}
	i++;
	return (0);
}
