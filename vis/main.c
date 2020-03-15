/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 21:57:18 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/18 11:08:08 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin_vis.h"

int		ft_soon_exit_fail(void)
{
	if (g_par)
		mlx_destroy_window(g_par->mlx, g_par->win);
	ft_free_peaks();
	ft_free_ants();
	ft_free_par();
	ft_putstr("ERROR\n");
	exit(EXIT_FAILURE);
	return (0);
}

int		ft_find_koord_four_stand_help(int x0, int y0, char **str0)
{
	char *str2;
	char *str1;

	if (!(*str0 = ft_itoa(x0)))
		return (-1);
	if (!(str1 = ft_strjoin(*str0, " ")))
		return (-1);
	ft_strdel(str0);
	if (!(*str0 = ft_itoa(y0)))
		return (-1);
	if (!(str2 = ft_strjoin(str1, *str0)))
		return (-1);
	ft_strdel(str0);
	ft_strdel(&str1);
	if (!(*str0 = ft_strjoin(str2, " ")))
		return (-1);
	ft_strdel(&str2);
	return (0);
}

char	*ft_find_koord_four_stand(int x0, int y0, int x1, int y1)
{
	char *str;
	char *str0;
	char *str1;
	char *str2;

	str0 = NULL;
	if (ft_find_koord_four_stand_help(x0, y0, &str0) == -1)
		return (NULL);
	if (!(str1 = ft_itoa(x1)))
		return (NULL);
	if (!(str2 = ft_strjoin(str0, str1)))
		return (NULL);
	ft_strdel(&str0);
	ft_strdel(&str1);
	if (!(str0 = ft_strjoin(str2, " ")))
		return (NULL);
	ft_strdel(&str2);
	if (!(str1 = ft_itoa(y1)))
		return (NULL);
	if (!(str = ft_strjoin(str0, str1)))
		return (NULL);
	ft_strdel(&str0);
	ft_strdel(&str1);
	return (str);
}

int		ft_init_par(void)
{
	int wid;
	int hey;

	if (!(g_par->muravey = mlx_xpm_file_to_image(g_par->mlx,
					"./vis/pic/muravey-3.xpm", &wid, &hey)))
		return (-1);
	if (!(g_par->obl_start = mlx_xpm_file_to_image(g_par->mlx,
					"./vis/pic/pic_start.xpm", &wid, &hey)))
		return (-1);
	if (!(g_par->obl_end = mlx_xpm_file_to_image(g_par->mlx,
					"./vis/pic/pic_end.xpm", &wid, &hey)))
		return (-1);
	if (!(g_par->obl_us = mlx_xpm_file_to_image(g_par->mlx,
					"./vis/pic/pic_us.xpm", &wid, &hey)))
		return (-1);
	g_par->head_peak = NULL;
	g_par->head_ants = NULL;
	return (0);
}

int		main(void)
{
	int wid;
	int hey;

	if (!(g_par = (t_draw *)malloc(sizeof(t_draw))))
		return (-1);
	ft_init_init();
	g_par->mlx = mlx_init();
	g_par->win = mlx_new_window(g_par->mlx, 1200, 800, "run, ant, run");
	if (!(g_par->raduga = mlx_xpm_file_to_image(g_par->mlx,
					"./vis/pic/raduga_nov.xpm", &wid, &hey)))
		ft_soon_exit();
	mlx_put_image_to_window(g_par->mlx, g_par->win, g_par->raduga, 0, 0);
	if (ft_init_par() == -1)
		ft_soon_exit();
	if (ft_find_peaks() == -1)
	{
		ft_soon_exit();
	}
	if (ft_run_ants() == -1)
	{
		ft_soon_exit();
	}
	mlx_loop(g_par->mlx);
}
