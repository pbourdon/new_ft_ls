/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 04:36:09 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/29 04:46:47 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

int		ft_ls(t_arg *arg, char *path, int id)
{
	if (arg->option_rr == 1)
		registre(arg, path, 1);
	else
		registre(arg, path, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_arg	arg;
	int		argument_nbr;
	int		option;

	if (argc > 1)
	{
		ft_init_struct(&arg);
		option = ft_handle_option(&arg, argc, argv, 0);
		if (option + 1 == argc)
			ft_ls(&arg, ".", 0);
		else
		{
			argument_nbr = 2;
			while (argument_nbr <= argc)
			{
				if (argv[argument_nbr - 1][0] != '-')
					ft_ls(&arg, argv[argument_nbr - 1], 0);
				argument_nbr++;
			}
		}
	}
	else if (argc == 1)
		ft_ls(&arg, "./", 0);
	return (0);
}
