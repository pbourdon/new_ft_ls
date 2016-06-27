/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:19:26 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/27 06:52:41 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		registre(t_arg *arg, char *path, int recursive)
{
	DIR				*rep;
	struct dirent	*b;
	struct stat		f;
	char			*linkname;
	size_t			r;
	Dlist *list = NULL;

	rep = NULL;
	list = dlist_new();
	if (lstat(path, &f) != 0)
	{
		ft_putstr("failed on first lstat of open");
		return (0);
	}
	rep = opendir(path);
	if (rep == NULL)
	{
		ft_putstr(path);
		ft_putchar(' ');
		ft_putstr("Permission Denied\n");
		return (0);
	}
	while ((b = readdir(rep)) != 0)
	{
		ft_putstr("analyse en cours...");
		ft_putstr(ft_strjoin_special(path, b->d_name));
		ft_putchar('\n');
		if (ft_check_folder(ft_strjoin_special(path, b->d_name)) == 1
			&& arg->option_a == 0)
		{
		}
		else
		{
			list = ft_add_data(list, b->d_name, path);
		}
	}
	ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(":\n");
	ft_display(arg, list);
	if (recursive == 1)
	{
		closedir(rep);
		rep = NULL;
		rep = opendir(path);
		if (rep == NULL)
		{
			ft_putstr("permission denied\n");
			return (0);
		}
		while ((b = readdir(rep)) != 0)
		{
			if (ft_check_folder(ft_strjoin_special(path, b->d_name)) == 1 && arg->option_a == 0)
			{
			}
			else
			{
				if (lstat(ft_strjoin_special(path, b->d_name), &f) != 0)
				{
					ft_putstr("A problem just happened of lstat");
					return(0);
				}
				if (S_ISDIR(f.st_mode) && s(b->d_name) != 0 && e(b->d_name) != 0)
				{
					ft_putstr("on rentre par ici");
					ft_putstr(ft_strjoin_special(path, b->d_name));
					ft_putchar('\n');
					registre(arg, ft_strjoin_special(path, b->d_name), 1);
				}
			}
		}
	}
		closedir(rep);
	return (0);
}
