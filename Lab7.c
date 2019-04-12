#include<stdio.h>
#include<stdio.h>
#include<string.h>

void main(){
	int ch,q,n,i;
	int proc[20],b[20],arrtime[20],rem;
	do{
		printf("Enter the choice: ");
		printf("\n 1.Round Robin\n 2.SRT\n 3.Exit\n");
		printf("Your choice is: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\n**ROUND ROBIN SCHEDULING ALGORITHM**\n");
				printf("Enter the number of processes:\n");
				scanf("%d",&n);
				printf("Enter burst time for Process:\n");
				for(i=0;i<n;i++){
					printf("P%d:",i+1);
					scanf("%d",&b[i]);
					proc[i]=b[i];
				}
				printf("Enter the quantum time:\n");
				scanf("%d",&q);
				roundrobin(n,q,proc,b);
				break;
			case 2:
				printf("\n**SHORTEST REMAINING TIME NEXT SCHEDULING ALGORITHM**");
				printf("Enter the number of processes: \n");
				scanf("%d",&n);
				printf("Enter burst time for process:\n");
				for(i=0;i<n;i++){
					printf("P%d:",i+1);
					scanf("%d",&b[i]);
					proc[i]=b[i];
				}
				printf("Enter arrival time for process:\n");
				for(i=0;i<n;i++){
					printf("P%d:",i+1);
					scanf("%d",&arrtime[i]);
				}
				printf("Burst time\tArrival time\n");
				for(i=0;i<n;i++){
					printf("%d\t|\t%d\n",b[i],arrtime[i]);
				}
				srtf(n,b,proc,arrtime);
				break;
			case 3:
				exit(0);
		}
	}while(ch!=3);
}

int roundrobin(int n,int q,int proc[],int b[]){
	int i,count=1,sq=0,turnat[10],wait[10],sumtat=0,sumwt=0,temp;
	float avgwt=0.0,avgtat=0.0;
	while(1){
		for(i=0,count=0;i<n;i++){
			temp=q;
			if(proc[i]==0){
				count++;
				continue;
			}
			if(proc[i]>q)
				proc[i]=proc[i]-q;
			else
				if(proc[i]>=0){
					temp=proc[i];
					proc[i]=0;
				}
			sq=sq+temp;
			turnat[i]=sq;
		}
		if(n==count)
			break;
	}
	for(i=0;i<n;i++){
		wait[i]=turnat[i]-b[i];
		sumwt=sumwt+wait[i];
		sumtat=sumtat+turnat[i];
	}
	avgwt=(float)sumwt/n;
	avgtat=(float)sumtat/n;
	printf("\nProcesses name \tBrust time\tWaiting time\tTurn around time\n");
	for(i=0;i<n;i++){
		printf("P%d\t|\t%d\t|\t%d\t|\t%d\n",i+1,b[i],wait[i],turnat[i]);
	}
	printf("\nAverage waiting time is:%f",avgwt);
	printf("\nAverage turn around time is:%f\n",avgtat);
	return 0;
}
int srtf(int n,int b[],int proc[],int arrtime[]){
	int time,sum_bt=0,small,i,rem;
	int sumt=0,sumw=0;
	float avgwt,avgtat;
	rem=n;
	printf("\nProcesses name\tWaiting time\tTurn around time\n");
	proc[9]=b[9]=9999;
	for(time=0;rem!=0;time++){
		small=9;
		for(i=0;i<n;i++){
			if(arrtime[i]<=time && proc[i]>0 && proc[i]<proc[small])
				small=i;
		}
		proc[small]--;
		if(proc[small]==0){
			rem--;
			printf("P%d\t|\t%d\t|\t%d\n",small+1,time+1-b[small]-arrtime[small],time+1-arrtime[small]);
			sumw=sumw+time+1-b[small]-arrtime[small];
			sumt=sumt+time+1-arrtime[small];
			avgwt=(float)sumw/n;
			avgtat=(float)sumt/n;
		}
	}
	printf("\nAverage waiting time =%f",avgwt);
	printf("\nAverage turnaround time=%f\n",avgtat);
	return 0;
}

/*OUTPUT
Enter the choice: 
 1.Round Robin
 2.SRT
 3.Exit
Your choice is: 1

**ROUND ROBIN SCHEDULING ALGORITHM**
Enter the number of processes:
3
Enter burst time for Process:
P1:24
P2:3
P3:3
Enter the quantum time:
4

Processes name 	Brust time	Waiting time	Turn around time
P1	|	24	|	6	|	30
P2	|	3	|	4	|	7
P3	|	3	|	7	|	10

Average waiting time is:5.666667
Average turn around time is:15.666667
Enter the choice: 
 1.Round Robin
 2.SRT
 3.Exit
Your choice is: 2

**SHORTEST REMAINING TIME NEXT SCHEDULING ALGORITHM**
Enter the number of processes: 
4
Enter burst time for process:
P1:8
P2:4
P3:9
P4:5
Enter arrival time for process:
P1:0
P2:1
P3:2
P4:3
Burst time	Arrival time
8	|	0
4	|	1
9	|	2
5	|	3

Processes name	Waiting time	Turn around time
P2	|	0	|	4
P4	|	2	|	7
P1	|	9	|	17
P3	|	15	|	24

Average waiting time =6.500000
Average turnaround time=13.000000
Enter the choice: 
 1.Round Robin
 2.SRT
 3.Exit
Your choice is: 3

*/	
