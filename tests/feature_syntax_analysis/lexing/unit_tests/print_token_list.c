/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_token_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:43:23 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/17 15:43:35 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	print_token_list(t_token_list token_list)
{
	const char	*enum_names[] = {"TOKEN_LIST_START", "TOKEN_LIST_END","WORD", "PIPE", "INPUT_REDIR_OPERATOR", "OUTPUT_REDIR_OPERATOR", "APPEND_OPERATOR", "HEREDOC OPERATOR", "UNKNOWN OPERATOR"};
	t_token	*current_token = token_list.token_list_first_token;

	while(current_token != NULL)
	{
		printf("Content = %s\n", current_token->token_content);
		printf("Token type = %s\n", enum_names[current_token->token_type]);
		printf("\n");
		current_token = current_token->next_token;
	}
}
