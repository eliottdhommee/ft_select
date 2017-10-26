/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:38:24 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/26 16:12:37 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		sig_handler(int signo)
{
	if (signo == SIGINT || signo == SIGQUIT)
	{
		g_win = 2;
	}
	else if (signo == SIGWINCH)
	{
		g_win = 1;
	}
	else if (signo == SIGCONT)
		g_win = 1;
}
