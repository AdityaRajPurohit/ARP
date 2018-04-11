#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
static int n;
struct process
{
	int priority;
	int ServiceTime;
	int ArrivalTime;
	int processedFlag;
	char ProcessID[5];
	process *link;
}*start=NULL;
void processor()
{
	process *p=start,readyQueue[n];
	readyQueue[0]=*p;
	for(int i=p->ArrivalTime,k=0;i<10;i++)
	{
		readyQueue[k].processedFlag=1;
		readyQueue[k].ServiceTime--;
		readyQueue[k].priority++;
		p=p->link;
		for(int j=i;j!=(p->ArrivalTime);j++,i=j+1);
		if(i==p->ArrivalTime)
		{
			if(readyQueue[k].ServiceTime==0)
			{
				printf("%s is executed with time %d",readyQueue[k].ProcessID,i);
				readyQueue[k]=*p;
			}
			else
			{
				if((p->processedFlag==0)||(p->priority>readyQueue[k].priority))
				{
					readyQueue[k+1]=readyQueue[k];
					readyQueue[k]=*p;
					k++;
				}
				else
				{
					readyQueue[k+1]=*p;
					k++;
				}
				
			}
			
		}
		
		
		
	}
	
}

void swap(process *a,process *b)
{
	printf("Swap");
    process *temp = a;
    a=b;
    b=temp;
}
void sortProcess()
{
    process *l=NULL,*p;
	printf("Sort");
    if(start==NULL)
        return ;
    else
    {
    	int swaped;
    	do
    	{
    		printf("Sort running");
    		swaped=0;	
    		p=start;
 			
        	while(p->link!=NULL)
        	{
        	    if(p->ArrivalTime> p->link->ArrivalTime)
       	    	{ 
       	    	    swap(p,p->link);
       	    	    swaped=1;
       	   	    }
        	    p=p->link;
        	}
        	l=p;
		}while(swaped);
        
    }
}
void processCreation()
{
	printf("Enter Number of process:");
	scanf("%d",&n);
	process *newProcess;
	for(int i=0;i<n;i++)
	{
		newProcess=(struct process*)malloc(sizeof(struct process));
		
		printf("\nNow Enter Process ID:");
		fflush(stdin);
		scanf(" % s ",& newProcess -> ProcessID);
		printf("\nNow Enter process arival time:");
		fflush(stdin);
		scanf(" % d ", & newProcess -> ArrivalTime);
		printf("\nNow Enter process burst/service Time:");
		fflush(stdin);
		scanf(" % d ", & newProcess  -> ServiceTime);
		newProcess->priority=0;
		newProcess->processedFlag=0;
		//newProcess->link=NULL;
		if(start==NULL)
		{
			start=newProcess;
			start->link=NULL;	
		}	
		else
		{
			process *p=start;
			while(p!=NULL)
			{
				p=p->link;
			}
			p=newProcess;
			p->link=NULL;
		}
	}
	printf("Calling sort");
	sortProcess();
	printf("calling processor");
	processor();
}

int  main()
{
	printf("******************Welcome To Process Scheduler******************\a\n");
	printf("\n\n******************Priority Scheduling******************\a\n");
	getch();
	processCreation();
	process *p=start;
	while(p!=NULL)
	{
		printf("%s->",p->ProcessID);
		p=p->link;
	}	
	
}
