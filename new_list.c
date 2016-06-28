/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:22:59 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/28 05:52:09 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

Dlist	*dlist_prepend(Dlist *p_list, char *name, char *path)
{
	struct node		*p_new;

	if (p_list != NULL)
	{
		p_new = malloc(sizeof(*p_new));
		if (p_new != NULL)
		{
			p_new->name = name;
			p_new->p_prev = NULL;
			if (p_list->p_tail == NULL)
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
			p_list->length++;
		}
	}
	return (p_list);
}

Dlist	*dlist_append(Dlist *p_list, char *name, char *path)
{
	struct node		*p_new;

	p_new = malloc(sizeof(*p_new));
	if (p_list != NULL)
	{
		if (p_new != NULL)
		{
			p_new->name = path;
			p_new->p_next = NULL;
			if (p_list->p_tail == NULL)
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
			p_list->length++;
		}
	}
	return (p_list);
}

Dlist	*dlist_insert(Dlist *p_list, char *name, char *path, int position)
{
	struct node		*p_temp;
	struct node		*p_new;
	int				i;

	if (p_list != NULL)
	{
		p_temp = p_list->p_head;
		i = 1;
		while (p_temp != NULL && i <= position)
		{
			if (position == i)
			{
				if (p_temp->p_next == NULL)
					p_list = dlist_append(p_list, "name", "path");
				else if (p_temp->p_prev == NULL)
					p_list = dlist_prepend(p_list, "name", "path");
				else
				{
					p_new = malloc(sizeof(*p_new));
					if (p_new != NULL)
					{
						p_new->name = name;
						p_temp->p_next->p_prev = p_new;
						p_temp->p_prev->p_next = p_new;
						p_new->p_prev = p_temp->p_prev;
						p_new->p_next = p_temp;
						p_list->length++;
					}
				}
			}
			else
				p_temp = p_temp->p_next;
			i++;
		}
	}
	return (p_list);
}

void	dlist_delete(Dlist **p_list)
{
	struct node		*p_temp;
	struct node		*p_del;

	if (*p_list != NULL)
	{
		p_temp = (*p_list)->p_head;
		while (p_temp != NULL)
		{
			p_del = p_temp;
			p_temp = p_temp->p_next;
			free(p_del);
		}
		free(*p_list);
		*p_list = NULL;
	}
}

Dlist	*dlist_new(void)
{
	Dlist	*p_new;

	p_new = malloc(sizeof(*p_new));
	if (p_new != NULL)
	{
		p_new->length = 0;
		p_new->p_head = NULL;
		p_new->p_tail = NULL;
	}
	return (p_new);
}
