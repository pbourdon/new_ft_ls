/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_ownership.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 02:33:20 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/27 02:48:05 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		ft_display_ownership(char *path)
{
	struct stat			f;
	struct passwd		*owner;
	struct group		*group;
	int					uid;
	int					gid;
	if (lstat(path, &f) != 0)
	{
		ft_putstr("lstat ft_display_ownership deconne");
		return (0);
	}
	uid = f.st_uid;
	gid = f.st_gid;
	owner = getpwuid(uid);
	group = getgrgid(gid);
	if (owner != NULL && owner->pw_name != NULL)
		ft_putstr(owner->pw_name);
	ft_putchar(' ');
	if (group != NULL && group->gr_name != NULL)
		ft_putstr(group->gr_name);
	ft_putchar(' ');
	return (0);
}
