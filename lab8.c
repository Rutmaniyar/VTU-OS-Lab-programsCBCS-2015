#include<stdio.h>
#include<string.h>
int i,n,m,j;
int avbl[20],max[10][10],aloc[10][10],need[10][10];
struct info{
	int index;
	int finish;
}proc[20];

int safety(){
	int work[10],i,count=0;
	for(i=0;i<m;i++){
		work[i]=avbl[i];
	}
	for(i=0;i<n;i++){
		proc[i].finish=0;
	}
	i=0;
	printf("\nSafe sequence: ");
	while(1){
		count++;
		if(proc[i].finish)
			i++;
		else{
			for(j=0;j<m;j++){
				if(need[i][j]>work[j])
					break;
			}
			if(proc[i].finish==0 && j==m){
				proc[i].finish=1;
				printf("P%d ",proc[i].index);
				for(j=0;j<m;j++)
					work[j]=work[j]+aloc[i][j];
			}i=++i%n;
			for(j=0;j<n;j++){
				if(proc[j].finish==0)
					break;
			}
			if(j==n){
				printf("\n System is safer!!..\n");
				return 1;
			}
			if(count>100){
				printf("\n Unsafe! System would lead to deadlock state..\n");
				return 0;
			}
		}
	}
}
void newrequest()
{
	int nr[10],ind;
	printf("\nEnter the process index for additional request:\n");
	scanf("%d",&ind);
	printf("\nEnter resource request for process P%d:\n",ind);
	for(j=0;j<m;j++){
		scanf("%d",&nr[j]);
	}
	for(j=0;j<m;j++){
		if(nr[j]>need[ind][j]){
			printf("\nERROR!Request is greater than need..\nSo the request cannot be granted!..\n");
			break;
		}
	}
	for(j=0;j<m;j++){
		if(nr[j]>avbl[j]){
			printf("\nERROR!Request is greater than available..\nSo the request cannot be granted!..\n");
			break;
		}
	}
	if(j==m){
		for(j=0;j<m;j++){
			aloc[ind][j]=aloc[ind][j]+nr[j];
			need[ind][j]=need[ind][j]-nr[j];
			avbl[j]=avbl[j]-nr[j];
		}
		if(safety())
			printf("\nResource request is granted...\n");
		else
			printf("\nResource request is not granted...\n");
	}
}
void main(){
	printf("\n*****BANKERS ALGORITHUM SIMULATION******");
	printf("\nEnter the number fo process in the system:\n");
	scanf("%d",&n);
	printf("Enter the toal number of resource type\n");
	scanf("%d",&m);
	printf("Default name selected for process are:\n");
	for(i=0;i<n;i++)
	{
		printf("P%d ",i);
		proc[i].index=i;
	}
	printf("\nEnter the available vector:<maximum resouresavailable>:\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&avbl[i]);
	}
	printf("Enter max demand of each process:\n");
	for(i=0;i<n;i++)
	{
		printf("P%d:",proc[i].index);
		for(j=0;j<m;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter the allocation matrix:\n");
	for(i=0;i<n;i++)
	{
		printf("P%d:",proc[i].index);
		for(j=0;j<m;j++)
		{
			scanf("%d",&aloc[i][j]);
		}
	}
	printf("Need matrix is:\n");
	for(i=0;i<n;i++)
	{
		printf("P%d:",proc[i].index);
		for(j=0;j<m;j++)
		{
			need[i][j]=max[i][j]-aloc[i][j];
			printf("%d ",need[i][j]);

		}
		printf("\n");
	}
	safety();
	newrequest();
}
/*
op1:
*****BANKERS ALGORITHUM SIMULATION******
Enter the number fo process in the system:
5
Enter the toal number of resource type
3
Default name selected for process are:
P0 P1 P2 P3 P4 
Enter the available vector:<maximum resouresavailable>:
3 3 2
Enter max demand of each process:
P0:7 5 3
P1:3 2 2
P2:9 0 2
P3:2 2 2
P4:4 3 
 
3
Enter the allocation matrix:
P0:0 1 0
P1:2 0 0 
P2:3 0 2
P3:2 1 1 
P4:0 0 2
Need matrix is:
P0:7 4 3 
P1:1 2 2 
P2:6 0 0 
P3:0 1 1 
P4:4 3 1 

Safe sequence: P1 P3 P4 P0 P2 
 System is safer!!..

Enter the process index for additional request:
1

Enter resource request for process P1:
1 0 2

Safe sequence: P1 P3 P4 P0 P2 
 System is safer!!..

Resource request is granted...

output2:
****BANKER'S ALGORITHM SIMULATION***
Enter the number of process in the system:
2

Enter the number of resource types:
3

Default name selected for process are:
P0,P1,
Enter available vector:<Maximum resources available>:
3
2
1

Enter the max demand of each process:
P0:2
0
0
P1:4
3
3

Enter the allocation matrix:
P0:3
0
2
P1:0
0
2

the need matrix:
P0:-10-2
P1:431

Safe sequence: P0 
 Unsafe! System would lead to deadlock state..

Enter the process index for additional request:
1

Enter resource request for process P1:
0
6
7

ERROR!Request is greater than need..
So the request cannot be granted!..

ERROR!Request is greater than available..
So the request cannot be granted!..
*/
