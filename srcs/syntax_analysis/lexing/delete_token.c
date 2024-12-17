/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 21:22:09 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/16 21:22:20 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	erase_token_content(char **content_to_delete)
{
	ft_bzero(*content_to_delete, ft_strlen(*content_to_delete));
	free(*content_to_delete);
	*content_to_delete = NULL;
}

void	delete_token(t_token **token_to_delete)
{
	erase_token_content(&(*token_to_delete)->token_content);
	(*token_to_delete)->previous_token = NULL;
	(*token_to_delete)->next_token = NULL;
	free(*token_to_delete);
	*token_to_delete = NULL;
}
