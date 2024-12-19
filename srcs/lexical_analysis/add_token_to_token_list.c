/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_token_to_token_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:20:20 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/19 15:20:32 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_list	add_token_to_token_list(t_token_list token_list,
					t_lexem token_lexem, t_token_type token_type)
{
	t_token			*token_to_add;
	t_token_list	new_node;

	token_to_add = create_token(token_lexem, token_type);
	if (token_to_add == NULL)
	{
		printf("Token_to_add = NULL\n");
		return (NULL);
	}
	new_node = ft_lstnew(token_to_add);
	if (new_node == NULL)
		return (NULL);
	ft_lstadd_back(&token_list, new_node);
	return (token_list);
}
