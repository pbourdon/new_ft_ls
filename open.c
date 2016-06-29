/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:19:26 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/29 04:47:31 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		fuck_the_norm(t_arg *arg, char *path, t_dlist *list)
{
	list = ft_add_data(list, "", path, 1);
	ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(":\n");
	ft_display(arg, list);
	dlist_delete(&list);
	return (0);
}

int		fuck_the_norm2(char *path)
{
	ft_putstr(path);
	ft_putchar(' ');
	ft_putstr("Permission denied\n");
	return (0);
}

void	fuck_the_norm3(t_arg *arg, t_dlist *list, char *path)
{
	ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(":\n");
	ft_display(arg, list);
}

int		registre(t_arg *arg, char *p, int recursive)
{
	DIR				*rep;
	struct dirent	*b;
	struct stat		f;
	size_t			r;
	t_dlist			*list;

	ft_putchar('\n');
	list = NULL;
	rep = NULL;
	list = dlist_new();
	if (lstat(p, &f) != 0)
		return (0);
	if (arg->option_l == 1 && S_ISLNK(f.st_mode))
		return (fuck_the_norm(arg, p, list));
	rep = opendir(p);
	if (rep == NULL)
		return (fuck_the_norm2(p));
	while ((b = readdir(rep)) != 0)
	{
		if (z(t(p, b->d_name)) == 0 || (z(t(p, b->d_name)) == 1 && arg->a == 1))
			list = ft_add_data(list, b->d_name, p, 1);
	}
	fuck_the_norm3(arg, list, p);
	dlist_delete(&list);
	return (fuck_the_norm6(p, arg, rep, recursive));
}

int		registre2(char *path, t_arg *arg)
{
	DIR				*rep;
	struct dirent	*b;
	struct stat		f;
	size_t			r;

	rep = NULL;
	rep = opendir(path);
	if (rep == NULL)
		fuck_the_norm2(path);
	while ((b = readdir(rep)) != 0)
	{
		if ((ft_check_folder(ft_strjoin_special(path, b->d_name)) == 1
			&& arg->option_a == 1) ||
			(ft_check_folder(ft_strjoin_special(path, b->d_name)) == 0))
		{
			if (lstat(ft_strjoin_special(path, b->d_name), &f) != 0)
				return (0);
			if (S_ISDIR(f.st_mode) && s(b->d_name) != 0 && e(b->d_name) != 0)
				registre(arg, ft_strjoin_special(path, b->d_name), 1);
		}
	}
	if (rep != NULL)
		closedir(rep);
	return (0);
}
