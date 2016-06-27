/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/08 09:49:11 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/27 02:29:46 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		ft_display_r(t_arg *arg, Dlist *p_list, int l)
{
	struct node *p_temp;

	p_temp = p_list->p_tail;
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
			p_temp = p_temp->p_prev;
		}
	}
	return (0);
}
