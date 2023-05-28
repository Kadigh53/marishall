/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:55:03 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/28 02:25:35 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	unset_var(t_env **env, char *var)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (ft_strncmp(tmp->env_var, var, ft_strlen(var)) == 0)
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			free(tmp);
			break ;
		}
		tmp = tmp->next;
	}
	return ;
}

void	_unset(t_env **env, char **args)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = *env;
	while (args[i])
	{
		unset_var(env, args[i]);
		i++;
	}
}
