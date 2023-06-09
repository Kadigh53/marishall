/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:07:07 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/09 19:45:56 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	_pwd(void)
{
	int		fd;
	char	*cwd;

	fd = 1;
	cwd = ft_malloc(1024);
	if (getcwd(cwd, 1024))
	{
		write(fd, cwd, ft_strlen(cwd));
		write(fd, "\n", 1);
	}
	else
		error("ERROR:gtcwd failed\n");
	free(cwd);
}
