/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:58:33 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/24 18:58:14 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int			max_len(t_list *begin)
{
	size_t	max;

	max = 0;
	while (begin)
	{
		if (ft_strlen(((t_content*)begin->data)->name) > max)
			max = ft_strlen(((t_content*)begin->data)->name);
		begin = begin->next;
	}
	return (max + 1);
}

static int			get_col(void)
{
	struct winsize ws;

	ioctl(0, TIOCGWINSZ, &ws);
	return (ws.ws_col);
}

static int			get_line(void)
{
	struct winsize ws;

	ioctl(0, TIOCGWINSZ, &ws);
	return (ws.ws_row);
}

t_term		*update_var(t_list *begin, t_term *var)
{
	var->size = ft_lstsize(begin);
	var->max_len = max_len(begin) + 1;
	var->col = get_col() / (var->max_len + 1);
	get_line();
	if (var->col > 0)
		var->line = var->size / var->col;
	if (var->col > 0 && var->size % var->col > 0)
		var->line++;
	return (var);
}
