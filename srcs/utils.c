/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 14:58:33 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/03 18:01:52 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int			max_len(char **args)
{
	int		i;
	size_t	max;

	i = 0;
	max = 0;
	while (args[i])
	{
		if (ft_strlen(args[i]) > max)
			max = ft_strlen(args[i]);
		i++;
	}
	return (max + 1);
}

int			putchar_tput(int c)
{
	return (write(1, &c, 1));
}

t_term		update_var(char **args, t_term var)
{
	var.max_len = max_len(args);
	var.col = tgetnum("co") / var.max_len;
	var.line = ft_tablen(args) / var.col;
	if (ft_tablen(args) % var.col > 0)
		var.line++;
	return (var);
}

void		print_col(char **args, t_term var)
{
	int		i;
	int		j;

	var = update_var(args, var);
	i = 0;
	while (i < var.line)
	{
		j = 0;
		while (j < var.col && args[i + j * var.line])
		{
			ft_printf("%-*s", var.max_len + 1, args[i + j * var.line]);
			j++;
		}
		ft_putchar('\n');
		var.pos_y++;
		tputs(tgetstr("cr", NULL), 0, putchar_tput);
		i++;
	}
	ft_nup(var.line, var);
}
