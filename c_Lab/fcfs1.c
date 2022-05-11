#include<stdio.h>

void main(){
    int arrivtim[10],busrttim[10],completime[10],temp[10],TAT[10],WT[10],nof,sum=0,tat=0,wt=0;
    float avg_tat,avg_wt;
    printf("Enter the Number of process: ");
    scanf("%d",&nof);
    for(int i=0 ; i<nof ;i++){
        printf("\nEnter The Process[%d] detail\n",i+1);
        printf("Arrival Time: ");
        scanf("%d",&arrivtim[i]);
        printf("Burst Time: ");
        scanf("%d",&busrttim[i]);
    }
    temp[0]=0;
    for(int i=0; i<nof ; i++){
        WT[i]=0;
        TAT[i]=0;
        temp[i+1] = temp[i] + busrttim[i];
        WT[i] = temp[i] - arrivtim[i];
        TAT[i] = WT[i] + busrttim[i];
        wt = wt + WT[i];
        tat = tat + TAT[i];
        printf("\nP%d \t\t %d \t\t %d \t\t %d \t\t %d",i+1,arrivtim[i],busrttim[i],TAT[i],WT[i]);
    }
avg_wt = wt*1.0/nof;
avg_tat = tat*1.0/nof;
printf("\nAverage Waiting Time: %f\n",avg_wt);
printf("Average Turn Around Time: %f\n",avg_tat);
}