/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:13:42 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/14 16:27:50 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

t_graph		*ft_graph_create(unsigned int size)
{
	t_graph *ht;

	if (size < 1)
		return (NULL);
	if (!(ht = malloc(sizeof(t_graph))))
		return (NULL);
	ht->array = (t_vert **)malloc(size * sizeof(t_vert));
	if (!(ht->array))
		return (NULL);
	ft_memset(ht->array, 0, size * sizeof(t_vert));
	ht->rooms = NULL;
	ht->size = size;
	return (ht);
}
