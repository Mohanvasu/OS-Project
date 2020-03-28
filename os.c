#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int readcount=0;
int shared;
pthread_mutex_t rmutex, wmutex;
int i;
void main()
{
	int r,w;
        printf("Enter the shared variable value: ");
        scanf("%d%*c",&shared);
        printf("\n\n");
        printf("Provide the total number of reader :\n");
        scanf("%d%*c",&r);
        if(r<0 || w<0)
        {
        	printf("Invalid Entries:\n");
        	return;
		}
        
        /*for(i=0; i<rn; i++){
                printf("R%d\n", i);
        }*/
        printf("\n\n");
        printf("Provide the total number of writer :\n");
        scanf("%d%*c", &w);
        /*for(i=0; i<wn; i++){
                printf("W%d\n", i);
        }*/
        //declaring the threads
        pthread_t read[r], write[w];
        printf("\n\n");
        //initialising the thread
        pthread_mutex_init(&rmutex,NULL);
        //testcases to perform for 
        pthread_mutex_init(&wmutex,NULL);
        
}
