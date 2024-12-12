/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_interface.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hucherea <hucherea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:10:49 by hucherea          #+#    #+#             */
/*   Updated: 2024/12/12 14:31:09 by hucherea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USER_INTERFACE_H
# define USER_INTERFACE_H

// INCLUDES

# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

// DEFINES

# define MSH_PROMPT "SDF$> "
# define CTRL_D 0

// GLOBAK VARIABLES

volatile sig_atomic_t	g_signal = 0;

// PROTOTYPES

void	signal_handler(int signum);
void	received_signal(void);

#endif
