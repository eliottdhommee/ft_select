/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:34:58 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/24 18:36:34 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		raw_term(void)
{
	struct termios	tattr;

	tcgetattr(0, &tattr);
	tattr.c_lflag &= ~(ECHO | ICANON | ISIG);
	tattr.c_oflag &= ~(OPOST);
	tattr.c_cc[VMIN] = 0;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &tattr);
	tgetent(NULL, ft_getenv("TERM"));
	tputs(tgetstr("vi", NULL), 0, putchar_tput);
	tputs(tgetstr("ho", NULL), 0, putchar_tput);
	tputs(tgetstr("cd", NULL), 0, putchar_tput);
}

void		default_term(void)
{
	struct termios	tattr;

	tcgetattr(0, &tattr);
	tattr.c_lflag |= (ECHO | ICANON | ISIG);
	tattr.c_oflag |= (OPOST);
	tcsetattr(0, TCSADRAIN, &tattr);
	tputs(tgetstr("ve", NULL), 0, putchar_tput);
}
