/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printwords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 16:57:14 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/31 15:52:45 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_term		*print_one(t_content *data, t_term *var, int opt)
{
	if (opt == 1)
		tputs(tgetstr("us", NULL), 0, putchar_tput);
	if (data->is_selected == 1)
		tputs(tgetstr("mr", NULL), 0, putchar_tput);
	ft_printf("%w%-*s", 2, var->max_len + 1, data->name);
	if (data->is_selected == 1 || opt == 1)
		tputs(tgetstr("me", NULL), 0, putchar_tput);
	var->pos_x++;
	return (var);
}

t_term		*reprint_one(t_content *data, t_term *var, int x, int y)
{
	while (var->pos_x < x)
		var = ft_curright(var);
	while (var->pos_x > x)
		var = ft_curleft(var);
	while (var->pos_y < y)
		var = ft_curdwn(var);
	while (var->pos_y > y)
		var = ft_cursup(var);
	var = print_one(data, var, 1);
	var = ft_curleft(var);
	return (var);
}

t_term		*reprint(t_list *begin, t_term *var)
{
	var = upnleft(var);
	tputs(tgetstr("cd", NULL), 0, putchar_tput);
	var = print_col(begin, var);
	return (var);
}

t_term		*print_col(t_list *begin, t_term *var)
{
	int		i;
	int		j;
	t_list	*tmp;

	var = update_var(begin, var);
	if (var->line > get_line())
		return (var);
	i = 0;
	while (i < var->line)
	{
		j = 0;
		while (j < var->col && (tmp = ft_list_at(begin, 1 + i + j++ * var->line)))
			var = print_one((t_content*)tmp->data, var, 0);
		if (i != var->line - 1)
		{
			ft_putchar_fd('\n', 2);
			var->pos_y++;
		}
		var = beginline(var);
		i++;
	}
	var = ft_goto(begin, var, 0, 0);
	return (var);
}
