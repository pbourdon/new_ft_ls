/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:46:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/28 08:42:28 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void		dlist_delete(t_dlist **p_list)
{
	t_node		*p_temp;
	t_node		*p_del;

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

t_dlist		*dlist_prepend(t_dlist *p_list, char *path, char *name)
{
	t_node		*p_new;

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
				p_list = nik_the_norm(p_new, p_list, 0);
			else
				p_list = nik_the_norm(p_new, p_list, 1);
			p_list->length++;
		}
	}
	return (p_list);
}

t_dlist		*dlist_append(t_dlist *p_list, char *path, char *name)
{
	t_node		*p_new;

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
				p_list = nik_the_norm2(p_list, p_new, 0);
			else
				p_list = nik_the_norm2(p_list, p_new, 1);
			p_list->length++;
		}
	}
	return (p_list);
}

t_dlist		*ins_avant(t_dlist *liste, char *path, char *name, int pos)
{
	int			i;
	t_node		*n;
	t_node		*courant;

	i = 1;
	n = malloc(sizeof(*n));
	if (n == NULL)
		return (liste);
	n->path = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(name)) + 1);
	n->name = malloc(sizeof(char) * (ft_strlen(name) + 3));
	n = fuck_the_norm5(n, path, name);
	n->name = ft_strdup(name);
	courant = liste->p_head;
	while (i++ < pos)
		courant = courant->p_next;
	n->p_next = courant;
	n->p_prev = courant->p_prev;
	if (courant->p_prev == NULL)
		liste->p_head = n;
	else
		courant->p_prev->p_next = n;
	courant->p_prev = n;
	liste->length++;
	return (liste);
}

t_dlist		*ft_add_data(t_dlist *p_list, char *name, char *path, int compteur)
{
	int			max;
	t_node		*p_temp;

	max = 1;
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
			p_temp->path) > 0 && compteur++ > 0)
			p_temp = p_temp->p_next;
	}
	if (compteur == 1)
		return (dlist_prepend(p_list, path, name));
	else if (compteur >= max)
		return (dlist_append(p_list, path, name));
	p_list = ins_avant(p_list, path, name, compteur);
	return (p_list);
}
