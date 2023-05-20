/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:34:09 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/20 16:35:37 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

void	**env(char **envp)
{
	int	i;
	t_env	*env;
	void	*node;

	i = 0;
	env = NULL;
	while (envp[i])
	{
		node = ft_lstnew(envp[i]);
		ft_lstadd_back(&env,node);
        i++;
	}
    return (env);
}
