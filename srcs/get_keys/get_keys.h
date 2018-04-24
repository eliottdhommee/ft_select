/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keys.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 17:53:55 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/24 18:42:00 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_KEYS_H
# define GET_KEYS_H

# include <ft_select.h>

# define KEY_SPACE "\x20\0\0\0\0\0"
# define KEY_ESC "\x1b\0\0\0\0\0"
# define KEY_RET "\xa\0\0\0\0\0"
# define KEY_BCK "\x7f\0\0\0\0\0"
# define KEY_DEL "\x1b\x5b\x33\x7e\0\0"
# define KEY_C "\x3\0\0\0\0\0"
# define KEY_Z "\x1a\0\0\0\0\0"
# define KEY_SLASH "\x1c\0\0\0\0\0"

typedef struct	s_keys
{
	int			(*iser)(char*);
	t_term		*(*f)(t_list**, t_term*);
}				t_keys;

int			is_up(char *key);
int			is_down(char *key);
int			is_left(char *key);
int			is_right(char *key);
int			is_space(char *key);
int			is_close(char *key);
int			is_return(char *key);
int			is_pause(char *key);
int			is_back(char *key);
int			is_del(char *key);

t_term		*do_up(t_list **list, t_term *var);
t_term		*do_down(t_list **list, t_term *var);
t_term		*do_left(t_list **list, t_term *var);
t_term		*do_right(t_list **list, t_term *var);
t_term		*do_space(t_list **list, t_term *var);
t_term		*do_close(t_list **list, t_term *var);
t_term		*do_return(t_list **list, t_term *var);
t_term		*do_pause(t_list **list, t_term *var);

#endif
