# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 11:04:39 by jmaynard          #+#    #+#              #
#    Updated: 2019/09/16 19:08:43 by jmaynard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEAD = ./lem_in.h
LDFLAGS = -L ./libft/ -lft
LIBFT = ./libft/libft.a
VISUAL = visu-hex

GRAPH_SRC =	create.c free.c sort.c \
			del.c insert.c direct.c \
			distance.c queve.c clean_graph.c
GRAPH_PATH = src/graph

INIT_SRC =	del_farm.c init.c \
			print_farm.c tree_lis.c\
			validation.c copy_rooms.c \
			valid_ants.c valid_links.c
INIT_PATH = src/init

SRC =		main.c move.c sence.c \
			path.c move_to_next.c \
			move_from_start.c move_to_end.c
SRC_PATH = src

VIS =		ants_count.c change_koord_help_1.c change_koord_help_2.c change_koord_help_3.c \
			change_koord.c create_line_help.c create_line.c destroy_ant.c find_peaks_help_1.c \
			find_peaks_help_2.c find_peaks.c free_struct.c help.c main.c mouse_hook.c \
			move_ants_help_1.c move_ants.c put_name.c put_oblako.c refill_struct.c rem_line_help.c \
			rem_line.c run_ants_help.c run_ants.c work_with_list_help.c work_with_list.c
VIS_PATH = vis
V_INC = -I /usr/local/include
V_LIB = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

G_SRC = $(addprefix $(GRAPH_PATH)/, $(GRAPH_SRC))
S_SRC = $(addprefix $(SRC_PATH)/, $(SRC))
I_SRC = $(addprefix $(INIT_PATH)/, $(INIT_SRC))
V_SRC = $(addprefix $(VIS_PATH)/, $(VIS))

OBJ = $(S_SRC:.c=.o)
G_OBJ = $(G_SRC:.c=.o)
I_OBJ = $(I_SRC:.c=.o)
V_OBJ = $(V_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(G_OBJ) $(I_OBJ) $(LIBFT) $(VISUAL)
	@$(CC) -o $(NAME) $(OBJ) $(G_OBJ) $(I_OBJ) $(LDFLAGS)

$(LIBFT):
	@$(MAKE) -C ./libft/

$(VISUAL): $(V_OBJ)
	@Cc -o $(VISUAL) $(V_INC) $(V_OBJ) $(LDFLAGS) $(V_LIB)

%.o: %.c $(HEAD)
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@$(MAKE) -C ./libft/ $@
	@/bin/rm -f $(OBJ) $(G_OBJ) $(I_OBJ) $(V_OBJ)

fclean: clean
	@$(MAKE) -C ./libft/ $@
	@/bin/rm -f $(NAME) $(VISUAL)

re: fclean all

.PHONY: all, clean, fclean, re