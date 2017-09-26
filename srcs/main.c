/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:22:53 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/26 15:32:40 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			main(void)
{
	char				*term_name;
	char				term_buf[2048];
	char				*buffer;
	char				*temp;

	term_name = ft_getenv("TERM");
	tgetent(term_buf, term_name);
	buffer = malloc(ft_strlen(term_buf));

	cl_string = tgetstr ("cl", &buffer);
	cm_string = tgetstr ("cm", &buffer);
	auto_wrap = tgetflag ("am");
	height = tgetnum ("li");
	width = tgetnum ("co");

	temp = tgetstr ("pc", &buffer);
	PC = temp ? *temp : 0;
	BC = tgetstr ("le", &buffer);
	UP = tgetstr ("up", &buffer);
	return (0);
}
