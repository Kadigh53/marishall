/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:32:46 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/11 14:38:20 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pipe(int pipefds[])
{
	int	r;

	r = pipe(pipefds);
	if (r == -1)
	{
		write(2, "pipe fail\n", 10);
		exit(1);
	}
}