/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_lexes_user_command_line.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 19:21:13 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/18 19:21:31 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token_list	end_tokenization(t_token_list tokenized_command_line)
{
	t_token_list	token_list;

	token_list = add_token_to_token_list(tokenized_command_line, NULL,
		TOKEN_LIST_END);
	return (token_list);
}

static t_token_list	start_tokenization(t_token_list tokenized_command_line)
{
	t_token_list	token_list;

	token_list = add_token_to_token_list(tokenized_command_line, NULL,
		TOKEN_LIST_START);
	return (token_list);
}

t_token_type	search_in_lexer_dictionary(const char operator)
{
	t_token_type	type;
	size_t			i;

	i = 0;
	while (LEXER_DICTIONARY[i] != '\0')
	{
		if (LEXER_DICTIONARY[i] == operator)
		{
			type = i;
			return (type);
		}
	}
	return (FAILURE);
}

t_token_list	tokenize_operator(const char operator,
					t_token_list tokenized_command_line)
{
	t_token_type	token_type;

	token_type = search_in_lexer_dictionary(operator);
	tokenized_command_line = add_token_to_token_list(tokenized_command_line, NULL,
			token_type);
	return (tokenized_command_line);
}

t_token_list	tokenizer(const char *user_command_line,
					t_token_list tokenized_command_line)
{
	size_t			i;

	i = 0;
	while(user_command_line[i] != '\0')
	{
		if (is_separator(user_command_line[i] == true))
			tokenized_command_line = tokenize_separator(user_command_line[i],
				tokenized_command_line);
		if (user_command_line[i] == '|')
		{
			tokenized_command_line = add_token_to_token_list(tokenized_command_line, NULL,
			PIPE);
		}
		else if (user_command_line[i] == '<')
		{
			tokenized_command_line = add_token_to_token_list(tokenized_command_line, NULL,
				INPUT_REDIR_OPERATOR);
		}
		else if (user_command_line[i] == '>')
		{
			tokenized_command_line = add_token_to_token_list(tokenized_command_line, NULL, OUTPUT_REDIR_OPERATOR);
		}
		if (tokenized_command_line == NULL)
			return (NULL);
		++i;
	}
	return (tokenized_command_line);
}

t_token_list	minishell_lexes_user_command_line(const char *user_command_line)
{
	t_token_list	tokenized_command_line;

	tokenized_command_line = NULL;
	tokenized_command_line = start_tokenization(tokenized_command_line);
	if (tokenized_command_line != NULL)
	{
		tokenized_command_line = tokenizer(user_command_line, tokenized_command_line);
	}
	if (tokenized_command_line != NULL)
	{
		tokenized_command_line = end_tokenization(tokenized_command_line);
	}
	return (tokenized_command_line);
}
