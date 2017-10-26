/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:58:33 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/26 12:29:47 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			max_len(t_list *begin)
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

int			putchar_tput(int c)
{
	return (write(2, &c, 1));
}

int			get_col(void)
{
	struct winsize ws;

	ioctl(0, TIOCGWINSZ, &ws);
	return (ws.ws_col);
}

t_term		*update_var(t_list *begin, t_term *var)
{
	var->size = ft_lstsize(begin);
	var->max_len = max_len(begin) + 1;
	var->col = get_col() / (var->max_len + 1);
	var->line = var->size / var->col;
	if (var->size % var->col > 0)
		var->line++;
	return (var);
}
