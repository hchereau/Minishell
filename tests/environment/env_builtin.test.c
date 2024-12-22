/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_builtin.test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linux <linux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 13:03:06 by linux             #+#    #+#             */
/*   Updated: 2024/12/22 16:31:29 by linux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "unity.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*captured_output = NULL;
size_t	captured_size = 0;


void capture_start()
{
    fflush(stdout);
    if (captured_output)
    {
        free(captured_output);
        captured_output = NULL;
    }
    FILE *temp = open_memstream(&captured_output, &captured_size);
    if (!temp)
    {
        perror("open_memstream");
        exit(EXIT_FAILURE);
    }
    setbuf(stdout, NULL);
    stdout = temp;
}

void capture_end()
{
    fflush(stdout);
    fclose(stdout); // Remet stdout à sa valeur initiale
    stdout = fdopen(STDOUT_FILENO, "w");
}

// Test de la fonction env_builtin
void test_env_builtin_should_display_environment_variables()
{
    // Given
    char *mock_envp[] = {
        "PATH=/usr/bin:/bin",
        "HOME=/home/user",
        "SHELL=/bin/bash",
        NULL
    };

    // When
    capture_start();
    env_builtin(mock_envp);
    capture_end();

    // Then
    const char *expected_output =
        "PATH=/usr/bin:/bin\n"
        "HOME=/home/user\n"
        "SHELL=/bin/bash\n";

    TEST_ASSERT_EQUAL_STRING(expected_output, captured_output);
}


void test_stdout_capture()
{
    capture_start();
    printf("Hello, world!\n");
    capture_end();

    const char *expected_output = "Hello, world!\n";
    TEST_ASSERT_EQUAL_STRING(expected_output, captured_output);
}

