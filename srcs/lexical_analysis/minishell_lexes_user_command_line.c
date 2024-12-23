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
	tokenized_command_line = add_token_to_token_list(tokenized_command_line, NULL,
		TOKEN_LIST_END);
	return (tokenized_command_line);
}

static t_token_list	start_tokenization(t_token_list token_list)
{
	token_list = add_token_to_token_list(token_list, NULL,
		TOKEN_LIST_START);
	return (token_list);
}

static t_token_list	build_token_list(const char *input,
					t_token_list token_list)
{
	while(!is_input_end(input))
	{
		if (is_separator(*input) != NULL)
		{
			//printf("char  == %c\n", *input);
			++input;
		}
		else if (is_operator(*input) != NULL)
		{
			token_list = tokenize_operator(&input,
				token_list);
			//printf("token_char = %c\n", *input);
			if (token_list == NULL)
				return (NULL);
		}
		else
		{
			token_list = tokenize_word(&input, token_list);
			if (token_list == NULL)
				return (NULL);
		}
	}
	return (token_list);
}

t_token_list	tokenize(const char *input)
{
	t_token_list	token_list;
	(void)input;

	token_list = NULL;
	token_list = start_tokenization(token_list);
	if (token_list != NULL)
	{
		token_list = build_token_list(input, token_list);
	}
	if (token_list != NULL)
	{
		token_list = end_tokenization(token_list);
	}
	return (token_list);
}
