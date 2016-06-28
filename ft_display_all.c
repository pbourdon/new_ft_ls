/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/27 02:28:05 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/28 02:01:51 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		ft_display_all(char *path, char *name)
{
	ft_display_rights(path);
	ft_display_link_count(path);
	ft_display_ownership(path);
	ft_display_size(path);
	ft_make_time(path);
	if (ft_strlen(name) > 0)
		ft_putstr(name);
	else
		ft_putstr(path);
	ft_display_link(path);
	ft_putchar('\n');
	return (0);
}
