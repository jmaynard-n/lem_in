/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:57:30 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/18 12:24:39 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

static int		ft_help_add_room(t_init *init, t_room *tmp, t_room **s)
{
	t_room *t;

	t = init->rooms;
	while (t)
	{
		if (ft_strcmp(t->line, tmp->line) == 0 && !ft_strchr(tmp->line, '#'))
			return (0);
		else if (!ft_strchr(tmp->line, '#') &&
			t->x_coord == tmp->x_coord && t->y_coord == tmp->y_coord)
			return (0);
		t = t->next;
	}
	*s = init->rooms;
	while ((*s) && (*s)->next)
		*s = (*s)->next;
	if (!((*s)->next) &&
		(!ft_strcmp(tmp->line, "##start") || !ft_strcmp(tmp->line, "##end")) &&
		(!ft_strcmp((*s)->line, "##start") || !ft_strcmp((*s)->line, "##end")))
		return (0);
	return (1);
}

static int		ft_cont_add(t_init *init, char *line, t_room *tmp)
{
	t_room *s;

	s = NULL;
	if (!(ft_help_add_room(init, tmp, &s)))
	{
		free(tmp->line);
		free(tmp);
		return (0);
	}
	else if (!ft_strchr(line, '#') &&
		s->x_coord == tmp->x_coord && s->y_coord == tmp->y_coord)
	{
		free(tmp->line);
		free(tmp);
		return (0);
	}
	s->next = tmp;
	return (1);
}

static int		ft_add_to_room_list(t_init *init, char *line, int index)
{
	t_room		*tmp;
	t_room		*s;

	s = NULL;
	if (!(tmp = ft_add_roomlst(line, index)))
		return (0);
	if (!(init->rooms))
	{
		init->rooms = tmp;
		return (1);
	}
	if (!(ft_cont_add(init, line, tmp)))
		return (0);
	return (1);
}

static void		ft_find_place(t_init *init, char *line, t_tree **time)
{
	t_tree *s;

	s = init->the_rooms;
	while (s)
	{
		*time = s;
		if (ft_strcmp(s->line, line) < 0)
			s = s->left;
		else
			s = s->right;
	}
}

int				ft_add_room(t_init *init, char *line)
{
	t_tree *tmp;
	t_tree *time;

	time = NULL;
	if (!(init->the_rooms))
	{
		if (!(tmp = ft_add_to_tree(line)))
			return (-1);
		init->the_rooms = tmp;
		if (!(ft_add_to_room_list(init, line, tmp->index)))
			return (-1);
		return (1);
	}
	if (!(tmp = ft_add_to_tree(line)))
		return (-1);
	ft_find_place(init, line, &time);
	if (ft_strcmp(time->line, line) < 0)
		time->left = tmp;
	else
		time->right = tmp;
	if (!(ft_add_to_room_list(init, line, tmp->index)))
		return (-1);
	return (tmp->index + 1);
}
