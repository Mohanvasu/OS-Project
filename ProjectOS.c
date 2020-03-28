#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int readcount=0;
int shared;
pthread_mutex_t rmutex, wmutex;
int i;
//creating pointer to the function 
//Address wise the particular reader has been passed via loop
void *writer(void *uid)
{
	pthread_mutex_lock(&wmutex);
	    
	    int add;
	    //int n = rand() % 10;
        int rid = *((int*)uid);
        //printf("%d\n",rid);
        //Writter has to write X number of times
        sleep(rand()%10);
        printf("Enter the number of times Writer can write: ");
        int nt;
        scanf("%d%*c",&nt);
        printf("\n");
        printf("Writer started \n",rid+1);
        //Block -Shared value will change 
        for(i=0;i<nt;i++)
		{
        printf("Enter the value of add to write :\n");
        scanf("%d%*c", &add);
        shared=shared+add;
        }
        
        printf("Final value of Shared variable is %d:\n", shared);
        printf("Readers left :%d\n", readcount);
        //Unlocking
        pthread_mutex_unlock(&wmutex);
}

void *reader(void *uid)
{//locking ,Redaer has priority over writer has been specified
   int nt;
   pthread_mutex_lock(&rmutex);
   //1 reader came
    readcount++;
    if(readcount==1)
	{
    pthread_mutex_lock(&wmutex);
    }
    //unlocking the read lock
    pthread_mutex_unlock(&rmutex);
    sleep(rand()%10);
    int rid = *(int*)uid;
    /*printf("R%d wait for Random time between 0ns and 10ns = %d\n", rid, n);
    sleep(n);*/
    printf("Enter the number of times Reader%d can read : ",rid+1);
    scanf("%d %*c",&nt);
    printf("\n");
    printf("Reader%d has started\n",rid+1);
    for(i=0;i<nt;i++)
	{
    printf("Reader%d ,Shared value :%d\n",rid+1,shared);
    }
    printf("Readers left :%d\n", readcount);
    printf("\n");
    pthread_mutex_lock(&rmutex);
    readcount--;
    if(readcount==0)
	{//If no readers writers can come 
    pthread_mutex_unlock(&wmutex);
    }
    pthread_mutex_unlock(&rmutex);
}


void main(){
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
        //waits for the thread specified by thread to terminate. 
        for(i=0;i<r;i++)
		{
        pthread_join(write[i],NULL);
        pthread_join(read[i],NULL);
        }
                
		for(i=r;i<w;i++)
		{
        pthread_join(write[i],NULL);
        }
        }
		else
		{{int id[w];
            for(i=0;i<w;i++)
			{
            pthread_create(&write[i], NULL, &writer, &id[i]);
            pthread_create(&read[i], NULL, &reader, &id[i]);
            }}
            int l=r-w;
            int id[l];
            for(i=w;i<r;i++)
			{
            pthread_create(&read[i], NULL, &reader, &id[i]);
            }
                //waits for the thread specified by thread to terminate. 
            for(i=0;i<w;i++)
			{
            pthread_join(write[i],NULL);
            pthread_join(read[i],NULL);
            }
            for(i=w;i<r;i++)
		   {
            pthread_join(read[i],NULL);
           }
        }
        printf("...............");
        printf("Fetching the shared variable :\n");
        sleep(2);
        printf("Final value of share variable = %d\n",shared);
        
}
