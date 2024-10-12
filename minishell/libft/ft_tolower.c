
#include "libft.h"

int	ft_tolower(int input)
{
	if (input >= 'A' && input <= 'Z')
	{
		input += 32;
	}
	return (input);
}
