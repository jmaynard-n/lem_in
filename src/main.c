/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:08:59 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/18 10:35:25 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	ft_error(t_init *init, int *dis)
{
	ft_putstr("ERROR\n");
	if (dis)
		free(dis);
	ft_del_farm(&init);
	ft_graph_free(g_graph);
	exit(EXIT_FAILURE);
}

int		main(void)
{
	t_init	*init;
	int		ants;
	int		*dis;

	g_start = -1;
	g_end = -1;
	init = NULL;
	dis = NULL;
	if (!(ants = ft_init_farm(&init)))
		ft_error(init, dis);
	if (g_start == -1 || g_end == -1)
		ft_error(init, dis);
	if (g_graph->array[g_start] == NULL)
		ft_error(init, dis);
	ft_copy_rooms(init->rooms);
	if (!(ft_direct(&dis)))
		ft_error(init, dis);
	if (g_graph->array[g_start] == NULL)
		ft_error(init, dis);
	ft_printf("%d\n", ants);
	ft_print_farm(init);
	ft_move(dis, ants);
	ft_graph_free(g_graph);
	free(dis);
	return (0);
}
