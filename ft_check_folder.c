/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_folder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 18:06:37 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/22 18:07:55 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_folder(char *path)
{
	int		index;

	index = 1;
	while (path[index] != '\0')
	{
		if (path[index - 1] == '/' && path[index] == '.')
			return (1);
		index++;
	}
	return (0);
}
