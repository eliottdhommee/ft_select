/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:29:32 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/10 18:18:53 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_list		*get_list(char **args)
{
	t_list		*begin;
	t_content	*tmp;
	int			i;

	i = 0;
	while (args[i])
	{
		tmp = new_content(args[i]);
		ft_list_push_back(&begin, tmp);
		i++;
	}
	return (begin);
}
