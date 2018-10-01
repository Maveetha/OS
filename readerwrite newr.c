#include<semaphore.h>
#include<stdio.h>
#include<pthread.h>

void *reader(void *);
void *writer(void *);

int readcount=0,writecount=0,sh_var=5,bsize[5];
sem_t x,y,z,rsem,wsem;
pthread_t r[3],w[2];

void *reader(void *i)
{
printf("\n-------------------------");
printf("\n\n reader-%d is reading",i);

sem_wait(&z);
sem_wait(&rsem);
sem_wait(&x);
readcount++;
if(readcount==1)
    sem_wait(&wsem);
sem_post(&x);
sem_post(&rsem);
sem_post(&z);
printf("\nupdated value : %d",sh_var);
sem_wait(&x);
readcount--;
if(readcount==0)
    sem_post(&wsem);
sem_post(&x);
}

void *writer(void *i)
{
printf("\n\n writer-%d is writing",i);
sem_wait(&y);
writecount++;
if(writecount==1)
sem_wait(&rsem);
sem_post(&y);
sem_wait(&wsem);

sh_var=sh_var+5;
sem_post(&wsem);
sem_wait(&y);
writecount--;
if(writecount==0)
sem_post(&rsem);
sem_post(&y);
}

int main()
{
sem_init(&x,0,1);
sem_init(&wsem,0,1);
sem_init(&y,0,1);
sem_init(&z,0,1);
sem_init(&rsem,0,1);

pthread_create(&r[0],NULL,(void *)reader,(void *)0);
pthread_create(&w[0],NULL,(void *)writer,(void *)0);
pthread_create(&r[1],NULL,(void *)reader,(void *)1);
pthread_create(&r[2],NULL,(void *)reader,(void *)2);
pthread_create(&r[3],NULL,(void *)reader,(void *)3);
pthread_create(&w[1],NULL,(void *)writer,(void *)3);
pthread_create(&r[4],NULL,(void *)reader,(void *)4);

pthread_join(r[0],NULL);
pthread_join(w[0],NULL);
pthread_join(r[1],NULL);
pthread_join(r[2],NULL);
pthread_join(r[3],NULL);
pthread_join(w[1],NULL);
pthread_join(r[4],NULL);

return(0);
}

 /*
Output:-

student@mmcoe-desktop:~$ gcc rw1.c -lpthread
student@mmcoe-desktop:~$ ./a.out
-------------------------
 reader-0 is reading
updated value : 5

 writer-0 is writing
-------------------------
 reader-1 is reading
updated value : 10
-------------------------
 reader-2 is reading
updated value : 10
-------------------------
 reader-3 is reading
updated value : 10
*/