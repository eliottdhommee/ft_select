/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:22:53 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/10 19:04:19 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void		raw_term(void)
{
	struct termios	tattr;

	tcgetattr(0, &tattr);
	tattr.c_lflag &= ~( ECHO | ICANON );
	tattr.c_oflag &= ~( OPOST );
	tattr.c_cc[VMIN] = 1;
	tattr.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &tattr);
	tgetent(NULL, ft_getenv("TERM"));
}

void		default_term(void)
{
	struct termios	tattr;

	tcgetattr(0, &tattr);
	tattr.c_lflag |= ( ECHO | ICANON );
	tattr.c_oflag |= ( OPOST );
	tcsetattr(0, TCSADRAIN, &tattr);
}

int			main(int argc, char **argv)
{
	char		buf[6];
	t_term		var;
	t_list		*begin_list;
	int			i;

	raw_term();
	var = init_var();
	begin_list = get_list(&argv[1]);
	print_col(begin_list, var);
	if (signal(SIGINT, sig_handler) == SIG_ERR)
		ft_printf("error");
	while (argc)
	{
		i = 0;
		ft_bzero(buf, 6);
		read(0, buf, 6);
	}
	default_term();
	return (0);
}
