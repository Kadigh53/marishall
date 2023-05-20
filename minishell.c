/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 21:35:54 by yel-hadd          #+#    #+#             */
/*   Updated: 2023/05/20 17:06:38 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int ac, char **av, char **env)
{
    extern char **environ;
    char *command;

    if (ac != 1)
        error("ERROR:Invalide number of arguments\n");
    // set_env(env);
    while (1)
    {
        command = readline("marishall$ ");
        if (!command)
            continue;
        add_history(command);
        free(command);
    }
    return (0);
}
