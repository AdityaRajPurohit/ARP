/*
Design a scheduler that uses a preemptive priority scheduling algorithm based on 
dynamically changing priority.Larger number for priority indicates higher priority. 
Assume that the following processes with arrival time and service time wants to execute 
(for reference): 
ProcessID         Arrival Time     Service Time 
P1                    0                 4 
P2                    1                 1 
P3                    2                 2 
P4                    3                 1 
When the process starts execution (i.e. CPU assigned), priority for that process changes 
at the rate of m=1.When the process waits for CPU in the ready queue (but not yet started 
execution), its priority changes at a rate n=2. All the processes are initially assigned 
priority value of 0 when they enter ready queue for the first time . The time slice for 
each process is q = 1. When two processes want to join ready queue simultaneously,
the process which has not executed recently is given priority. Calculate the average 
waiting time for each process.The program must be generic i.e. number of processes, 
their burst time and arrival time must be entered by user. 
*/

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
}*front=NULL,*rear=NULL;
void processCreation()
{
	printf("Enter Number of process you want to enter:");
	scanf("%d",&n);
	process *newProcess;
	for(int i=0;i<n;i++)
	{
		newProcess=(*process)malloc(sizeof(process));
		
		printf("\nEnter Process ID:");
		scanf("%s",&newProcess->ProcessID);
		printf("Enter Process Arival time:");
		scanf("%d",&newProcess->ArrivalTime);
		printf("Enter Process Service Time:");
		scanf("%d",&newProcess->ServiceTime);
		newProcess->priority=0;
		newProcess->processedFlag=0;
		newProcess->link=NULL;
		if(front==NULL)
			rear=front=newProcess;
		else
		{
			rear->link=newProcess;
			rear=newProcess;
		}
	}
	sortProcess();
}
void sortProcess()
{
    struct Node *l=NULL,*p;

    if(front==NULL)
        return front;
    else
    {
    	do
    	{
    		swaped=0;
    		p=front;
 
        	while(p->link!=NULL)
        	{
        	    if(p->ArrivalTime> p->link->ArrivalTime)
       	    	{ 
       	    	    swap(p,p->link);
       	    	    swaped=1;
       	   	    }
        	    p=p->next;
        	}
        	l=p;
		}while(swaped)
        
    }
}
void swap(process *a,process *b)
{
    process *temp = a;
    a=b;
    b=temp;
}
void processor()
{
	process *p=front;
	for(int i=p->ArrivalTime;1;i++)
	{
		
			
	}
}
int main()
{

	printf("~~~~~~~~~~~~~~Welcome To Process Scheduler~~~~~~~~~~~~~~~~\a\n");
	printf("\n\n~~~~~~~~~~~~~~~~~~Priority Scheduling~~~~~~~~~~~~~~~~~~~~~~\a\n");
	getch();
	processor(processCreation());	
}
