/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 14:47:16 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/19 14:47:31 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_token(char *lexem, t_token_type token_type)
{
	t_token	*new_token;

	new_token = (t_token *)malloc(sizeof(t_token));
	if (new_token == NULL)
		ft_dprintf(STDERR_FILENO, "New_token NULL\n");
	if (new_token != NULL)
	{
		if (lexem != NULL)
			new_token->token_lexem = ft_strdup(lexem);
		else
			new_token->token_lexem = NULL;
		new_token->token_type = token_type;
	}
	return (new_token);
}
