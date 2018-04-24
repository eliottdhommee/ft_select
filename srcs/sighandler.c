/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:38:24 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/24 17:49:49 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void		sig_handler(int signo)
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
	{
		raw_term();
		g_win = 1;
	}
}

void		catch_sig(void)
{
	if (signal(SIGWINCH, &sig_handler) == SIG_ERR)
		ft_printf("error");
	if (signal(SIGINT, &sig_handler) == SIG_ERR)
		ft_printf("error");
	if (signal(SIGQUIT, &sig_handler) == SIG_ERR)
		ft_printf("error");
	if (signal(SIGCONT, &sig_handler) == SIG_ERR)
		ft_printf("error");
}
