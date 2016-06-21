/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 04:10:40 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/21 11:14:53 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void	ft_find_options(t_arg *arg, char *command)
{
	int		index;

	index = 0;
	while (command[index] != '\0')
	{
		if (command[index] == 'R')
			arg->option_rr = 1;
		if (command[index] == 'a')
			arg->option_a = 1;
		if (command[index] == 'l')
			arg->option_l = 1;
		if (command[index] == 'r')
			arg->option_r = 1;
		if (command[index] == 't')
			arg->option_t = 1;
		index++;
	}
}
