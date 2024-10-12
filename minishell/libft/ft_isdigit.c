
#include "libft.h"

int	ft_isdigit(int input)
{
	if (input >= '0' && input <= '9')
	{
		return (1);
	}
	return (0);
}
