/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:54:24 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/24 14:54:36 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_token(void *data)
{
	t_token *	token_to_delete = (t_token *)data;

	free(token_to_delete->token_lexem);
	free(token_to_delete);
}
