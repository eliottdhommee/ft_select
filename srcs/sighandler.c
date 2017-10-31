/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:38:24 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/31 15:32:32 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		sig_handler(int signo)
{
	if (signo == SIGINT || signo == SIGQUIT)
	{
		tputs(tgetstr("ho", NULL), 0, putchar_tput);
		tputs(tgetstr("cd", NULL), 0, putchar_tput);
		default_term();
	}
	else if (signo == SIGWINCH)
	{
		g_win = 1;
	}
	else if (signo == SIGCONT)
		g_win = 1;
}
