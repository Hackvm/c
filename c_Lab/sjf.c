#include<stdio.h>

void main(){
    int busttime[10],i,j,process[10],numberofprocess,t,WT[10],TAT[10],wt=0,ata=0;
    float avg_wt,avg_ata;
    printf("Enter the Number of Process:");
    scanf("%d",&numberofprocess);

    for(i=0;i<numberofprocess;i++){
        printf("Enter the detail of process[%d]:\n",i);
        printf("Proces Number: ");
        scanf("%d",&process[i]);

        printf("Burst Time: ");
        scanf("%d",&busttime[i]);
    }

    for(i=0;i<numberofprocess;i++){
        for(j=0;j<numberofprocess-i-1;j++){

            if (busttime[j]>busttime[j+1]){
                t = busttime[j];
                busttime[j] = busttime[j+1];
                busttime[j+1] = t;

                t = process[j];
                process[j] = process[j+1];
                process[j+1] = t;
            }
        }
    }
    for(i=0;i<numberofprocess;i++){
        WT[i]=0;
        TAT[i]=0;
        for(j=0;j<i;j++){
            WT[i] = WT[i]+busttime[j];
        }
        TAT[i] = WT[i] + busttime[i];
        wt = wt + WT[i];
        ata = ata +TAT[i];

        printf("\n%d \t\t %d \t\t %d \t\t %d\n",i,busttime[i],TAT[i],WT[i]);
    }

    avg_wt = wt *1.0/numberofprocess;
    avg_ata = ata *1.0/numberofprocess;
}