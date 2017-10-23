#include <string.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pthread_t tid[100]; int N,T,group;

void* prime(int N,int T)
{
	pthread_t id = pthread_self();
	int a;
	while(a<T){
	group = N/T;
	if(pthread_equal(id,tid[0]))
	{	
		for(int x=2; x<=group; x++){
			int cek=1;
			for(int j=3;j<=group;j++){
				if(x%j==0) cek=0;
			}
			if(cek==1) printf("%d ", x);
		}
	}
	else if(pthread_equal(id,tid[!0]))
	{
		int awal=(group*a)+1;
		int akhir=group*(a+1);
		for(int x=awal;x<=akhir;x++){
			int cek=1;
			for(int j=awal+1;j<=akhir;j++){
				if(x%j==0) cek=0;
			}
			if(cek==1) printf("%d ", x);
		}
	}
	}
	return NULL;
}

int main()
{
	int i; int err;
	printf("Masukkan N batas bilangan dan T jumlah thread : ");
	scanf("%d %d", &N, &T);
	while(i<T)
	{
		err=pthread_create(&(tid[i]),NULL,prime(N,T),NULL);
		if(err!=0) printf("can't create thread : [%s]",strerror(err));
		else printf("create thread success");
		i++;
	}
	i=0;
	while(i<T){
		pthread_join(tid[i],NULL);
		i++;
	}
	return 0;
}
