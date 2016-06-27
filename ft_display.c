/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 01:54:49 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/27 02:50:12 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void	ft_display(t_arg *arg, Dlist *p_list)
{
	if (arg->option_r == 1)
	{
		ft_display_r(arg, p_list, arg->option_l);
	}
	else
		ft_display_list(p_list, arg->option_l);
}

void	ft_display_list(Dlist *p_list, int l)
{
	struct node *p_temp;

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
}
