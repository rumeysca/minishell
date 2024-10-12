#include "../minishell.h"

void	print_error_exit(const char *arg, const char *msg, int code)
{
	int	len;

	len = ft_strlen(arg);
	write(2, "minishell: exit: ", 17);
	if (len > 0)
		write(2, arg, len);
	write(2, ": ", 2);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	errno = code;
}

int	check_argument(const char *arg)
{
	int	j;

	j = 0;
	if (arg[j] == '+' || arg[j] == '-')
		j++;
	while (arg[j])
	{
		if (arg[j] < '0' || arg[j] > '9')
			return (0);
		j++;
	}
	return (1);
}

int	valid_value(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if (arg[0] == '-')
	{
		if (len > ft_strlen("-9223372036854775808"))
			return (0);
		if (len == ft_strlen("-9223372036854775808") \
			&& ft_strcmp(arg, "-9223372036854775808") > 0)
			return (0);
	}
	else
	{
		if (len > ft_strlen("9223372036854775807"))
			return (0);
		if (len == ft_strlen("9223372036854775807") \
			&& ft_strcmp(arg, "9223372036854775807") > 0)
			return (0);
	}
	return (1);
}

void	exit_handling(char **args, int i, t_exit_status *exit_code_line)
{
	long long	exit_code_s;

	if (!check_argument(args[0]) || !valid_value(args[0]))
	{
		print_error_exit(args[0], "numeric argument required", 255);
		exit_code_line->exit_code = 255;
		exit(exit_code_line->exit_code);
	}
	exit_code_s = ft_longlong(args[0]);
	if (i > 1)
	{
		print_error_exit("", "too many arguments", 1);
		exit_code_line->exit_code = 1;
		return ;
	}
	exit_code_line->exit_code = exit_code_s % 256;
	exit(exit_code_line->exit_code);
}

void	ft_exit(t_line *line, t_exit_status *exit_code_line)
{
	int	i;

	i = 0;
	while (line->arg && line->arg[i] != NULL)
		i++;
	printf("exit\n");
	if (!line->arg)
		exit(exit_code_line->exit_code);
	exit_handling(line->arg, i, exit_code_line);
}
