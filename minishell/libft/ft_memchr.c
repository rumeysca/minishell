
#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)ptr;
	i = 0;
	while (i < num)
	{
		if (str[i] == (unsigned char)value)
		{
			return (str + i);
		}
		i++;
	}
	return (0);
}
