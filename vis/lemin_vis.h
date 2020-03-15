/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_vis.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: volyvar- <volyvar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 22:00:16 by volyvar-          #+#    #+#             */
/*   Updated: 2019/09/18 10:57:50 by volyvar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_VIS_H
# define LEMIN_VIS_H
# ifndef LIBFT_LIBFT_H
#  define LIBFT_LIBFT_H
#  include "../libft/includes/libft.h"
# endif
# include "mlx.h"

typedef struct		s_peaks
{
	char			*line;
	struct s_peaks	*next;
}					t_peaks;

typedef struct		s_ants
{
	int				num;
	char			*from;
	char			*to;
	int				pos;
	struct s_ants	*next;
}					t_ants;

typedef struct		s_draw
{
	void			*mlx;
	void			*win;
	void			*raduga;
	void			*muravey;
	void			*obl_start;
	void			*obl_end;
	void			*obl_us;
	t_peaks			*head_peak;
	t_ants			*head_ants;
	struct s_draw	*next;
}					t_draw;

t_draw				*g_par;
int					g_ants;

/*
** ants_count.c
*/

int					ft_print_ants(int ants);
int					ft_print_ants_count(int *ants);
int					ft_print_ants_end(int ants);
int					ft_print_ants_count_end(int *ants);
int					ft_is_end_ants(void);

/*
** change_koord_help_1.c
*/

int					ft_find_x_koord(char *line);
int					ft_find_y_koord(char *line);
int					ft_find_min_x(t_peaks *head, t_peaks *head_con);
int					ft_find_min_y(t_peaks *head, t_peaks *head_con);
int					ft_find_max_x(t_peaks *head, t_peaks *head_con);

/*
** change_koord_help_2.c
*/

int					ft_find_max_y(t_peaks *head, t_peaks *head_con);
int					ft_find_peak_name(char *line, char **p);
int					ft_write_line(char **line, char *p, int x, int y);
int					ft_minus_xy_koord(char **line, int minx, int miny);
int					ft_plus_xy_koord_h(char **line, int minx, int miny);

/*
** change_koord_help_3.c
*/

int					ft_change_xy_koord(t_peaks *head, t_peaks *head_con,
							int minx, int miny);
int					ft_plus_xy_koord(t_peaks *head, t_peaks *head_con,
										int minx, int miny);
int					ft_move_to_begin(t_peaks *head_con);
int					ft_mult_koord(char **line, float delx, float dely);
int					ft_multiply_koord(t_peaks *head, t_peaks *head_con,
							float delx, float dely);

/*
** change_koord.c
*/

int					ft_stretch_graph(t_peaks *head_con);
int					ft_move_from_begin(t_peaks *head_con);
int					ft_change_koord_peaks(t_peaks *head_con);
void				ft_init_init(void);

/*
** create_line_help.c
*/

void				ft_find_t0_first(char *str, int *x, int *y);
void				ft_find_t0_sec(char *str, int *x, int *y);
int					ft_abs(int a, int b);
int					ft_find_t0(char *t, int *x, int *y);
int					ft_create_line_var(char *str, int col);

/*
** create_line.c
*/

int					ft_create_line_norm_help(char *str, int col, int x, int y);
int					ft_create_line_norm(char *str, int col);
int					ft_create_line_rev_help(char *str, int col, int x, int y);
int					ft_create_line_rev(char *str, int col);
int					ft_create_line(char *str, int col);

/*
** destroy_ant.c
*/

int					ft_find_con(t_peaks **con);
int					ft_find_peak_name_help(char **end_name);
int					ft_find_peak_name_help_h(t_peaks **t,
									char **name, t_ants *tmp);
int					ft_put_certain_ants(int x, int y);
int					ft_delete_ants(void);

/*
** find_peaks_help_1.c
*/

int					ft_find_first_peak_in_con(char **p1, char *line);
int					ft_find_sec_peak_in_con(char **p1, char *line);
int					ft_heaven_or_hell(char *line);
int					ft_same_peaks(char *line);
int					ft_find_peak_in_koord(char **p1, char *line);
int					ft_draw_obl();

/*
** find_peaks_help_2.c
*/

int					ft_is_that_peak_1(t_peaks *con, t_peaks *tmp);
int					ft_is_that_peak_2(t_peaks *con, t_peaks *tmp);
int					ft_cut_peak_name(char **koord, char *p);
int					ft_connect_peaks(t_peaks *p1, t_peaks *p2);
int					ft_soon_exit(void);

