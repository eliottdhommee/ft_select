/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:22:53 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/24 15:17:12 by edhommee         ###   ########.fr       */
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
}

void		default_term(void)
{
	struct termios	tattr;

	tcgetattr(0, &tattr);
	tattr.c_lflag |= ( ECHO | ICANON );
	tattr.c_oflag |= ( OPOST );
	tcsetattr(0, TCSADRAIN, &tattr);
}

int			ft_select(char **arg)
{
	char				buf[6];
	static t_term		*var = NULL;
	static t_list		*begin_list = NULL;

	if (!var || !begin_list)
	{
		var = init_var();
		begin_list = get_list(arg);
		print_col(begin_list, var);
	}
	else if (var->col != get_col() / (var->max_len + 1))
		var = reprint(begin_list, var);
	while (g_win == 0)
	{
		ft_bzero(buf, 6);
		read(0, buf, 6);
		var = get_keys(buf, var, &begin_list);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	raw_term();
	if (signal(SIGWINCH , &sig_handler2) == SIG_ERR)
		ft_printf("error");
	if (signal(SIGINT , &sig_handler) == SIG_ERR)
		ft_printf("error");
	while (1)
	{
		g_win = 0;
		ft_select(&argv[1]);
	}
	default_term();
	return (0);
}
