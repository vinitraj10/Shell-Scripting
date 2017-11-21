#include<stdio.h>
#include<stdlib.h>

typedef struct process {
	int id;
	int bt;
	int wt;
	int tat;
}process;

int compare(const void* a, const void* b){
	return (*(process*)a).bt > (*(process*)b).bt;
}

int main(){
	int n,i;
	printf("Enter the number of processes:-\n");
	scanf("%d",&n);
	process p[n];
	for(i=0;i<n;i++){
		p[i].id=i;
		printf("Enter the burst time for process no. %d\t",i);
		scanf("%d",&p[i].bt);
	}
	qsort(p, n, sizeof(process), compare);
	p[0].tat=p[0].bt;
	p[0].wt=0;
	printf("Process\t Burst Time\t Waiting Time\t Turn around Time\n");
	printf(" %d \t\t %d\t\t %d\t\t %d\n",p[0].id,p[0].bt,p[0].wt,p[0].tat);
	
	for(i=1;i<n;i++){
		p[i].tat=p[i-1].bt+p[i].bt;
		p[i].wt=p[i].tat - p[i].bt;
		printf(" %d \t\t %d\t\t %d \t\t %d \n",p[i].id,p[i].bt,p[i].wt,p[i].tat);	
	}
	return 0;
}
