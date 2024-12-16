/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:29:07 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/16 16:29:22 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token	*initialize_token_content(t_token *new_token,
					char *new_token_content, t_token_type new_token_type)
{
	new_token->token_content = ft_strdup(new_token_content);
	if (new_token->token_content == NULL)
	{
		free(new_token);
		return (NULL);
	}
	new_token->token_type = new_token_type;
	new_token->previous_token = NULL;
	new_token->next_token = NULL;
	return (new_token);
}

t_token	*create_token(char *new_token_content, t_token_type new_token_type)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (new_token == NULL)
		return (NULL);
	return (initialize_token_content(new_token, new_token_content,
					new_token_type));
}
