/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:35:45 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/24 18:36:28 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void			return_selec(t_list *begin_list)
{
	t_list		*tmp;

	tmp = begin_list;
	while (tmp)
	{
		if (((t_content*)tmp->data)->is_selected == 1)
			ft_printf("%w%s ", 1, ((t_content*)tmp->data)->name);
		tmp = tmp->next;
	}
}

void			close_term(t_term *var, t_list *list)
{
	var = upnleft(var);
	tputs(tgetstr("cd", NULL), 0, putchar_tput);
	default_term();
	if (list)
		return_selec(list);
	exit(0);
}
