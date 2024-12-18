/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexing_bdd_empty_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 17:58:32 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/14 19:28:13 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

// static int		check_lexing_result(t_token_list lexer_output)
// {
// 	return (SUCCESS);
// }

void	test_input_empty_string(void)
{
	return ;
}
/*

Test pour le lexer -> ici la fonction principale du lexer = build_token_list_from_user_input.

BUILD_TOKEN_LIST_FROM_USER_INPUT :

INPUT : une chaine de caracteres, correspondant a la ligne de commande saisie
		par l'utilisateur et envoyee au prompt.

OUTPUT : une liste de tokens (t_token_list), corrspondant a l'entree de l'utilisateur
		decoupee en lexems.

GOAL : decouper et ordonner l'entree de l'utilisateur en lexems, afin de preter un
		sens a chaque entite qu'elle contient, pour quele shell puisse operer.

PROCESS :

*/
