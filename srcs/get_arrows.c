/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arrows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 17:40:06 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/12 17:40:50 by edhommee         ###   ########.fr       */
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

int		is_down(char *key)
{
	char	*arrow;

	arrow = tgetstr("kd", NULL);
	arrow[1] = 91;
	if (ft_memcmp((void*)arrow, (void*)key, ft_strlen(arrow)) == 0)
		return (1);
	return (0);
}

int		is_left(char *key)
{
	char	*arrow;

	arrow = tgetstr("kl", NULL);
	arrow[1] = 91;
	if (ft_memcmp((void*)arrow, (void*)key, ft_strlen(arrow)) == 0)
		return (1);
	return (0);
}

int		is_right(char *key)
{
	char	*arrow;

	arrow = tgetstr("kr", NULL);
	arrow[1] = 91;
	if (ft_memcmp((void*)arrow, (void*)key, ft_strlen(arrow)) == 0)
		return (1);
	return (0);
}
