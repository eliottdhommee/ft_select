/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:38:24 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/16 19:18:40 by edhommee         ###   ########.fr       */
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
	else if (signo == SIGWINCH)
	{
		ft_select(NULL);
	}
}
