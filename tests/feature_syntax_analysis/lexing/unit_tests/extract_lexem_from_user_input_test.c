/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_lexem_from_user_input_test.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:16:15 by tchobert          #+#    #+#             */
/*   Updated: 2024/12/17 18:16:25 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

void	test_extract_lexem_from_user_input(void)
{
	printf("Testing lexing: extract_lexem_from_user_input\n");
	
	//ARRANGE

	char	*test = "Cut a lexem";
	char	*test_2 = "";
	t_lexem	lexem_test; //word "lexem"
	t_lexem	lexem_test_2; //for test_2

	//ACT

	lexem_test = extract_lexem_from_user_input(test + 6, test + 11);
	lexem_test_2 = extract_lexem_from_user_input(test_2, test_2 + 1);

	//ASSERT

	printf("%s\n", lexem_test);
	TEST_ASSERT_EQUAL(0, ft_strcmp("lexem", lexem_test));
	TEST_ASSERT_EQUAL('\0', *lexem_test_2);
}
/*

FONCTION "EXTRACT_LEXEM_FROM_USER_INPUT"

BUT: Extraire un lexem (une sequence de caracteres ayant un sens pour le shell),
utilisable pour construire un token.

INPUT: Deux pointeurs, les limites du lexem a extraire
OUTPUT: Un pointeur vers une chaine de caracteres contenant le lexem

PROCESS:

A/ Verifie si le lexem n'est pas un caractere vide, si oui dup une chaine vide,
la retourne

B/ Definit la taille du lexem a extraire -> FONCTION : "GET_LEXEM_SIZE"

C/ Alloue l'espace necessaire pour recevoir ce lexem -> MALLOC

D/ Copie le lexem dans son nouvel emplacement -> FT_STRNCPY

E/ Retourne le lexem extrait

*/


/*

TOUT CE QUI EST ENTRE SEPARATEURS = UN LEXEM.\

DEFINIR SON SENS APRES.

*/
