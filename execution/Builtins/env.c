/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 16:05:47 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/22 12:30:06 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

void	_env(t_env **env)
{
	int	i;
	int fd;
	t_env *tmp;

	i = 0;
	tmp = *env;
	while (tmp)
	{
		if (!tmp->env_or_export)
		{
			write(fd,tmp->env_var,ft_strlen(tmp->env_var));
			write(1,"\n",1);
		}
		tmp = tmp->next;
	}
}
