/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 18:35:31 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/12 18:50:05 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		get_keys(char *str , t_term *var)
{
	if (is_up(str))
		var = ft_cursup(var);
	else if (is_down(str))
		var = ft_curdwn(var);
	else if (is_left(str))
		var = ft_curleft(var);
	else if (is_right(str))
		var = ft_curright(var);
	else if (ft_memcmp((void*)KEY_SPACE, (void*)str, 6) == 0)
		ft_printf("espace\n");
	else if (ft_memcmp((void*)KEY_ESC, (void*)str, 6) == 0)
		ft_printf("echap\n");
	else if (ft_memcmp((void*)KEY_RET, (void*)str, 6) == 0)
		ft_printf("entree\n");
	else if (ft_memcmp((void*)KEY_BCK, (void*)str, 6) == 0)
		ft_printf("backspace\n");
	else if (ft_memcmp((void*)KEY_DEL, (void*)str, 6) == 0)
		ft_printf("delete\n");
	return (0);
}
