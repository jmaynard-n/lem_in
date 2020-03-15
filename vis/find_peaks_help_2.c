/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_peaks_help_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 21:47:49 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/18 10:03:32 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_is_that_peak_1(t_peaks *con, t_peaks *tmp)
{
	char *p1;
	char *p2;

	p1 = NULL;
	p2 = NULL;
	if (ft_find_first_peak_in_con(&p1, con->line) == -1)
		return (-1);
	if (ft_find_peak_in_koord(&p2, tmp->line) == -1)
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

int		ft_is_that_peak_2(t_peaks *con, t_peaks *tmp)
{
	char *p1;
	char *p2;

	p1 = NULL;
	p2 = NULL;
	if (ft_find_sec_peak_in_con(&p1, con->line) == -1)
		return (-1);
	if (ft_find_peak_in_koord(&p2, tmp->line) == -1)
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

int		ft_cut_peak_name(char **koord, char *p)
{
	int i;
	int j;
	int len;

	i = 0;
	while (p && p[i] != ' ')
		i++;
	i++;
	len = ft_strlen(p) - i;
	if (!(*koord = (char *)malloc(sizeof(char) * (len + 1))))
		return (-1);
	j = 0;
	while (p && p[i] != '\0')
	{
		(*koord)[j] = p[i];
		j++;
		i++;
	}
	(*koord)[j] = '\0';
	return (0);
}

int		ft_connect_peaks(t_peaks *p1, t_peaks *p2)
{
	char *koord1;
	char *koord2;
	char *str;
	char *str1;

	if (ft_cut_peak_name(&koord1, p1->line) == -1)
		return (-1);
	if (ft_cut_peak_name(&koord2, p2->line) == -1)
		return (-1);
	if (!(str1 = ft_strjoin(koord1, " ")))
		return (-1);
	ft_strdel(&koord1);
	if (!(str = ft_strjoin(str1, koord2)))
		return (-1);
	ft_strdel(&str1);
	ft_strdel(&koord2);
	ft_create_line(str, 0x000000);
	ft_put_oblako(p1);
	ft_put_oblako(p2);
	ft_strdel(&str);
	if (ft_put_name(p1) == -1)
		return (-1);
	if (ft_put_name(p2) == -1)
		return (-1);
	return (0);
}

int		ft_soon_exit(void)
{
	if (g_par)
		mlx_destroy_window(g_par->mlx, g_par->win);
	ft_free_peaks();
	ft_free_par();
	ft_free_ants();
	ft_putstr("ERROR\n");
	exit(EXIT_FAILURE);
	return (0);
}
