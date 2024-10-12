#include "../minishell.h"

void	handle_input(int pipefd[2], char *target)
{
	char	*input;

	while (1)
	{
		input = readline("> ");
		if (g_catch_ctrlc == 1)
		{
			g_catch_ctrlc = 0;
			free(input);
			break ;
		}
		if (heredoc_ctrld(input) || ft_strcmp(input, target) == 0)
		{
			free(input);
			break ;
		}
		if (!input)
			exit(EXIT_FAILURE);
		if (write(pipefd[1], input, ft_strlen(input)) == -1
			|| write(pipefd[1], "\n", 1) == -1)
			exit(EXIT_FAILURE);
		free(input);
	}
}

int	heredoc(char *target)
{
	int		pipefd[2];

	init_signals_heredoc();
	if (pipe(pipefd) == -1)
		exit(EXIT_FAILURE);
	handle_input(pipefd, target);
	close(pipefd[1]);
	return (pipefd[0]);
}

