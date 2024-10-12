#include "../minishell.h"

int	heredoc_ctrld(char *line)
{
	if (!line)
	{
		free(line);
		return (1);
	}
	return (0);
}

void	heredoc_ctrlc(int signum)
{
	if (signum == SIGINT)
	{
		g_catch_ctrlc = 1;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_replace_line("", 0);
		rl_on_new_line();
	}
}

int	init_signals_heredoc(void)
{
	signal(CTRL_C, heredoc_ctrlc);
	signal(CTRL_SLASH, SIG_IGN);
	return (1);
}
