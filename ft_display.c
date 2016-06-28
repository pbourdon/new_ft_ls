/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 01:54:49 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/28 08:37:41 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void	ft_display(t_arg *arg, t_dlist *p_list)
{
	if (arg->option_r == 1)
	{
		ft_display_r(arg, p_list, arg->option_l);
	}
	else
		ft_display_list(p_list, arg->option_l);
}

int		ft_display_list(t_dlist *p_list, int l)
{
	t_node *p_temp;

	p_temp = p_list->p_head;
	if (p_list != NULL)
	{
		while (p_temp != NULL)
		{
			if (l == 1)
				ft_display_all(p_temp->path, p_temp->name);
			else
			{
				ft_putstr(p_temp->name);
				ft_putchar('\n');
			}
			p_temp = p_temp->p_next;
		}
	}
	return (0);
}
