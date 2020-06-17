#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h> 
#include<unistd.h>
#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"
#include "x86.h"


int main(int argc, char *argv[]) {
	char temp[128], *s = argv[4];
	int offset, len;
	int fd = open(argv[1], O_CREAT | O_RDONLY);
	
	offset = atoi(argv[2]);
	len = atoi(argv[3]);

	if(argc != 5)
		return 0;
	lseek(fd, offset, SEEK_CUR);
	int i = read(fd, temp, len);
	if(i != 0){
		if(strcmp(s, temp) == 0)
			printf("Same\n");
		else
			printf("Not same\n");
	}	
	else
		printf("Not found\n");
	close(fd);
	exit(0);
}

