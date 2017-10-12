/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:18:16 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/12 18:46:23 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <termcap.h>
# include <termios.h>
# include <term.h>
# define KEY_SPACE "\x20\0\0\0\0\0"
# define KEY_ESC "\x1b\0\0\0\0\0"
# define KEY_RET "\xa\0\0\0\0\0"
# define KEY_BCK "\x7f\0\0\0\0\0"
# define KEY_DEL "\x1b\x5b\x33\x7e\0\0"

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
void		sig_handler(int signo);
int			putchar_tput(int c);
t_list		*get_list(char **args);
void		print_col(t_list *begin, t_term *var);
int			max_len(t_list *begin);
t_term		*init_var(void);
t_content	*new_content(char *name);
int			get_keys(char *str, t_term *var);
int			is_up(char *key);
int			is_down(char *key);
int			is_left(char *key);
int			is_right(char *key);
t_term		*ft_cursup(t_term *var);
t_term		*ft_curdwn(t_term *var);
t_term		*ft_curleft(t_term *var);
t_term		*ft_curright(t_term *var);

#endif
