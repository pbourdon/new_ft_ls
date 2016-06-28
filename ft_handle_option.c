/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_option.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 04:35:04 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/28 04:35:13 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		ft_handle_option(t_arg *arg, int argc, char **argv, int option)
{
	int		argument_nbr;

	argument_nbr = argc;
	while (argument_nbr > 1)
	{
		if (argv[argument_nbr - 1][0] == '-')
		{
			ft_find_options(arg, argv[argument_nbr - 1]);
			option++;
		}
		argument_nbr--;
	}
	return (option);
}
