/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:06:02 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/17 16:06:14 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	delete_token_list(t_token_list **list_to_delete, void (*del_funct)
			(t_token **))
{
	t_token	*list_current_token;
	t_token	*list_next_token;

	list_current_token = (*list_to_delete)->token_list_first_token;
	while (list_current_token != NULL)
	{
		list_next_token = list_current_token->next_token;
		if (del_funct != NULL)
		{
			del_funct(&list_current_token);
		}
		list_current_token = list_next_token;
	}
	ft_bzero(*list_to_delete, sizeof(t_token_list));
	*list_to_delete = NULL;
}
