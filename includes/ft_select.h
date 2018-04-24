/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:18:16 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/24 19:01:16 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <liblst.h>
# include <termcap.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>

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

void		raw_term(void);
void		default_term(void);
void		close_term(t_term *var, t_list *list);
t_term		*init_var(void);
t_term		*update_var(t_list *begin, t_term *var);
t_content	*new_content(char *name);
void		del_content(void *content);

int			putchar_tput(int c);
void		catch_sig(void);
t_list		*get_list(char **args);
t_content	*get_pos(t_list *list, int y, int x, t_term *var);

t_term		*print_col(t_list *begin, t_term *var);
t_term		*reprint_one(t_content *data, t_term *var, int x, int y);
t_term		*print_one(t_content *data, t_term *var, int opt);
t_term		*reprint(t_list *begin, t_term *var);

t_term		*get_keys(char *str, t_term *var, t_list **list);
t_term		*ft_goto(t_list *list, t_term *var, int x, int y);
t_term		*ft_cursup(t_term *var);
t_term		*ft_curdwn(t_term *var);
t_term		*ft_curleft(t_term *var);
t_term		*ft_curright(t_term *var);
t_term		*beginline(t_term *var);
t_term		*upnleft(t_term *var);

#endif
