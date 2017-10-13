/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:58:33 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/13 17:12:27 by edhommee         ###   ########.fr       */
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
	return (write(1, &c, 1));
}

t_term		*update_var(t_list *begin, t_term *var)
{
	int		size;

	size = ft_lstsize(begin);
	var->max_len = max_len(begin);
	var->col = tgetnum("co") / var->max_len;
	var->line = size / var->col;
	if (size % var->col > 0)
		var->line++;
	return (var);
}
