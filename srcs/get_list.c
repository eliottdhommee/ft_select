/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:29:32 by edhommee          #+#    #+#             */
/*   Updated: 2018/04/24 18:28:17 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int			cmp_content(void *data1, void *data2)
{
	return (ft_strcmp(((t_content*)data1)->name, ((t_content*)data2)->name));
}

t_list				*get_list(char **args)
{
	t_list		*begin;
	t_content	*tmp;
	int			i;

	i = 0;
	begin = NULL;
	while (args[i])
	{
		tmp = new_content(args[i]);
		ft_lstinsert(&begin, tmp, &cmp_content);
		i++;
	}
	return (begin);
}
