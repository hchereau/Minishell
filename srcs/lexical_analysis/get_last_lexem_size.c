/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_lexem_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:42:08 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/24 14:42:18 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	get_last_lexem_size(t_token_list token_list)
{
	const t_token_list	last_node = (t_token_list)ft_lstlast(token_list);
	const t_token		*last_token;

	if (last_node == NULL || last_node->content == NULL)
		return (0);
	last_token = (const t_token *)last_node->content;
	if (last_token->token_lexem == NULL)
		return (0);
	return (ft_strlen(last_token->token_lexem));
}
