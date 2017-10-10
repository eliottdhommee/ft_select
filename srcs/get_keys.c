/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 18:35:31 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/10 19:04:00 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		is_up(char *key)
{
	char	*arrow;

	arrow = tgetstr("ku", NULL);
	arrow[1] = 91;
	if (ft_memcmp((void*)arrow, (void*)key, ft_strlen(arrow)) == 0)
		return (1);
	return (0);
}
