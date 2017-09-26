/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 11:18:16 by edhommee          #+#    #+#             */
/*   Updated: 2017/09/26 15:33:41 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <termcap.h>

char *cl_string, *cm_string;
int height;
int width;
int auto_wrap;

char PC;   /* For tputs.  */
char *BC;  /* For tgoto.  */
char *UP;

#endif
