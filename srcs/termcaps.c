/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 18:40:25 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/24 18:40:38 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_term		*beginline(t_term *var)
{
	tputs(tgetstr("cr", NULL), 0, putchar_tput);
	var->pos_x = 0;
	return (var);
}

t_term		*upnleft(t_term *var)
{
	tputs(tgetstr("ho", NULL), 0, putchar_tput);
	var->pos_x = 0;
	var->pos_y = 0;
	return (var);
}

int			putchar_tput(int c)
{
	return (write(2, &c, 1));
}
