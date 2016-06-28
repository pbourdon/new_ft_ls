/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_rights.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 07:48:33 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/28 01:45:57 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void	ft_display_rights2(struct stat f)
{
	if (S_ISBLK(f.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(f.st_mode))
		ft_putchar('c');
	else if (S_ISFIFO(f.st_mode))
		ft_putchar('p');
	else if (S_ISSOCK(f.st_mode))
		ft_putchar('s');
	else if (S_ISLNK(f.st_mode))
		ft_putchar('l');
	else if (S_ISDIR(f.st_mode))
		ft_putchar('d');
	else
		ft_putchar('-');
	ft_putstr((f.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr((f.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr((f.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr((f.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr((f.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr((f.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr((f.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr((f.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr((f.st_mode & S_IXOTH) ? "x" : "-");
	ft_putchar(' ');
}

void	ft_display_rights(char *path)
{
	struct stat f;

	if (lstat(path, &f) != 0)
		exit(EXIT_FAILURE);
	ft_display_rights2(f);
}
