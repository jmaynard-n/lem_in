/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_links.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:45:03 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/16 20:11:45 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

t_tree			*ft_add_to_tree(char *line)
{
	t_tree		*tmp;
	static int	ind;

	if (!(tmp = (t_tree *)malloc(sizeof(t_tree))))
		return (NULL);
	if (!(tmp->line = ft_strdup(line)))
		return (NULL);
	tmp->index = ind;
	tmp->left = NULL;
	tmp->right = NULL;
	if (!ft_strstr(line, "#"))
		ind++;
	return (tmp);
}

static t_lis	*ft_add_to_list(char *line)
{
	t_lis *tmp;

	if (!(tmp = (t_lis *)malloc(sizeof(t_lis))))
		return (NULL);
	if (!(tmp->line = ft_strdup(line)))
		return (NULL);
	tmp->next = NULL;
	return (tmp);
}

int				ft_add_link(t_init *init, char *line)
{
	t_lis *tmp;
	t_lis *s;

	if (!(init->the_links))
	{
		if (!(tmp = ft_add_to_list(line)))
			return (0);
		init->the_links = tmp;
		return (1);
	}
	s = init->the_links;
	while (s->next)
		s = s->next;
	if (!(tmp = ft_add_to_list(line)))
		return (0);
	s->next = tmp;
	return (1);
}

static int		ft_find_node(t_tree *rooms, char *line, int *ind)
{
	t_tree *tmp;

	tmp = rooms;
	if (tmp && *ind == -1)
	{
		if ((ft_strcmp(tmp->line, line) == 32) && *ind == -1)
		{
			*ind = tmp->index;
			return (0);
		}
		else if (*ind == -1)
		{
			ft_find_node(tmp->left, line, ind);
			ft_find_node(tmp->right, line, ind);
		}
	}
	return (-1);
}

int				ft_valid_links(t_init *init, char *line)
{
	int		ind1;
	int		ind2;
	char	*str;
	char	*tmp;

	ind1 = -1;
	ind2 = -1;
	if (ft_strstr(line, "#"))
		return (1);
	str = ft_strstr(line, "-") + 1;
	tmp = ft_strsub(line, 0, str - line - 1);
	ft_find_node(init->the_rooms, str, &ind1);
	ft_find_node(init->the_rooms, tmp, &ind2);
	if (ind1 == -1 || ind2 == -1)
		return (ft_strdel(&tmp));
	else
	{
		ft_add_to_graph(g_graph, ind1, ind2);
		ft_add_to_graph(g_graph, ind2, ind1);
	}
	ft_strdel(&tmp);
	return (1);
}
