/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:06:37 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/22 01:59:28 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

void    echo(t_env **env, char **args)
{
	int i;
	int fd;
	bool n;

	i = 1;
	n = false;
	if (ft_strcmp(args[0], "-n",  2) == 0)
	{
		while (args[0][i] && args[0][i] == 'n')
			i++;
		if (i == ft_strlen(args[0]))
			n = true;
	}
	i = 0;
	if (n)
		i = 1;
	while (args[i])
	{
		write(fd, args, ft_strlen(args));
	}
	if (!n)
		write(fd, "\n", 1);
}
