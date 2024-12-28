/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analyser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 21:05:13 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/14 17:15:22 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static t_types_matching_status	search_if_following_type_is_matching(
// 			t_token_type current_token_type, t_token_type next_token_type)
// {

// }

static t_types_matching_status check_tokens_types(
			t_token_type current_token_type,
			t_token_type next_token_type)
{
	const t_token_type	*possibilities_array =
							get_possibilities_list(current_token_type);
	size_t				i;

	i = 0;
	while (possibilities_array[i] != NULL)
	{
		if (next_token_type == possibilities_array[i])
			return (MATCH);
		++i;
	}
	return (NO_MATCH_FOUND);
}

static t_syntax_status	check_tokens_sequence(t_token_list *current_token)
{
	t_token_type	current_token_type;
	t_token_type	next_token_type;

	current_token_type = ((t_token *)(*current_token)->content)->token_type;
	if (current_token_type == TOKEN_LIST_END)
		return (VALID_SYNTAX);
	next_token_type = ((t_token *)(*current_token)->next->content)->token_type;
	if (check_tokens_types(current_token_type, next_token_type) == NO_MATCH)
		return (INVALID_SYNTAX);
	*current_token = (t_token_list *)(*current_token)->next;
	return (PARSING_IN_PROGRESS);
}

t_syntax_status	parser(t_token_list token_list)
{
	t_token_list	current_token;
	t_syntax_status	parser_output;

	parser_output = PARSING_IN_PROGRESS;
	while (parser_output == PARSING_IN_PROGRESS)
	{
		parser_output = check_tokens_sequence(&current_token);
	}
	if (parser_output == INVALID_SYNTAX)
		display_syntax_error(current_token);
	return (parser_output);
}
