
#include "push_swap.h"

void	push_swap(int count, char **num);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (NOTHING);
	push_swap(--argc, ++argv);
	return (GOOD);
}
