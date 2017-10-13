/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moveword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:13:03 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/13 17:24:29 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_term		*ft_goto(t_term *var, int x, int y)
{
	while (var->pos_x < x)
		var = ft_curright(var);
	while (var->pos_x > x)
		var = ft_curleft(var);
	while (var->pos_y < y)
		var = ft_curdwn(var);
	while (var->pos_y > y)
		var = ft_cursup(var);
	return (var);
}

t_term		*beginline(t_term *var)
{
	tputs(tgetstr("cr", NULL), 0, putchar_tput);
	var->pos_x = 0;
	return (var);
}

t_term		*upnleft(t_term *var)
{
	var = beginline(var);
	while (var->pos_y > 0)
		var = ft_cursup(var);
	return (var);
}
