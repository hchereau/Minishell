/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_to_token_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:31:01 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/16 17:31:11 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token_add_status	initialize_token_list(t_token_list *token_list,
								t_token *token_to_add)
{
	token_list->token_list_first_token = token_to_add;
	token_list->token_list_last_token = token_to_add;
	return (ADD_SUCCESS);
}

static t_token_add_status	add_token(t_token_list *token_list,
								t_token *token_to_add)
{
	token_list->token_list_last_token->next_token = token_to_add;
	token_to_add->previous_token = token_list->token_list_last_token;
	token_list->token_list_last_token = token_to_add;
	return (ADD_SUCCESS);
}

t_token_add_status	add_token_to_token_list(t_token_list *token_list,
						t_token *token_to_add)
{
	if (token_list == NULL || token_to_add == NULL)
		return (ADD_FAILURE);
	if (token_list->token_list_first_token == NULL)
	{
		return (initialize_token_list(token_list, token_to_add));
	}
	return (add_token(token_list, token_to_add));
}
