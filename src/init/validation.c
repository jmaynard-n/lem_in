/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:49:26 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/18 12:45:32 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

t_room			*ft_add_roomlst(char *line, int index)
{
	t_room		*tmp;

	if (!(tmp = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	if (ft_strchr(line, '#'))
	{
		tmp->line = ft_strdup(line);
		tmp->x_coord = -1;
		tmp->y_coord = -1;
	}
	else
	{
		tmp->line = ft_strsub(line, 0, ft_strchr(line, ' ') - line);
		tmp->x_coord = ft_atoi(ft_strchr(line, ' '));
		tmp->y_coord = ft_atoi(ft_strrchr(line, ' '));
	}
	tmp->index = index;
	tmp->next = NULL;
	return (tmp);
}

static int		ft_check_part(char *line, int ft_comp(int))
{
	int fl;
	int i;

	fl = 0;
	i = 0;
	if (line[0] == 'L' || ft_strchr(line, '-'))
		return (0);
	while ((line[i] != '\0'))
	{
		if (((line[i] == ' ') && (fl > 0))
			|| ((line[i + 1] == '\0') && (ft_comp(line[i]))))
		{
			(i)++;
			break ;
		}
		else if ((line[i] == ' ') && (fl == 0))
			return (0);
		if (!(ft_comp(line[i])))
			return (0);
		fl++;
		(i)++;
	}
	return (1);
}

static int		ft_check_space(char *line)
{
	int count;
	int i;

	i = 0;
	count = 0;
	if (*line == '#')
		return (2);
	while (line && (line[i] != '\0'))
	{
		if (line[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

static int		ft_del_ptr(char ***ptr)
{
	char	**str;
	int		i;

	str = *ptr;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	*ptr = NULL;
	return (0);
}

int				ft_valid_rooms(char *line)
{
	int				i;
	char			**ptr;
	int				flag;
	long long int	num;

	i = 0;
	if ((line && (ft_strlen(line) == 0)) || !line || ft_check_space(line) != 2)
		return (0);
	if (*line == '#')
		return (1);
	ptr = ft_strsplit(line, ' ');
	if (ft_check_part(ptr[0], &(ft_isprint)) == 0)
		return (ft_del_ptr(&ptr));
	while (++i < 3 && ptr[i])
	{
		num = ft_atoi_large(ptr[i], &flag);
		if (num > (long long int)2147483647 ||
			num < (long long int)-2147483648 || flag == 0)
			return (ft_del_ptr(&ptr));
	}
	if (i != 3)
		return (ft_del_ptr(&ptr));
	ft_del_ptr(&ptr);
	return (1);
}
