/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:43:08 by jmaynard          #+#    #+#             */
/*   Updated: 2019/09/16 18:47:40 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem_in.h"

static int		ft_check_valid_ants_line(char *line)
{
	int	i;

	i = 0;
	if (ft_strlen(line) == 0)
		return (0);
	if (line && line[i] == '-')
		i++;
	while (line && line[i] != '\0')
	{
		if (!(ft_isdigit(line[i])))
			return (0);
		i++;
	}
	return (1);
}

int				ft_valid_ants(char *line)
{
	long long int	num;
	int				flag;
	long long int	int_max;

	int_max = 2147483647;
	flag = 1;
	if (!(ft_check_valid_ants_line(line)))
		return (-1);
	num = ft_atoi_large(line, &flag);
	if (num > int_max || num < 0 || flag == 0)
		return (-1);
	return (num);
}
