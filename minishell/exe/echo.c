#include "../minishell.h"

void	echo_case1(char c, int *expect, int *ret)
{
	if (c == '-')
		*expect = 2;
	else
		*ret = 0;
}

int	echo_case2(char c, int *expect, int *ret)
{
	if (c == 'n')
		*expect = 3;
	else if (c == ' ')
	{
		*ret = 1;
		return (1);
	}
	else
		*ret = 0;
	return (0);
}

int	echo_case3(char c, int *expect, int *ret)
{
	if (c == ' ')
	{
		*expect = 1;
		return (1);
	}
	else if (c != 'n')
		*ret = 0;
	return (0);
}

int	echo_index(char *s)
{
	int		ans;
	int		expect;
	size_t	i;
	int		ret;

	i = -1;
	ret = -1;
	ans = 0;
	expect = 1;
	while (++i < ft_strlen(s))
	{
		if (expect == 1)
			echo_case1(s[i], &expect, &ret);
		else if (expect == 2 && echo_case2(s[i], &expect, &ret) == 1)
			return (i + 1);
		else if (echo_case3(s[i], &expect, &ret) == 1)
			ans = i + 1;
		if (ret != -1)
			return (ans + ret);
	}
	if (expect == 3)
		ans += 3;
	return (ans);
}

int	echo_main(char *s)
{
	int	ind;

	if (!s)
	{
		printf("\n");
		return (0);
	}
	ind = echo_index(s);
	printf("%s", &s[ind]);
	if (ind < 3)
		printf("\n");
	return (0);
}
