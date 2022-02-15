
#include "push_swap.h"
#include <stdlib.h>

void	terminate(int code)
{
	if (code == ERROR)
		ft_putstr_fd("Error\n", 2);
	exit(code);
}
