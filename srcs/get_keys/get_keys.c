/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 18:35:31 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/24 19:06:16 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_keys.h"

static t_term	*do_rmone(t_list **list, t_term *var)
{
	int		x;
	int		y;

	x = var->pos_x;
	y = var->pos_y;
	ft_deli(list, 1 + var->pos_y + var->pos_x * var->line, &del_content);
	var = reprint(*list, var);
	var = ft_goto(*list, var, x, y);
	return (var);
}

t_term			*get_keys(char *str, t_term *var, t_list **list)
{
	int				i;
	static t_keys	checker[] = {
		{&is_up, &do_up},
		{&is_down, &do_down},
		{&is_right, &do_right},
		{&is_left, &do_left},
		{&is_space, &do_space},
		{&is_close, &do_close},
		{&is_return, &do_return},
		{&is_pause, &do_pause},
		{&is_back, &do_rmone},
		{&is_del, &do_rmone},
		{NULL, NULL}
	};

	i = 0;
	while (checker[i].iser != NULL)
	{
		if (checker[i].iser(str) == 1)
			return ((checker[i].f)(list, var));
		i++;
	}
	return (var);
}
