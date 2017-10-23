#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t tid[2];
int status=0;

void* copy1()
{
	status=0;
	pid_t child; child=fork();
	if(child==0)
	{
	char *argv[]={"cp", "baca.txt","/home/yoshi/seslabmodul3/salin1.txt",NULL};
	execv("/bin/cp",argv);
	}
	status=1;
}

void* copy2()
{
	while(status!=1) {}
	pid_t child; child=fork();
	if(child==0)
	{
	char *argc[]={"cp", "/home/yoshi/seslabmodul3/salin1.txt", "/home/yoshi/seslabmodul3/salin2.txt",NULL};
	execv("/bin/cp", argc);
	}
}

int main()
{
	pthread_create(&(tid[0]),NULL,&copy1,NULL);
	pthread_create(&(tid[1]),NULL,&copy2,NULL);

	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	return 0;
}
