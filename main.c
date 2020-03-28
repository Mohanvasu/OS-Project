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
        if(r<0 || w<0)
		{
        printf("Invalid Values !!!\n");
        return;
        }
		else if(r==0)
		{
        printf("Multithreading for writers !!!!!!!!!!\n");
        }
		else if(w==0)
		{
        printf("Multithreading for readers only !!!!!!!!!!\n");
        }
		else
		{
        printf("Multithreading for reader as well as writer !!!!!!!!!!!:\n");
        }
   //Varying inputs has been taken to consider the testcases 
   //When the number of total reader and writers are equal 
        if(r==w)
		{
        int id[r];
        for(i=0; i<r; i++)
		{
        id[i]=i;
        pthread_create(&write[i],NULL,&writer,&id[i]);
        pthread_create(&read[i],NULL,&reader,&id[i]);
        }
        for(i=0;i<r;i++)
		{
            pthread_join(write[i],NULL);
            pthread_join(read[i],NULL);
        }
        }
        
        //When the number of writer is more than the number of reader
		else if(w>r)
		{{int id[r];
        for(i=0;i<r;i++)
		{
        id[i]=i;
        pthread_create(&write[i],NULL,&writer,&id[i]);
        pthread_create(&read[i],NULL,&reader,&id[i]);
        }}
        int l=w-r;
        int id[l];
        for(i=r;i<w;i++)
		{
        pthread_create(&write[i],NULL,&writer,&id[i]);
        }
        
}
