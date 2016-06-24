/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:46:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/24 06:35:41 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

Dlist *dlist_new(void)
{
	Dlist *p_new = malloc(sizeof *p_new);

	if (p_new != NULL)
	{
		p_new->length = 0;
		p_new->p_head = NULL;
		p_new->p_tail = NULL;
	}
	return p_new;
}

Dlist *dlist_prepend(Dlist *p_list, char *path, char *name)
{
	if (p_list != NULL)
	{
		struct node *p_new = malloc(sizeof *p_new);
		if (p_new != NULL)
		{
			p_new->path = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(name)) + 1);
			p_new->name = malloc(sizeof(char) * (ft_strlen(name) + 3));
			p_new->path = ft_strjoin_special(path, name);
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
	return p_list;
}

Dlist *dlist_append(Dlist *p_list, char *path, char *name)
{
	if (p_list != NULL)
	{
		struct node *p_new = malloc(sizeof *p_new);
		if (p_new != NULL)
		{
			p_new->path = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(name)) + 1);
			p_new->name = malloc(sizeof(char) * (ft_strlen(name) + 3));
			p_new->path = ft_strjoin_special(path, name);
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
	return p_list; 
}

Dlist *dlist_insert(Dlist *p_list, char *path, char *name, int position)
{
	if (p_list != NULL)
	{
		struct node *p_temp = p_list->p_head;
		int i = 1;
		while (p_temp != NULL && i <= position)
		{
			if (position == i)
			{
				if (p_temp->p_next == NULL)
				{
					ft_putstr("il prends la place de ");
					ft_putstr(p_temp->name);
					ft_putstr("la");
					p_list = dlist_append(p_list, path, name);
				}
				else if (p_temp->p_prev == NULL)
				{
					ft_putstr("here");
					p_list = dlist_prepend(p_list, path, name);
				}
				else
				{
					ft_putstr(path);
					ft_putstr(" prends la place de ");
					ft_putstr(p_temp->path);
					struct node *p_new = malloc(sizeof *p_new);;
					if (p_new != NULL)
					{
						p_new->path = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(name)) + 1);
						p_new->name = malloc(sizeof(char) * (ft_strlen(name) + 3));
						p_new->path = ft_strjoin_special(path, name);
						p_new->name = ft_strdup(name);
						p_temp->p_next->p_prev = p_new;
						p_temp->p_prev->p_next = p_new;
						p_new->p_prev = p_temp->p_prev;
						p_new->p_next = p_temp;
						p_list->length++;
					}
				}
			}
			else
			{
				p_temp = p_temp->p_next;
			}
			i++;
		}
	}
	return p_list;
}

void	ft_display_list(Dlist *p_list)
{
	int		compteur;

	compteur = 1;
	ft_putstr("--------------------- NOUVELLE LISTE ---------------\n");
	if (p_list != NULL)
	{
		struct node *p_temp = p_list->p_head;
		while (p_temp != NULL)
		{
			printf("%d", compteur);
			printf("%s\n", p_temp->path);
			p_temp = p_temp->p_next;
			compteur++;
		}
	}
	ft_putstr("---------------------- FIN DE LALISTE ---------------\n");
}

Dlist	*ft_add_data(Dlist *p_list, char *name, char *path)
{
	int		compteur;
	int		max;
	char	*test;

	test = malloc(sizeof(2048));
	max = 1;
	compteur = 1;
	if (p_list != NULL)
	{
		struct node *p_temp = p_list->p_head;
		while (p_temp != NULL)
		{
			p_temp = p_temp->p_next;
			max++;
		}
		p_temp = p_list->p_head;
		while (p_temp != NULL && strcmp(ft_strjoin_special(path, name), p_temp->path) > 0)
		{
			
			ft_putstr(p_temp->name);
			ft_putstr(" VS ");
			ft_putstr(name);
			ft_putchar(' ');
			ft_putnbr(strcmp(ft_strjoin_special(path, name), p_temp->path));
			ft_putchar('\n');
		
			test = strdup(p_temp->path);
			p_temp = p_temp->p_next;
			compteur++;
		}
		if (strcmp(ft_strjoin_special(path, name), test) > 0)
		{
			ft_putstr(name);
			ft_putstr(" is upper than ");
			ft_putstr(test);
		}
	}
	if (compteur == 1)
	{
		p_list = dlist_prepend(p_list, path, name);
		ft_display_list(p_list);
		return (p_list);
	}
	if (compteur >= max)
	{
		ft_putstr("ici");
		p_list = dlist_append(p_list, path, name);
		ft_display_list(p_list);
		return (p_list);
	}
	ft_putstr("on insere ");
	ft_putstr(name);
	ft_putstr(" a la place ");
	ft_putnbr(compteur);
	ft_putchar ('\n');
	p_list = dlist_insert(p_list, path, name, compteur);
	ft_display_list(p_list);
	return (p_list);
}
