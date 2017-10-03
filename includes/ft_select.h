/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:18:16 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/03 18:28:58 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <termcap.h>
# include <termios.h>
# include <term.h>

typedef struct	s_term
{
	int			col;
	int			line;
	int			pos_x;
	int			pos_y;
	int			max_len;
}				t_term;

typedef struct	s_content
{
	char		*name;
	int			is_selected;
}				t_content;

void		raw_term(void);
void		default_term(void);
int			putchar_tput(int c);
void		sig_handler(int signo);
void		print_col(char **args, t_term var);
int			max_len(char **args);
t_term		init_var(void);
void		ft_nup(int i, t_term var);

#endif
