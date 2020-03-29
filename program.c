#include<stdio.h>
 typedef struct 
{
	int processID;
	int burstTime;
	int arrivalTime;
}Process;
void Que1();
void Que2();
void findWaitingTime(Process proc[], int m,int wt[]) 
{ 
    int rt[m]; 
    for (int i = 0; i < m; i++) 
        rt[i] = proc[i].burstTime; 
  
    int complete = 0, t = 0, minm = 100000; 
    int shortest = 0, finish_time,j; 
    bool check = false; 
  
    //  It Process until all the processes get 
    // completed 
    while (complete != m) { 
  
        // Find  the process with minimum 
        // the remaining time among the 
        // processes that arrives till  
        // the current time` 
        for ( j = 0; j < m; j++) { 
            if ((proc[j].arrivalTime <= t) && 
            (rt[j] < minm) && rt[j] > 0) { 
                minm = rt[j]; 
                shortest = j; 
                check = true; 
            } 
        } 
  
        if (check == false) { 
            t++; 
            continue; 
        } 
        rt[shortest]--;
        minm = rt[shortest]; 
        if (minm == 0) 
            minm = 100000; 
	            if (rt[shortest] == 0) { 
            complete++; 
            check = false; 
            finish_time = t + 1; 

            wt[shortest] = finish_time - 
                        proc[shortest].burstTime - 
                        proc[shortest].arrivalTime; 
  
            if (wt[shortest] < 0) 
                wt[shortest] = 0; 
        } 
        t++; 
    } 
} 
  
// Function to calculate the turn around time 
void findTurnAroundTime(Process proc[], int m, 
                        int wt[], int tat[]) 
{ 
    for (int i = 0; i < m; i++) 
        tat[i] = proc[i].burstTime + wt[i]; 
} 
  
// Function to the calculate of average time 
void findavgTime(Process proc[], int m) 
{ 
    int wt[m], tat[m], total_wt = 0, 
                    total_tat = 0,i; 

    findWaitingTime(proc, m, wt); 
    findTurnAroundTime(proc, m, wt, tat);  
    printf(" Processes\t Burst time\t Waiting time\t  Turn around time\n"); 

for ( i = 0; i < m; i++) {
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        printf( " %d        \t ", proc[i].processID);
        printf(" %d        \t ",proc[i].burstTime) ;
		printf(" %d        \t ",wt[i]); 
        printf(" %d        \t ", tat[i]) ; printf("\n"); 
    } 
  
    printf( "\nAverage waiting time = ");
        printf("%f", (float)total_wt / (float)m); 
    printf("\nAverage turn around time = ");
        printf("%f", (float)total_tat / (float)m); 
} 
void Que1()
{
	printf("\nRound Robin Scheduling\n");
	  int count,j,m,time,remain,flag=0,time_quantum; 
  int wait_time=0,turnaround_time=0,at[10],burstTime[10],rt[10]; 
  printf("Enter Total Process:\t "); 
  scanf("%d",&m); 
  remain=m; 
  for(count=0;count<m;count++) 
  { 
    printf("Enter Arrival Time and Burst Time for Process Process Number %d :",count+1); 
    scanf("%d",&at[count]); 
    scanf("%d",&burstTime[count]); 
    rt[count]=burstTime[count]; 
  } 
  printf("Enter Time Quantum:\t"); 
  scanf("%d",&time_quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,count=0;remain!=0;) 
  { 
    if(rt[count]<=time_quantum && rt[count]>0) 
    { 
      time+=rt[count]; 
      rt[count]=0; 
      flag=1; 
    } 
    else if(rt[count]>0) 
    { 
      rt[count]-=time_quantum; 
      time+=time_quantum; 
    } 
    if(rt[count]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-burstTime[count]); 
      wait_time+=time-at[count]-burstTime[count]; 
      turnaround_time+=time-at[count]; 
      flag=0; 
    } 
    if(count==m-1) 
      count=0; 
    else if(at[count+1]<=time) 
      count++; 
    else 
      count=0; 
  } 
  printf("\nAverage Waiting Time= %f\n",wait_time*1.0/m); 
  printf("Avg Turnaround Time = %f",turnaround_time*1.0/m); 
  
}
void Que2()
{
	printf("\nQueue2 :\n");
	printf("\nShortest Job first Scheduling\n"); 
	printf("Enter Total Number of Processes:\t"); 
	int limit,count;
	scanf("%d", &limit);  
	Process proc[limit]; 
	for(count = 0; count < limit; count++) 
	{ 
		printf("\nProcess ID:\t"); 
		scanf("%d", &proc[count].processID); 
		printf("Arrival Time:\t"); 
		scanf("%d", &proc[count].arrivalTime); 
		printf("Burst Time:\t"); 
		scanf("%d", &proc[count].burstTime);  
	}

	findavgTime(proc,limit);
}

int main()
{
	int p1,p2;
	int que1=1,que2=2;
	printf("Enter the priority of the queue %d\n",que1);
	scanf("%d",&p1);
	printf("Enter the priority of the queue %d\n",que2);
	
	scanf("%d",&p2);
	if(p1<p2)
	{
	  Que1();
	  Que2();
	}
	else if(p1>p2){
	 Que2();
     Que1();
	}
}

