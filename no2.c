#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t tid[100]; int N,T,group,a=0;

void* prime()
{
	pthread_t id = pthread_self();
	printf("a=%d\n", a);
	group = N/T; //printf("group=%d", group);
	if(pthread_equal(id,tid[0]))
	{
		for(int x=2; x<=group; x++){
			int cek=1;
			for(int j=2;j<x;j++){
				if(x%j==0) cek=0;
			}
			if(cek==1) printf("%d\n", x);
		}
	}
	else if(pthread_equal(id,tid[!0]))
	{
		int awal=(group*a)+1;
		int akhir=group*(a+1);
		for(int x=awal;x<=akhir;x++){
			int cek=1;
			for(int j=awal;j<=x;j++){
				if(x%j==0) cek=0;
			}
			if(cek==1) printf("%d\n", x);
		}
	}
	a++;
	return NULL;
}

int main()
{
	int i=0;
	printf("Masukkan N batas bilangan dan T jumlah thread : ");
	scanf("%d %d", &N, &T);
	while(i<T)
	{
		pthread_create(&(tid[i]),NULL,&prime,NULL);
		i++;
	}
	i=0;
	while(i<T){
		pthread_join(tid[i],NULL);
		i++;
	}
	return 0;
}
