/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 16:20:17 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/24 18:11:22 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_keys.h"

int		is_space(char *key)
{
	if (ft_memcmp((void*)KEY_SPACE, (void*)key, 6) == 0)
		return (1);
	return (0);
}

int		is_close(char *key)
{
	if (ft_memcmp((void*)KEY_ESC, (void*)key, 6) == 0 ||
			ft_memcmp((void*)KEY_C, (void*)key, 6) == 0 ||
			ft_memcmp((void*)KEY_SLASH, (void*)key, 6) == 0)
		return (1);
	return (0);
}

int		is_return(char *key)
{
	if (ft_memcmp((void*)KEY_RET, (void*)key, 6) == 0)
		return (1);
	return (0);
}

int		is_pause(char *key)
{
	if (ft_memcmp((void*)KEY_Z, (void*)key, 6) == 0)
		return (1);
	return (0);
}

int		is_back(char *key)
{
	if (ft_memcmp((void*)KEY_BCK, (void*)key, 6) == 0)
		return (1);
	return (0);
}

int		is_del(char *key)
{
	if (ft_memcmp((void*)KEY_DEL, (void*)key, 6) == 0)
		return (1);
	return (0);
}
