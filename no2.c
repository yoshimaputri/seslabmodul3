#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t tid[2];

void* prime(void *arg)
{
	pthread_t id = pthread_self();
	if(pthread_equal(id,tid[0]))
	{
	}
	else if(pthread_equal(id,tid[1]))
	{
	}
	return NULL;
}

int main()
{
	int i; int err;
	while(i<2)
	{
		err=pthread_create(&(tid[i]),NULL,&prime,NULL);
		if(err!=0) printf("can't create thread : [%s]",strerror(err));
		else printf("create thread success");
		i++;
	}
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	return 0;
}
