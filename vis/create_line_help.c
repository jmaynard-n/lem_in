/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_line_help.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:05:58 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/14 21:28:30 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

void	ft_find_t0_first(char *str, int *x, int *y)
{
	if (!str)
		return ;
	*x = ft_atoi(str);
	while (str && *str != '\0' && *str != ' ')
		str++;
	str++;
	*y = ft_atoi(str);
}

void	ft_find_t0_sec(char *str, int *x, int *y)
{
	int flag;

	if (!str)
		return ;
	flag = 0;
	while (flag != 2 && str && *str != '\0')
	{
		if (*str == ' ')
			flag++;
		str++;
	}
	*x = ft_atoi(str);
	while (str && *str != '\0' && *str != ' ')
		str++;
	str++;
	*y = ft_atoi(str);
}

int		ft_abs(int a, int b)
{
	if (a - b > 0)
		return (a - b);
	else
		return (b - a);
}

int		ft_find_t0(char *t, int *x, int *y)
{
	if (!t)
		return (-1);
	*x = ft_atoi(t);
	while (t && *t != '\0' && *t != ' ')
	{
		t++;
	}
	t++;
	*y = ft_atoi(t);
	return (0);
}

int		ft_create_line_var(char *str, int col)
{
	int x0;
	int x1;
	int y0;
	int y1;

	ft_find_t0_first(str, &x0, &y0);
	ft_find_t0_sec(str, &x1, &y1);
	if (ft_abs(x1, x0) >= ft_abs(y1, y0))
		ft_create_line_norm(str, col);
	else
		ft_create_line_rev(str, col);
	return (0);
}
