/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:38:24 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/24 14:58:24 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		sig_handler(int signo)
{
	if (signo == SIGINT)
	{
		default_term();
		exit(0);
	}
}

void		sig_handler2(int signo)
{
	if (signo == SIGWINCH)
	{
		g_win = 1;
	}
}
