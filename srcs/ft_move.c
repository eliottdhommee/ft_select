/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:54:38 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/15 16:04:40 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_term		*ft_cursup(t_term *var)
{
	if (var->pos_y > 0)
	{
		tputs(tgetstr("up", NULL), 0, putchar_tput);
		var->pos_y--;
	}
	return (var);
}

t_term		*ft_curdwn(t_term *var)
{
	if (var->pos_y < var->line - 1)
	{
		tputs(tgetstr("do", NULL), 0, putchar_tput);
		var->pos_y++;
	}
	return (var);
}

t_term		*ft_curleft(t_term *var)
{
	int		i;

	i = var->max_len + 1;
	if (var->pos_x > 0)
	{
		while (i--)
			tputs(tgetstr("le", NULL), 0, putchar_tput);
		var->pos_x--;
	}
	return (var);
}

t_term		*ft_curright(t_term *var)
{
	int		i;

	i = var->max_len + 1;
	if (var->pos_x < var->col - 1)
	{
		while (i--)
			tputs(tgetstr("nd", NULL), 0, putchar_tput);
		var->pos_x++;
	}
	return (var);
}
