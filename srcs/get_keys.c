/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 18:35:31 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/31 15:37:47 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_term		*do_space(t_list *list, t_term *var)
{
	t_content		*tmp;

	tmp = get_pos(list, var->pos_x, var->pos_y, var);
	if (tmp && tmp->is_selected == 0)
		tmp->is_selected = 1;
	else if (tmp && tmp->is_selected == 1)
		tmp->is_selected = 0;
	var = ft_goto(list, var, var->pos_x + 1, var->pos_y);
	return (var);
}

t_term		*do_rmone(t_list **list, t_term *var)
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

t_term		*get_keys(char *str, t_term *var, t_list **list)
{
	if (is_up(str))
		var = ft_goto(*list, var, var->pos_x, var->pos_y - 1);
	else if (is_down(str))
		var = ft_goto(*list, var, var->pos_x, var->pos_y + 1);
	else if (is_left(str))
		var = ft_goto(*list, var, var->pos_x - 1, var->pos_y);
	else if (is_right(str))
		var = ft_goto(*list, var, var->pos_x + 1, var->pos_y);
	else if (ft_memcmp((void*)KEY_SPACE, (void*)str, 6) == 0)
		var = do_space(*list, var);
	else if (ft_memcmp((void*)KEY_ESC, (void*)str, 6) == 0 ||
			ft_memcmp((void*)KEY_C, (void*)str, 6) == 0 ||
			ft_memcmp((void*)KEY_SLASH, (void*)str, 6) == 0)
	{
		close_term(var);
		exit(0);
	}
	else if (ft_memcmp((void*)KEY_RET, (void*)str, 6) == 0)
	{
		close_term(var);
		return_selec(*list);
		exit(0);
	}
	else if (ft_memcmp((void*)KEY_BCK, (void*)str, 6) == 0)
		var = do_rmone(list, var);
	else if (ft_memcmp((void*)KEY_DEL, (void*)str, 6) == 0)
		var = do_rmone(list, var);
	return (var);
}
