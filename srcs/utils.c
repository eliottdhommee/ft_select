/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:58:33 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/12 18:56:10 by edhommee         ###   ########.fr       */
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

void		print_col(t_list *begin, t_term *var)
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
			ft_printf("%-*s", var->max_len + 1, ((t_content*)tmp->data)->name);
			j++;
		}
		var = ft_curdwn(var);
		tputs(tgetstr("cr", NULL), 0, putchar_tput);
		i++;
	}
}
