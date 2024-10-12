
#include "../minishell.h"

int	give_type_2(int i, char *str)
{
	if (str[i] == '<')
	{
		if (str[i + 1] == '<')
			return (HEREDOC);
		return (LESS);
	}
	if (str[i] == '>')
	{
		if (str[i + 1] == '>')
			return (GREATER);
		return (GREAT);
	}
	if (str[i] == '$')
		return (DOLLAR);
	return (EXCEPT);
}

int	give_type(char *str)
{
	int		i;
	char	quote;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			quote = str[i];
			i++;
			while (str[i] && str[i] != quote)
			{
				if (str[i] == '$')
					return (DOLLAR);
				i++;
			}
		}
		else if (str[i] == '|')
			return (PIPE);
		else if (give_type_2(i, str) != EXCEPT)
			return (give_type_2(i, str));
		i++;
	}
	return (EXCEPT);
}

t_split	*get_node(const char *str, unsigned int start, size_t len)
{
	t_split	*node;
	size_t	j;

	if (!str)
		return (NULL);
	node = malloc(sizeof(t_split));
	if (!node)
		return (NULL);
	node->node = malloc(sizeof(char) * (len + 1));
	if (!node->node)
	{
		free(node);
		return (NULL);
	}
	j = 0;
	while (j < len)
	{
		node->node[j] = str[start + j];
		j++;
	}
	node->node[j] = '\0';
	node->meta = give_type(node->node);
	node->next = NULL;
	return (node);
}

void	append_to_list(t_split **head, const char *line, int start, int end)
{
	t_split	*new_node;
	t_split	*current;

	new_node = get_node(line, start, end - start);
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

t_split	*split_to_nodes(t_mini *mini)
{
	int		i;
	int		start;
	t_split	*head;

	i = 0;
	head = NULL;
	while (mini->line[i])
	{
		skip_spaces(mini->line, &i);
		if (!mini->line[i])
			break ;
		start = i;
		while (mini->line[i] == '\'' || mini->line[i] == '\"')
			i = skip_quotes(mini->line, i);
		get_token(mini->line, &i);
		if (i > start)
			append_to_list(&head, mini->line, start, i);
	}
	if (!redirect_dollar(head))
	{
		free_the_split(head);
		free_the_minis(mini);
		return (0);
	}
	return (head);
}
