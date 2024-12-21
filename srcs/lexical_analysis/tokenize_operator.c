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

t_token_list	tokenize_operator(const char operator,
					t_token_list tokenized_command_line)
{
	t_token_type	token_type;

	if (is_space(operator) != true)
	{
		token_type = search_operator_in_lexer_dictionary(operator);
		tokenized_command_line = add_token_to_token_list(tokenized_command_line, NULL,
															token_type);
	}
	return (tokenized_command_line);
}
