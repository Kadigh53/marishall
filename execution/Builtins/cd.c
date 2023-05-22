/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:05:47 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/05/22 21:48:07 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/header.h"

// char	*parse_arg()
// {
	
// }


// char	*cd_home(t_env **env)
// {
// 	t_env	*tmp;

// 	tmp = *env;
// 	while (tmp)
// 	{
// 		if (!ft_strncmp(tmp->env_var, "HOME=", 5))
// 			return (tmp->env_var);
// 		tmp = tmp->next;
// 	}
// 	// what if there is no home env_var
// 	return (NULL);
// }

// void	cd_with_abspath(char *arg)
// {
// 	if (chdir(arg) == -1)
// 		error("ERROR:chdir() failed\n");
// }

// void	cd_fromcwd(char *arg)
// {
// 	if (arg[])
// }

// void	_cd(t_env **env, char *arg)
// {
// 	parse_arg(arg);
// 	if (!arg || (arg[0] == '~'))
// 	{
// 		if (!cd_home(env))
// 			write(2, "cd: HOME not set\n",17);
// 	}	
// 	cd_with_abspath(arg);
// 	cd_fromcwd();
// }
#include <stdlib.h>
int main(int ac, char **argv)
{
	char	*buff= malloc(1024);
	buff = argv[1];
	getcwd(buff,62);
	printf("%s\n",buff);
	int a = chdir(buff);
	printf("%d\n",a);
	getcwd(buff,62);
	printf("\n>>>\n%s\n",buff);
}