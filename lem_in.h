/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:04:01 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/18 11:02:22 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "./libft/includes/libft.h"
# include "./src/graph/graph.h"

int				g_start;
int				g_end;

typedef	struct	s_lis
{
	char			*line;
	struct s_lis	*next;
}				t_lis;

typedef	struct	s_tree
{
	char			*line;
	int				index;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

typedef struct	s_init
{
	t_tree	*the_rooms;
	t_room	*rooms;
	t_lis	*the_links;
}				t_init;

/*
** validation.c
*/
int				ft_valid_rooms(char *line);
t_room			*ft_add_roomlst(char *line, int index);

/*
** valid_links.c
*/
t_tree			*ft_add_to_tree(char *line);
int				ft_valid_links(t_init *init, char *line);
int				ft_add_link(t_init *init, char *line);

/*
** valid_ants.c
*/
int				ft_valid_ants(char *line);

/*
** tree and lis.c
*/
int				ft_add_room(t_init *init, char *line);

/*
** print_farm.c
*/
void			ft_print_farm(t_init *init);
void			ft_print_instr(int ant, int room);

/*
** init.c
*/
int				ft_init_farm(t_init **init);

/*
** copy_rooms.c
*/
int				ft_copy_rooms(t_room *rooms);

/*
** del_farm.c
*/
void			ft_del_farm(t_init **init);

/*
** move.c
*/
void			ft_set(int **arr, size_t size);
void			ft_move(int *dis, int ants);
void			ft_set_1(int **arr, size_t size);

/*
** move_from_start.c
*/
void			ft_move_from_start(int *aval, int *dis,
					t_vert **mv_ants, t_vert **prev_vert);

/*
** move_to_end.c
*/
void			ft_move_to_end(int *aval, t_vert **mv_ants, int *dis, int ants);
int				ft_find_vert(int *dis, int *aval,
					t_vert *mv_ants, t_vert *prev_vert);
int				ft_turn(unsigned int ant, t_vert *mv);

/*
** move_to_next.c
*/
int				ft_move_to_next(int *aval, int vert,
					int peak, t_vert **mv_ants);
int				ft_add_to_queve(t_vert **queve, int vert);
void			ft_free_mv(t_vert **mv);
int				ft_moving(int *aval, int vert, int peak, t_vert **mv_ants);
int				ft_try_way(int *aval, int vert, t_vert **mv_ants);

/*
** main.c
*/
void			ft_error(t_init *init, int *dis);

/*
** path.c
*/
int				ft_path(int **dis, t_graph *gr);

/*
** sence.c
*/
int				ft_sense(int ants, int *dis, int turn);
int				ft_get_turn(int ants, int *dis);

#endif
