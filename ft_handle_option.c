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
