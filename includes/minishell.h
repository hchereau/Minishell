/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchobert <tchobert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:11:56 by hucherea          #+#    #+#             */
/*   Updated: 2024/12/11 11:43:22 by tchobert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

// INCLUDES

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

// DEFINES

# define MSH_LOOP 1
# define MSH_PROMPT "SDF$> "
# define CTRL_D 0

// PROTOTYPES

int		exit_shell_routine(void);
char	*prompt_get_user_input(void);

#endif
