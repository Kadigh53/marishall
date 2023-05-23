/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:34:09 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/24 00:30:39 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/header.h"

t_env	**env(char **envp)
{
	int	i;
	t_env	*env;
	t_env	*node;

	i = 0;
	env = NULL;
	while (envp[i])
	{
		node = ft_lstnew(envp[i]);
		node->env_or_export = 0;
		ft_lstadd_back(&env,node);
        i++;
	}
    return (env);
}
