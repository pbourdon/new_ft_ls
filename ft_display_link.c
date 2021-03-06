/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_link.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 02:37:57 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/28 04:34:22 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		ft_display_link(char *path)
{
	struct stat		f;
	char			*linkname;
	ssize_t			r;

	if (lstat(path, &f) != 0)
		return (0);
	if (S_ISLNK(f.st_mode))
	{
		linkname = (char*)malloc(255);
		if (linkname == NULL)
			return (0);
		if ((r = readlink(path, linkname, 255)))
			linkname[r] = '\0';
		else
			return (0);
		ft_putstr(" -> ");
		ft_putstr(linkname);
		free(linkname);
	}
	return (0);
}
