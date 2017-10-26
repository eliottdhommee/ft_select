/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:34:58 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/26 12:43:25 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		raw_term(void)
{
	struct termios	tattr;

	tcgetattr(0, &tattr);
	tattr.c_lflag &= ~( ECHO | ICANON );
	tattr.c_oflag &= ~( OPOST );
	tattr.c_cc[VMIN] = 0;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &tattr);
	tgetent(NULL, ft_getenv("TERM"));
	tputs(tgetstr("vi", NULL), 0, putchar_tput);
}

void		default_term(void)
{
	struct termios	tattr;

	tcgetattr(0, &tattr);
	tattr.c_lflag |= ( ECHO | ICANON );
	tattr.c_oflag |= ( OPOST );
	tcsetattr(0, TCSADRAIN, &tattr);
	tputs(tgetstr("ve", NULL), 0, putchar_tput);
}

void		close_term(t_term *var)
{
	var = upnleft(var);
	tputs(tgetstr("cd", NULL), 0, putchar_tput);
	default_term();
}
