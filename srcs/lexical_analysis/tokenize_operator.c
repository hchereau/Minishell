/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 15:31:14 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/21 15:31:22 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_lexem_match(const char *lexem, const char *input)
{
	return (ft_strncmp(lexem, input, ft_strlen(lexem)) == 0);
}

static t_grammar_element	*find_grammar_element(const char *input)
{
	static t_grammar_element	grammar_elements[] = {
	{.token_type = PIPE_OPERATOR, .token_lexem = "|"},
	{.token_type = HEREDOC_OPERATOR, .token_lexem = "<<"},
	{.token_type = INPUT_REDIR_OPERATOR, .token_lexem = "<"},
	{.token_type = APPEND_OPERATOR, .token_lexem = ">>"},
	{.token_type = OUTPUT_REDIR_OPERATOR, .token_lexem = ">"},
	};
	size_t						i;
	size_t						array_size;

	i = 0;
	array_size = sizeof(grammar_elements) / sizeof(*grammar_elements);
	while (i < array_size)
	{
		if (is_lexem_match(grammar_elements[i].token_lexem, input))
		{
			return (&grammar_elements[i]);
		}
		++i;
	}
	return (NULL);
}

t_token_list	tokenize_operator(const char *input,
					t_token_list token_list)
{
	t_grammar_element	*grammar_element;

	grammar_element = find_grammar_element(input);
	if (grammar_element != NULL)
	{
		return (add_token_to_token_list(token_list,
				grammar_element->token_lexem, grammar_element->token_type));
	}
	else
		return (NULL);
}
