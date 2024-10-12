
#include "libft.h"

int	ft_isalpha(int input)
{
	if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z'))
	{
		return (1);
	}
	return (0);
}
