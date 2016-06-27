/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 07:01:37 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/27 02:47:31 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		ft_display_size(char *path)
{
	struct stat		f;
	int				nbr;

	if (lstat(path, &f) != 0)
	{
		ft_putstr("lstat of ft_display_size fucked up");
		return (0);
	}
	if (S_ISBLK(f.st_mode) || S_ISCHR(f.st_mode))
	{
		ft_putnbr(major(f.st_rdev));
		ft_putstr(", ");
		ft_putnbr(minor(f.st_rdev));
		ft_putchar(' ');
	}
	else
	{
		nbr = f.st_size;
		ft_putnbr(nbr);
		ft_putchar(' ');
	}
	return (0);
}
