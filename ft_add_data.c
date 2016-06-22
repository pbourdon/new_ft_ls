/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:46:12 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/22 19:40:14 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void	ft_display_list(t_arg2 *arg2)
{
	struct node *tmp = arg2;
	while (tmp != NULL)
	{
		ft_putstr("again");
		ft_putstr(tmp->path);
		printf("%s", tmp->path);
		tmp = tmp->p_next;
	}
}

t_arg2	*ft_add_data(char *name, t_arg2 *arg2, char *path)
{
	struct node* new = malloc(sizeof(struct node));

	new->path = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(name)) + 1);
	new->name = malloc(sizeof(char) * (ft_strlen(name) + 1));
	new->path = ft_strjoin_special(path, name);
	new->name = ft_strdup(name);
	ft_putstr(new->name);
	ft_putchar(' ');
	ft_putstr(new->path);
	ft_putchar('\n');
	new->p_next = arg2;
	return (arg2);
}
