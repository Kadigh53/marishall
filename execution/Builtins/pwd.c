/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:07:07 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/22 12:30:16 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void    _pwd()
{
	int fd;
	char *cwd;

	cwd = ft_malloc(1024);
	if (getcwd(cwd,1024))
	{
		write(fd,cwd,ft_strlen(cwd));
		write(fd,"\n",1);
	}
	else
		error("ERROR:gtcwd failed\n");
}
// /Users/aaoutem-/Desktop/projects/minishell/execution/Builtins