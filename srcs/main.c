/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:22:53 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/24 19:01:19 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int			ft_select(char **arg)
{
	char				buf[6];
	static t_term		*var = NULL;
	static t_list		*begin_list = NULL;

	if (!var || !begin_list)
	{
		var = init_var();
		begin_list = get_list(arg);
		var = print_col(begin_list, var);
	}
	else
		var = reprint(begin_list, var);
	while (g_win == 0)
	{
		ft_bzero(buf, 6);
		read(0, buf, 6);
		var = get_keys(buf, var, &begin_list);
		if (!begin_list)
			close_term(var, NULL);
	}
	return (0);
}

int			main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!ft_getenv("TERM"))
		return (0);
	raw_term();
	catch_sig();
	while (g_win != 2)
	{
		g_win = 0;
		ft_select(&argv[1]);
	}
	return (0);
}
