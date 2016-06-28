/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 04:27:23 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/28 08:38:20 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

t_dlist	*dlist_new(void)
{
	t_dlist *p_new;

	p_new = malloc(sizeof(*p_new));
	if (p_new != NULL)
	{
		p_new->length = 0;
		p_new->p_head = NULL;
		p_new->p_tail = NULL;
	}
	return (p_new);
}
