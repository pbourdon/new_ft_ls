/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_link_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 02:31:10 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/27 02:33:02 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		ft_display_link_count(char *path)
{
	struct stat		f;

	if (lstat(path, &f) != 0)
	{
		ft_putstr("ft_display_link_count deconne");
		return (0);
	}
	ft_putnbr(f.st_nlink);
	ft_putchar(' ');
	return (0);
}
