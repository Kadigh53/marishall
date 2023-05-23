#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdlib.h>
int main(int ac, char **argv)
{
	// printf("%d",access("/home/kadigh/Desktop/projects/minishell/execution", F_OK ));
	char	*buff= malloc(1024);
	// buff = argv[1];
	getcwd(buff,62);
	printf("%s\n",buff);
	int a = chdir(buff);
	printf("%d\n",a);
	getcwd(buff,62);
	printf("\n>>>\n%s\n",buff);
}