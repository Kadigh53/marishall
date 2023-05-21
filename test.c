#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd = open("testin.txt", O_RDWR | O_CREAT, 0644);
	dup2(fd, STDOUT_FILENO);
	printf("hellhmad d\n");
}
// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>

// int main() {
//     int fileDescriptor = open("output.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
//     if (fileDescriptor == -1) {
//         perror("open");
//         return 1;
//     }
//     if (dup2(fileDescriptor, STDOUT_FILENO) == -1) {
//         perror("dup2");
//         return 1;
//     }
//     printf("This will be written to the file.\n");
//     close(fileDescriptor);
    
//     return 0;
// }