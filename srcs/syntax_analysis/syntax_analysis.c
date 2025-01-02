/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_analysis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:43:13 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/30 16:43:24 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_syntax_status	syntaxic_analysis(const t_token_list token_list)
{
	t_syntax_status	parser_output;

	parser_output = parser(token_list);
	return (parser_output);
}
