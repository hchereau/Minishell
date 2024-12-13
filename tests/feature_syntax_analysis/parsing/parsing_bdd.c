/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bdd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:25:24 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/13 18:33:55 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	parsing_bbd_valid_syntax(void)
{
	test_simple_command_valid(WORD, END);
	//test_simple_command_valid(WORD, WORD);
}
