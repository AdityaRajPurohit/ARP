#include<stdio.h>
#include<conio.h>
static int n;
struct process
{
	int priority;
	int ServiceTime;
	int ArrivalTime;
	int processedFlag;
	char ProcessID[5];
};
process processCreation()
{
	printf("Enter Number of process you want to enter:");
	scanf("%d",&n);
	process allProcess[n];
	for(int i=0;i<n;i++)
	{
		printf("\nEnter Process ID:");
		scanf("%s",&allProcess[i].ProcessID);
		printf("Enter Process Arival time:");
		scanf("%d",&allProcess[i].ArrivalTime);
		printf("Enter Process Service Time:");
		scanf("%d",&allProcess[i].ServiceTime);
		allProcess[i].priority=0;
		allProcess[i].processedFlag=0;
	}
	return sortProcess(allProcess);
}
process sortProcess(process p[])
{
	int a;
	for(i=0;i<n;++i)
    {
        for(j=i+1;j<n;++j)
        {
            if(P[i].ArrivalTime>P[j].ArrivalTime) 
            {
                a=P[i].ArrivalTime;
                P[i].ArrivalTime=P[j].ArrivalTime;
                P[j].ArrivalTime=a;
            }
        }
    }
    return p;
}
void processor(process readyQueue[])
{
	process executing[n];
	for(int i=readyQueue[0].ArrivalTime;1;i++)
	{
		execution[i]=readyQueue[i];
			
	}
}
int main()
{

	printf("~~~~~~~~~~~~~~Welcome To Process Scheduler~~~~~~~~~~~~~~~~\a\n");
	printf("\n\n~~~~~~~~~~~~~~~~~~Priority Scheduling~~~~~~~~~~~~~~~~~~~~~~\a\n");
	getch();
	processor(processCreation());	
}
