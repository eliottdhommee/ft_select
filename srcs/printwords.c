/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printwords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:57:14 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/13 17:36:11 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_term		*print_one(t_content *data, t_term *var, int opt)
{
	if (opt == 1)
		tputs(tgetstr("us", NULL), 0, putchar_tput);
	if (data->is_selected == 1)
		tputs(tgetstr("mr", NULL), 0, putchar_tput);
	ft_printf("%-*s", var->max_len + 1, data->name);
	if (data->is_selected == 1 || opt == 1)
		tputs(tgetstr("me", NULL), 0, putchar_tput);
	var->pos_x++;
	return (var);
}

t_term		*print_col(t_list *begin, t_term *var)
{
	int		i;
	int		j;
	t_list	*tmp;

	var = update_var(begin, var);
	i = 0;
	while (i < var->line)
	{
		j = 0;
		while (j < var->col && (tmp = ft_list_at(begin, 1 + i + j * var->line)))
		{
			var = print_one((t_content*)tmp->data, var, 1);
			j++;
		}
		if (i != var->line - 1)
		{
			ft_putchar('\n');
			var->pos_y++;
		}
		var = beginline(var);
		i++;
	}
	var = upnleft(var);
	return (var);
}
