/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 05:46:02 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/27 06:46:25 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		ft_check_date(long int date)
{
	long int		diff;
	long int		calc;

	calc = 3600 * 24 * 30 * 6;
	diff = time(0) - date;
	if (diff < 0)
		diff = -diff;
	if (calc < diff)
		return (1);
	return (0);
}

char	*display_special_date(char *retur)
{
	int		index;
	int		index2;
	char	*date;

	date = malloc(sizeof(ft_strlen(retur) + 1));
	index2 = 0;
	index = 4;
	while (index < 10)
	{
		date[index2] = retur[index];
		index2++;
		index++;
	}
	index = 19;
	while (index < 24)
	{
		date[index2] = retur[index];
		index2++;
		index++;
	}
	date[index2] = ' ';
	return (date);
}

int		ft_make_time(char *path)
{
	struct stat		f;
	char			*retur;
	int				index;
	char			*date;
	int				index2;

	index = 4;
	index2 = 0;
	if (lstat(path, &f) != 0)
	{
		ft_putstr("a problem just happened on lstat of make time\n");
		return (0);
	}
	retur = malloc(sizeof(ft_strlen(ctime(&f.st_mtime)) + 1));
	date = malloc(sizeof(ft_strlen(ctime(&f.st_mtime)) + 1));
	retur = ctime(&f.st_mtime);
	if (ft_check_date(*&f.st_mtime) == 1)
		date = display_special_date(retur);
	else
	{
		while (index < 16)
		{
			date[index2] = retur[index];
			index++;
			index2++;
		}
		date[index2] = ' ';
	}
	ft_putstr(date);
	return (0);
}
