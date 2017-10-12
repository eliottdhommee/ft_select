/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:54:38 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/12 18:37:48 by edhommee         ###   ########.fr       */
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
	if (var->pos_y < var->line)
	{
		tputs(tgetstr("hd", NULL), 0, putchar_tput);
		var->pos_y++;
	}
	return (var);
}

t_term		*ft_curleft(t_term *var)
{
	if (var->pos_x > 0)
	{
		tputs(tgetstr("kl", NULL), 0, putchar_tput);
		var->pos_x--;
	}
	return (var);
}

t_term		*ft_curright(t_term *var)
{
	if (var->pos_x < var->col)
	{
		tputs(tgetstr("kl", NULL), 0, putchar_tput);
		var->pos_x--;
	}
	return (var);
}
