/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 17:55:03 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/22 12:29:37 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void    search_var(t_env **env, char *var)
{
	t_env	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (ft_strcmp(tmp->env_var, var, ft_strlen(var)) == 0)
		{}
		tmp = tmp->next;
	}
	return ;
}

void	_unset(t_env **env, char **args)
{
	t_env	*tmp;
	int     i;

	i = 0;
	tmp = *env;
	while (args[i])
	{
		search_var(env, args[i]);
		i++;
	}
}
