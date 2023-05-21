/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:57:47 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/21 15:58:53 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char			*p;
	unsigned int	j;
	size_t			k;

	j = 0;
	k = ft_strlen(s) - start + 1;
	if (len < (size_t)(ft_strlen(s) - start))
		k = len + 1;
	if (start < (size_t)ft_strlen(s) && *s != 0)
	{
		p = malloc(k * sizeof(char));
		if (!p)
			return (NULL);
		while ((s + start)[j] && j < len)
		{
			p[j] = (s + start)[j];
			j++;
		}
		p[j] = '\0';
		return (p);
	}
    return (NULL);
}