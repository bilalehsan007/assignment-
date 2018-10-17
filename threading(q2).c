#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int chunk=100; //chunk size to give each thread
int arr[1000];
int sum=0;

void *add (void *arg)
{
    int s = (int) arg;
    int e = s + chunk;

    fot(int i=s;i<e;i++)
       sum=sum+arr[i];

    return ((void*)sum);
}

void main()
{
    for(int i=0;i<1000;i++)
        arr[i]=i;
    
    int s0,s1,s2,s3,s4,s5,s6,s7,s8,s9;
    pthread_t thread_0,thread_1,thread_2,thread_3,thread_4,thread_5,thread_6,thread_7,thread_8,thread_9;

    pthread_create (&thread_0, NULL, add, (void*)(0*chunk));
    pthread_create (&thread_1, NULL, add, (void*)(1*chunk));
    pthread_create (&thread_2, NULL, add, (void*)(2*chunk));
    pthread_create (&thread_3, NULL, add, (void*)(3*chunk));
    pthread_create (&thread_4, NULL, add, (void*)(4*chunk));
    pthread_create (&thread_5, NULL, add, (void*)(5*chunk));
    pthread_create (&thread_6, NULL, add, (void*)(6*chunk));
    pthread_create (&thread_7, NULL, add, (void*)(7*chunk));
    pthread_create (&thread_8, NULL, add, (void*)(8*chunk));
    pthread_create (&thread_9, NULL, add, (void*)(9*chunk));

    pthread_join (thread_0, (void**)&s0);
    pthread_join (thread_1, (void**)&s1);
    pthread_join (thread_2, (void**)&s2);
    pthread_join (thread_3, (void**)&s3);
    pthread_join (thread_4, (void**)&s4);
    pthread_join (thread_5, (void**)&s5);
    pthread_join (thread_6, (void**)&s6);
    pthread_join (thread_7, (void**)&s7);
    pthread_join (thread_8, (void**)&s8);
    pthread_join (thread_9, (void**)&s9);

    sum=s0+s1+s2+s3+s4+s5+s6+s7+s8+s9;

    printf("Sum of total threads is : " sum);


}