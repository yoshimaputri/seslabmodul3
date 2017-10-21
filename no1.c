#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t tid[2];

void* copy(void *arg)
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
	while(i<2)
	{
		int err=pthread_create(&(tid[i]),NULL,&copy,NULL);
	}
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
	return 0;
}
