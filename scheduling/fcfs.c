#include<stdio.h>

int main() {
	int n,i;
	printf("Enter the no. of processes\n");
	scanf("%d",&n);
	int bt[n],wt[n],tat[n];
	for(i=0;i<n;i++){
		printf("Enter the Burst Time for Process %d--\t",i);
		scanf("%d",&bt[i]);
	}
	tat[0]=bt[0];
	wt[0]=0;
	//Since We have assumed that the arrival time is 0 so Turn around time will be equal to Completion time.
	for(i=1;i<n;i++){
		tat[i]=bt[i]+bt[i-1];
		wt[i]=tat[i]-bt[i];
	}
	printf("\tProcess\tBurst Time\tTurn around Time\tWaiting Time\n");
	for(i=0;i<n;i++){
		printf("\t%d\t%d\t%d\t%d\n",i,bt[i],tat[i],wt[i]);
	}
	return 0;
}
