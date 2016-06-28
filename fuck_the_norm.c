/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fuck_the_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 06:17:13 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/28 06:34:57 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

struct node		*fuck_the_norm5(struct node *nouveau_element, char *path,
	char *nam)
{
	if (ft_strlen(nam) > 0)
		nouveau_element->path = ft_strjoin_special(path, nam);
	else
		nouveau_element->path = ft_strdup(path);
	return (nouveau_element);
}

Dlist			*nik_the_norm(struct node *p_new, Dlist *p_list, int i)
{
	if (i == 0)
	{
		p_new->p_next = NULL;
		p_list->p_head = p_new;
		p_list->p_tail = p_new;
	}
	else
	{
		p_list->p_head->p_prev = p_new;
		p_new->p_next = p_list->p_head;
		p_list->p_head = p_new;
	}
	return (p_list);
}

Dlist				*nik_the_norm2(Dlist *p_list, struct node *p_new, int i)
{
	if (i == 0)
	{
		p_new->p_prev = NULL;
		p_list->p_head = p_new;
		p_list->p_tail = p_new;
	}
	else
	{
		p_list->p_tail->p_next = p_new;
		p_new->p_prev = p_list->p_tail;
		p_list->p_tail = p_new;
	}
	return (p_list);
}
