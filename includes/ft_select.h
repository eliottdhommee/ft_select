/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:18:16 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/26 16:01:04 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <termcap.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# define KEY_SPACE "\x20\0\0\0\0\0"
# define KEY_ESC "\x1b\0\0\0\0\0"
# define KEY_RET "\xa\0\0\0\0\0"
# define KEY_BCK "\x7f\0\0\0\0\0"
# define KEY_DEL "\x1b\x5b\x33\x7e\0\0"

typedef struct	s_term
{
	int			size;
	int			col;
	int			line;
	int			pos_x;
	int			pos_y;
	int			max_len;
	int			end;
}				t_term;

int				g_win;

typedef struct	s_content
{
	char		*name;
	int			is_selected;
}				t_content;

int			ft_select(char **arg);
void		raw_term(void);
void		default_term(void);
void		close_term(t_term *var);
int			putchar_tput(int c);

void		sig_handler(int signo);

t_list		*get_list(char **args);
t_content	*get_pos(t_list *list, int x, int y, t_term *var);
void		return_selec(t_list *begin_list);

t_term		*print_one(t_content *data, t_term *var, int opt);
t_term		*print_col(t_list *begin, t_term *var);
t_term		*reprint(t_list *begin, t_term *var);

int			max_len(t_list *begin);
t_term		*init_var(void);
t_term		*update_var(t_list *begin, t_term *var);
int			get_col(void);
t_content	*new_content(char *name);
void		del_content(void *content);

t_term		*get_keys(char *str, t_term *var, t_list **list);
int			is_up(char *key);
int			is_down(char *key);
int			is_left(char *key);
int			is_right(char *key);

t_term		*ft_goto(t_list *list, t_term *var, int x, int y);
t_term		*ft_cursup(t_term *var);
t_term		*ft_curdwn(t_term *var);
t_term		*ft_curleft(t_term *var);
t_term		*ft_curright(t_term *var);
t_term		*beginline(t_term *var);
t_term		*upnleft(t_term *var);

#endif
