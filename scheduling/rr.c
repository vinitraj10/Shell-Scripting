#include<stdio.h>

typedef struct process {
	int id;
	int bt;
	int tat;
	int wt;
}process;
void findWaitingTime(process p[],int n,int tslice){
	int rem_bt[n],i,t=0;
	for(i=0;i<n;i++)
		rem_bt[i]=p[i].bt;
	while(1){
		int done=1,i;
		for(i=0;i<n;i++){
			if(rem_bt[i]>0){
				done=0;
				if(rem_bt[i]>tslice){
					t+=tslice;
					rem_bt[i]-=tslice;
				}
				else{
					t+=rem_bt[i];
					p[i].wt=t-p[i].bt;
					rem_bt[i]=0;
				}
			}
		}
		if(done==1)
			break;
	}
}
void findTurnAroundTime(process p[],int n){
	int i;
	for(i=0;i<n;i++){
		p[i].tat = p[i].bt+p[i].wt;
	}
}
void findAvgTime(process p[],int n,int tslice){
	int i=0;
	findWaitingTime(p,n,tslice);
	findTurnAroundTime(p,n);
	printf("Process\t Burst Time \t Waiting Time \t TAT\n");
	for(i=0;i<n;i++){
		printf("%d\t\t%d\t\t%d\t\t%d\n",p[i].id,p[i].bt,p[i].wt,p[i].tat);		
	}
}
int main(){
	int n,i,tslice;
	printf("Enter the no. of processes:-\n");
	scanf("%d",&n);
	process p[n];
	for(i=0;i<n;i++){
		p[i].id=i;
		printf("Enter the burst time for process no-%d\t",i);
		scanf("%d",&p[i].bt);	
	}
	printf("Enter the Time quantum:-\t");
	scanf("%d",&tslice);
	findAvgTime(p,n,tslice);
	return 0;
}
