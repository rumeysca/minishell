
#include "../minishell.h"

int	syntax_error_quote(void)
{
	write(1, "minishell: ", 11);
	printf("Syntax error. Unclosed quote.\n");
	return (0);
}

int	syntax_error_pipe(void)
{
	write(1, "minishell: ", 11);
	printf("Syntax error. Invalid pipe using.\n");
	return (0);
}

int	not_allowed_char_error(void)
{
	write(1, "minishell: ", 11);
	printf("Unexpected character using.\n");
	return (0);
}

int	syntax_error_redir(void)
{
	write(1, "minishell: ", 11);
	printf("Mixed redirect using.\n");
	return (0);
}

int	redirect_dollar(t_split *split)
{
	while (split)
	{
		if (is_redir(split) && split->meta != HEREDOC && \
		split->next->meta == DOLLAR)
		{
			write(1, "minishell: ", 11);
			printf("ambiguous redirect\n");
			return (0);
		}
		split = split->next;
	}
	return (1);
}
