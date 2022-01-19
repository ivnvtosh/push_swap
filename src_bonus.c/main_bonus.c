
#include "../libft/libft.h"

void	checker(int count, char **nubmers);

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	checker(--argc, ++argv);
	return (10);
}