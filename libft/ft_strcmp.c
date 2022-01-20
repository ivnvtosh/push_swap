
#include <stddef.h>

size_t	ft_strlen(const char *s);

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	n;
	size_t	i;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s1len < s2len)
		n = s2len;
	else
		n = s1len;
	if (n == 0)
		return (0);
	n--;
	i = 0;
	while (s1[i] == s2[i] && s1[i] && i < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
