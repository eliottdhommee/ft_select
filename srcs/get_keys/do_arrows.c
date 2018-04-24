/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_arrows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:24:42 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/24 18:19:00 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_keys.h"

t_term		*do_up(t_list **list, t_term *var)
{
	return (ft_goto(*list, var, var->pos_x, var->pos_y - 1));
}

t_term		*do_down(t_list **list, t_term *var)
{
	return (ft_goto(*list, var, var->pos_x, var->pos_y + 1));
}

t_term		*do_left(t_list **list, t_term *var)
{
	return (ft_goto(*list, var, var->pos_x - 1, var->pos_y));
}

t_term		*do_right(t_list **list, t_term *var)
{
	return (ft_goto(*list, var, var->pos_x + 1, var->pos_y));
}
