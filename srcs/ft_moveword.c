/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moveword.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:13:03 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/31 18:24:07 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			rotate_x(int x, int y, t_term *var)
{
	if (x < 0)
		x = var->col - 1;
	if (y < 0 && x > 0)
		x = x - 1;
	else if (y < 0 && x <= 0)
		x = 0;
	if (x >= var->col)
		x = 0;
	if (y >= var->line && x < var->col)
		x = x + 1;
	return (x);
}

int			rotate_y(int x, int y, t_term *var)
{
	if (x < 0 && y > 0)
		y = y - 1;
	else if (x < 0 && y <= 0)
		y = 0;
	if (y < 0)
		y = var->line - 1;
	if (x >= var->col && y < var->line)
		y = y + 1;
	if (y >= var->line)
		y = 0;
	return (y);
}

t_term		*ft_goto(t_list *list, t_term *var, int x, int y)
{
	t_content		*tmp;
	int				z;

	z = x;
	x = rotate_x(x, y, var);
	y = rotate_y(z, y, var);
	if (!(tmp = get_pos(list, x, y, var)))
	{
		if (var->pos_x == var->col - 2 && x == var->col - 1)
		{
			x = 0;
			y = (y < var->line - 1) ? y + 1 : y;
		}
		else if (var->pos_x == var->col - 1 || var->pos_x == 0)
			x = x - 1;
		if (!(tmp = get_pos(list, x, y, var)))
			return (var);
	}
	var = print_one(get_pos(list, var->pos_x, var->pos_y, var), var, 0);
	var = reprint_one(tmp, var, x, y);
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
	tputs(tgetstr("ho", NULL), 0, putchar_tput);
	var->pos_x = 0;
	var->pos_y = 0;
	return (var);
}
