/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:18:16 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/10 18:54:30 by edhommee         ###   ########.fr       */
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

t_list		*get_list(char **args);
void		raw_term(void);
void		default_term(void);
int			putchar_tput(int c);
void		sig_handler(int signo);
void		print_col(t_list *begin, t_term var);
int			max_len(t_list *begin);
t_term		init_var(void);
void		ft_nup(int i, t_term var);
t_content	*new_content(char *name);
int			is_up(char *key);

#endif
