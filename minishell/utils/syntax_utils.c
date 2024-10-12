
#include "../minishell.h"

int	jump_quotes(char c, int quote)
{
	if ((c == '\'' || c == '\"') && quote == 0)
		quote = c;
	else if ((quote == c) && quote != 0)
		quote = 0;
	return (quote);
}

int	jump_spaces(char *input, int i)
{
	while (input[i] == ' ')
		i++;
	return (i);
}
