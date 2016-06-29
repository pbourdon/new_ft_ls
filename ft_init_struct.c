/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourdon <pbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:27:17 by pbourdon          #+#    #+#             */
/*   Updated: 2016/06/29 04:46:56 by pbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libls.h"

void	ft_init_struct(t_arg *arg)
{
	arg->a = 0;
	arg->option_a = 0;
	arg->option_rr = 0;
	arg->option_l = 0;
	arg->option_r = 0;
	arg->option_t = 0;
	arg->uid = 0;
}
