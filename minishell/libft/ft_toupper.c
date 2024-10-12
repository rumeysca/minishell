
#include "libft.h"

int	ft_toupper(int input)
{
	if (input >= 'a' && input <= 'z')
	{
		input -= 32;
	}
	return (input);
}
