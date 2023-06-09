/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:06:37 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/06/09 13:03:06 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// int	ft_strncmp(char *s1, char *s2, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*p1;
// 	unsigned char	*p2;

// 	i = 0;
// 	p1 = (unsigned char *)s1;
// 	p2 = (unsigned char *)s2;
// 	if (!n)
// 		return (0);
// 	while (n-- > 0)
// 	{
// 		if (p1[i] != p2[i])
// 			return (p1[i] - p2[i]);
// 		if (p1[i] == '\0' && p2[i] == '\0')
// 			return (0);
// 		i++;
// 	}
// 	return (0);
// }

// size_t	ft_strlen(char *s)
// {
// 	size_t	count;
// 	int		i;

// 	i = 0;
// 	count = 0;
// 	while (s[i])
// 	{
// 		count += 1;
// 		i ++;
// 	}
// 	return (count);
// }

void	_echo(char **args)
{
	int		i;
	int		fd;
	bool	n;

	fd = 1;
	fd = 1;
	i = 1;
	n = false;
	if (ft_strncmp(args[0], "-n", 2) == 0)
	{
		while (args[0][i] && args[0][i] == 'n')
			i++;
		if (i == (int)ft_strlen(args[0]))
			n = true;
	}
	if (!args[0] || !args)
		return ;
	else
	{
		i = 0;
		if (n)
			i = 1;
		while (args[i])
		{
			write(fd, args[i], ft_strlen(args[i]));
			if (args[i + 1])
				write(fd, " ", 1);
			i++;
		}
	}
	if (!n)
		write(fd, "\n", 1);
	return ;
}
