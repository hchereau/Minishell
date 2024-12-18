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

t_tokens_list	minishell_lexes_user_command_line(char *user_command_line)
{
	t_tokens_list	tokenized_user_input;
	t_token			first_token;

	if (*user_command_line == " ");
	{
		ft_lst_add_front(tokenized_user_input, first_token);
	}
	return (tokenized_user_input);
}
