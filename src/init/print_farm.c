/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_farm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:59:38 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/15 15:32:35 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

void	ft_print_farm(t_init *init)
{
	t_room	*room;
	t_lis	*tmp_link;

	room = init->rooms;
	while (room)
	{
		if (ft_strchr(room->line, '#'))
			ft_printf("%s\n", room->line);
		else
			ft_printf("%s %d %d\n", room->line, room->x_coord, room->y_coord);
		room = room->next;
	}
	tmp_link = init->the_links;
	while (tmp_link)
	{
		ft_printf("%s\n", tmp_link->line);
		tmp_link = tmp_link->next;
	}
	ft_printf("\n");
	ft_del_farm(&init);
}

void	ft_print_instr(int ant, int room)
{
	t_room *tmp;

	tmp = g_graph->rooms;
	if (!tmp)
		return ;
	while (tmp)
	{
		if (tmp->index == room)
			break ;
		tmp = tmp->next;
	}
	if (ft_strchr(tmp->line, '#'))
		tmp = tmp->next;
	ft_printf("L%d-%s ", ant, tmp->line);
}
