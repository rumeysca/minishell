
#include "libft.h"

int	ft_isalnum(int input)
{
	if ((input >= '0' && input <= '9') || (input >= 'a' && input <= 'z')
		|| (input >= 'A' && input <= 'Z'))
	{
		return (1);
	}
	return (0);
}
