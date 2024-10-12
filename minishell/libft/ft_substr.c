
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	str_len;
	size_t	end;
	size_t	i;

	i = start;
	str_len = ft_strlen(s);
	end = 0;
	if (!s)
		return (NULL);
	if (start < str_len)
		end = str_len - start;
	if (end > len)
		end = len;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	dest = (char *)malloc((sizeof(char) * (end + 1)));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s + start, end + 1);
	return (dest);
}