/*
** find_peaks.c
*/

int					ft_draw_lines_help(t_peaks **tmp_p1, t_peaks **tmp_p2,
						t_peaks **tmp_con, t_peaks **tmp);
int					ft_draw_lines(t_peaks *head_con);
int					ft_find_peaks_help(char *line, t_peaks **head_con, int *i);
int					ft_find_peaks(void);

/*
** free_struct.c
*/

void				ft_free_peaks(void);
void				ft_free_ants(void);
void				ft_free_par(void);

/*
** help.c
*/

int					ft_find_obl_koord_help(int *x, int *y);
int					ft_change_yx(int y1, int y0);
int					key_hook(int keycode, void *param);

/*
** main.c
*/

int					ft_find_koord_four_stand_help(int x0, int y0, char **str0);
char				*ft_find_koord_four_stand(int x0, int y0, int x1, int y1);
int					ft_init_par(void);

/*
** move_ants_help_1.c
*/

int					ft_delete_from_middle(void);
int					ft_delete_from_begin(void);
int					ft_find_list_end_true(t_peaks *head, t_peaks **end);
int					ft_move_ants(void);

/*
** refill_struct.c
*/

int					ft_refill_struct_help(t_ants **tmp);
int					ft_refill_struct_help_h(t_ants **tmp, char *end_name);
int					ft_refill_struct_help_hh(t_ants **tmp);
int					ft_refill_struct(void);

/*
** mouse_hook.c
*/

int					ft_mouse_hook_h(int *ants, int *end);
int					ft_mouse_hook_hh(int *ants, int *end);
void				ft_useless(int *button, int *x, int *y, void **param);
int					ft_mouse_hook_hhh(int *i, int *ants, int *end);
int					mouse_hook(int button, int x, int y, void *param);

/*
** move_ants.c
*/

int					ft_put_to_begin_help(t_ants **tmp);
int					ft_put_to_begin(void);
int					ft_put_to_middle_help(t_ants **tmp, int *x, int *y);
int					ft_put_to_middle_help_h(t_ants **tmp, int *x1, int *y1);
int					ft_put_to_middle(void);

/*
** put_name.c
*/

int					ft_find_koord_obl_name(t_peaks *p1, int *x, int *y);
int					ft_find_peak_name_1(t_peaks *p, char **name);
int					ft_put_name(t_peaks *p1);

/*
** put_oblako.c
*/

int					ft_is_begin(t_peaks *p);
int					ft_is_end(t_peaks *p);
int					ft_find_koord_obl(t_peaks *p1, int *x, int *y);
int					ft_put_oblako(t_peaks *p1);

/*
** run_ant_help.c
*/

int					ft_cut_line(char *line, char **part, int start, int end);
int					ft_find_num(char *part);
int					ft_find_name_to(char **name, char *part);
int					ft_analyse_part(t_ants *head, char *part);

/*
** run_ants.c
*/

int					ft_init_struct_ants_help(t_ants **t, int *i);
int					ft_init_struct_ants_help_h(t_ants **t, int *i);
int					ft_init_struct_ants(void);
int					ft_analyse_line_out(char *line);
int					ft_run_ants(void);

/*
** work_with_list_help.c
*/

int					ft_put_to_begin_list(char *line);
int					ft_put_to_end_list(char *line);

/*
** work_with_list.c
*/

void				ft_find_list_end(t_peaks **tmp_p);
int					ft_put_before_last_list_help(char *line);
int					ft_put_before_last_list_help_h(char *line);
int					ft_put_before_last_list(char *line);
int					ft_put_after_first_list(char *line);

/*
** rem_line.c
*/

int					ft_put_start_help(t_peaks *tmp, char **start);
int					ft_put_start(void);
int					ft_rem_line_help(char *line);
int					ft_rem_line_help_h(char *line, t_peaks **tmp);
int					ft_rem_line(char *line, t_peaks **head_con);

/*
** rem_line_help.c
*/

int					ft_put_end_help(char **end, t_peaks **tmp);
int					ft_put_end_help_h(t_peaks **prev,
										char **end, t_peaks **tmp);
int					ft_put_end_help_hh(t_peaks **tmp, char **end,
										t_peaks **prev);
int					ft_put_end(void);

#endif
