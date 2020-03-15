/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:16:18 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/16 18:58:39 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include "../../libft/includes/libft.h"

typedef	struct	s_room
{
	char			*line;
	int				x_coord;
	int				y_coord;
	int				index;
	struct s_room	*next;
}				t_room;

typedef struct	s_vert
{
	int				vert;
	struct s_vert	*next;
}				t_vert;

typedef struct	s_graph
{
	unsigned int	size;
	t_room			*rooms;
	t_vert			**array;
}				t_graph;

t_graph			*g_graph;

/*
** create.c
*/
t_graph			*ft_graph_create(unsigned int size);

/*
**	insert.c
*/
int				ft_add_to_graph(t_graph *graph, const int dst, const int src);
void			print_graph(void);

/*
**	del.c
*/
int				ft_del_link(const int where, const int what, t_graph *graph);

/*
**	free.c
*/
void			ft_graph_free(t_graph *graph);

/*
** direct.c
*/
int				ft_direct(int **dis);

/*
** sort.c
*/
void			ft_sort(int *dis);
int				ft_list_len(t_vert *tmp);

/*
** queve.c
*/
int				ft_enqueve(t_vert **q);
int				ft_queve_smart(t_vert **q, int *dis, int vert);
int				ft_queve(t_vert **q, int vert);

/*
** distance.c
*/
int				ft_distance(t_graph *graph, int **dis);

/*
** clean_graph.c
*/
void			ft_clean_graph(int end);

#endif
