
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	memnbr;

	memnbr = count * size;
	str = (void *)malloc(memnbr);
	if (!str)
	{
		return (0);
	}
	ft_bzero(str, memnbr);
	return (str);
}
