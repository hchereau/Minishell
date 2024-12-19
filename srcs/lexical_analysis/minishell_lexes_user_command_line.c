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

t_token_list	minishell_lexes_user_command_line(const char *user_command_line)
{
	(void)user_command_line;
	t_token_list	tokenized_command_line;

	tokenized_command_line = NULL;
	tokenized_command_line = add_token_to_token_list(tokenized_command_line, NULL,
		TOKEN_LIST_START);
	tokenized_command_line = add_token_to_token_list(tokenized_command_line, NULL,
		TOKEN_LIST_END);
	return (tokenized_command_line);
}

// if (add_token_to_token_list(tokenized_command_line, NULL, TOKEN_LIST_START)
// 			== NULL)
// 			return (NULL);
// 	if (add_token_to_token_list(tokenized_command_line, NULL, TOKEN_LIST_END)
// 			== NULL)
// 			return (NULL);
