/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:29:12 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/24 18:21:34 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_keys.h"

t_term		*do_space(t_list **list, t_term *var)
{
	t_content		*tmp;

	tmp = get_pos(*list, var->pos_x, var->pos_y, var);
	if (tmp && tmp->is_selected == 0)
		tmp->is_selected = 1;
	else if (tmp && tmp->is_selected == 1)
		tmp->is_selected = 0;
	var = ft_goto(*list, var, var->pos_x + 1, var->pos_y);
	return (var);
}

t_term		*do_close(t_list **list, t_term *var)
{
	(void)list;
	close_term(var, NULL);
	return (var);
}

t_term		*do_return(t_list **list, t_term *var)
{
	close_term(var, *list);
	return (var);
}

t_term		*do_pause(t_list **list, t_term *var)
{
	(void)list;
	var = upnleft(var);
	tputs(tgetstr("cd", NULL), 0, putchar_tput);
	default_term();
	ioctl(0, TIOCSTI, KEY_Z);
	return (var);
}
