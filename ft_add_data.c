/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:46:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/28 06:02:18 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void		dlist_delete(Dlist **p_list)
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
		p_list = NULL;
	}
}

Dlist		*dlist_prepend(Dlist *p_list, char *path, char *name)
{
	struct node		*p_new;

	if (p_list != NULL)
	{
		p_new = malloc(sizeof(*p_new));
		if (p_new != NULL)
		{
			p_new->path = malloc(sizeof(char) * (ft_strlen(path) +
				ft_strlen(name)) + 1);
			p_new->name = malloc(sizeof(char) * (ft_strlen(name) + 3));
			if (ft_strlen(name) > 0)
				p_new->path = ft_strjoin_special(path, name);
			else
				p_new->path = ft_strdup(path);
			p_new->name = ft_strdup(name);
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

Dlist		*dlist_append(Dlist *p_list, char *path, char *name)
{
	struct node		*p_new;

	if (p_list != NULL)
	{
		p_new = malloc(sizeof(*p_new));
		if (p_new != NULL)
		{
			p_new->path = malloc(sizeof(char) * (ft_strlen(path) +
				ft_strlen(name)) + 1);
			p_new->name = malloc(sizeof(char) * (ft_strlen(name) + 3));
			if (ft_strlen(name) > 0)
				p_new->path = ft_strjoin_special(path, name);
			else
				p_new->path = ft_strdup(path);
			p_new->name = ft_strdup(name);
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

Dlist	*ins_avant(Dlist *liste, char *path, char *name, int pos)
{
	int				i;
	struct node		*nouveau_element;
	struct node		*courant;

	i = 1;
	nouveau_element = malloc(sizeof(*nouveau_element));
	if (nouveau_element == NULL)
		return (liste);
	nouveau_element->path = malloc(sizeof(char) * (ft_strlen(path) +
		ft_strlen(name)) + 1);
	nouveau_element->name = malloc(sizeof(char) * (ft_strlen(name) + 3));
	if (ft_strlen(name) > 0)
		nouveau_element->path = ft_strjoin_special(path, name);
	else
		nouveau_element->path = ft_strdup(path);
	nouveau_element->name = ft_strdup(name);
	courant = liste->p_head;
	while (i++ < pos)
		courant = courant->p_next;
	nouveau_element->p_next = courant;
	nouveau_element->p_prev = courant->p_prev;
	if (courant->p_prev == NULL)
		liste->p_head = nouveau_element;
	else
		courant->p_prev->p_next = nouveau_element;
	courant->p_prev = nouveau_element;
	liste->length++;
	return (liste);
}

Dlist	*ft_add_data(Dlist *p_list, char *name, char *path)
{
	int				compteur;
	int				max;
	struct node		*p_temp;

	max = 1;
	compteur = 1;
	if (p_list != NULL)
	{
		p_temp = p_list->p_head;
		while (p_temp != NULL)
		{
			p_temp = p_temp->p_next;
			max++;
		}
		p_temp = p_list->p_head;
		while (p_temp != NULL && strcmp(ft_strjoin_special(path, name),
			p_temp->path) > 0)
		{
			p_temp = p_temp->p_next;
			compteur++;
		}
	}
	if (compteur == 1)
	{
		p_list = dlist_prepend(p_list, path, name);
		return (p_list);
	}
	else if (compteur >= max)
	{
		p_list = dlist_append(p_list, path, name);
		return (p_list);
	}
	p_list = ins_avant(p_list, path, name, compteur);
	return (p_list);
}
