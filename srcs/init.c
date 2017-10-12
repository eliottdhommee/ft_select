/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 17:34:14 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/12 18:45:52 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_content	*new_content(char *name)
{
	t_content	*new;

	if (!(new = malloc(sizeof(t_content*))))
		return (NULL);
	new->name = ft_strdup(name);
	new->is_selected = 0;
	return (new);
}

t_term		*init_var(void)
{
	t_term		*var;

	var = ft_memalloc(sizeof(t_term*));
	var->col = 0;
	var->line = 0;
	var->pos_x = 0;
	var->pos_y = 0;
	var->max_len = 0;
	return (var);
}
