/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 11:19:26 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/21 12:31:39 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		ft_init_registre_link(int index, char *name, t_arg *arg, char *path)
{
}

int		registre(t_arg *arg, int index, char *path, int recursive)
{
	DIR				*rep;
	struct dirent	*b;
	struct stat		f;
	Dlist			*list;
	char			*linkname;
	size_t			r;

	list = NULL;
	rep = NULL;
	if (lstat(path, &f) != 0)
	{
		ft_putstr("failed on first lstat of open");
		return (0);
	}
	if (arg->option_l == 1 && S_ISLNK(f.st_mode))
	{
		linkname = (char *)(malloc(255));
		if ((r = readlink(path, linkname, 255)))
			linkname[r] = '\0';
		ft_init_registre_link(index, linkname, arg, path);
		index++;
		return (0);
	}
}
