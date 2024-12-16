/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_token_list_from_user_input.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:24:01 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/14 19:24:11 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_token_list	build_token_list_from_user_input(char *user_input)
{
	(void)user_input;
	t_token_list	tokenized_user_input;

	tokenized_user_input.token_list_first_token = NULL;
	return (tokenized_user_input);
}
