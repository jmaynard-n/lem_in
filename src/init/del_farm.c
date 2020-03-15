/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_farm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:51:15 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/16 18:50:32 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

static void	ft_del_lis(t_init **init)
{
	t_lis *l;
	t_lis *tmp;

	tmp = (*init)->the_links;
	while (tmp)
	{
		l = tmp->next;
		free(tmp->line);
		free(tmp);
		tmp = l;
	}
	(*init)->the_links = NULL;
}

static void	ft_del_tree(t_tree *r)
{
	if (!r)
		return ;
	ft_del_tree(r->left);
	ft_del_tree(r->right);
	free(r->line);
	free(r);
	r = NULL;
}

static void	ft_del_rooms(t_init **init)
{
	t_room *tmp;
	t_room *r;

	r = (*init)->rooms;
	while (r)
	{
		tmp = r->next;
		free(r->line);
		free(r);
		r = tmp;
	}
	(*init)->rooms = NULL;
}

void		ft_del_farm(t_init **init)
{
	if (!init || !(*init))
		return ;
	ft_del_lis(init);
	ft_del_tree((*init)->the_rooms);
	ft_del_rooms(init);
	(*init)->the_rooms = NULL;
	free(*init);
	*init = NULL;
}
