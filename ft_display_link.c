/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 02:37:57 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/27 06:44:51 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		ft_display_link(char *path)
{
	struct stat		f;
	char			*linkname;
	ssize_t			r;
	int				index;

	index = 0;
	if (lstat(path, &f) != 0)
	{
		ft_putstr("lstat of display_link deconne\n");
		return (0);
	}
	if (S_ISLNK(f.st_mode))
	{
		linkname = (char*)malloc(255);
		if (linkname == NULL)
			return (0);
		if ((r = readlink(path, linkname, 255)) != -1)
			linkname[r] = '\0';
		else
		{
			ft_putstr("display_link deconne ici");
			return (0);
		}
		ft_putstr(" -> ");
		ft_putstr(linkname);
		free(linkname);
	}
	return (0);
}
