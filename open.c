/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:19:26 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/27 01:48:00 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		ft_init_registre_link(int index, char *name, t_arg *arg, char *path)
{
	return (0);
}

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
		ft_putstr("permission denied\n");
		return (0);
	}
	while ((b = readdir(rep)) != 0)
	{
		if (ft_check_folder(ft_strjoin_special(path, b->d_name)) == 1
			&& arg->option_a == 0)
		{
		}
		else
		{
			list = ft_add_data(list, b->d_name, path);
		}
	}
	ft_display_list(list);
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
					registre(arg, ft_strjoin_special(path, b->d_name), 1);
				}
			}
		}
	}
	return (0);
}
