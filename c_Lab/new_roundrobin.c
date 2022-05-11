#include<stdio.h>
// #include<conio.h>

void main(){
    int Numbofprocess,busttime[10],arrivaltime[10],readyque[10],Quantumtime,y,sum=0,count=0,wt=0,tat=0;
    float avg_tat,avg_wt;
    printf("\n Enter  the Number of Process:");
    scanf("%d",&Numbofprocess);
     y = Numbofprocess;
    for(int i=0;i<Numbofprocess;i++){
        printf("\nThe Process[%d] detail\n",i+1);
        printf("Arrivial Time: ");
        scanf("%d",&arrivaltime[i]);
        printf("Bust Time: ");
        scanf("%d",&busttime[i]);
        readyque[i]=busttime[i];
    }

    printf("\nEnter the Quantum Time: ");
    scanf("%d",&Quantumtime);

    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");

    for(int i=0,sum=0;y!=0;){
        if(readyque[i] <= Quantumtime && readyque[i] > 0){
            sum = sum + readyque[i];
            readyque[i]=0;
            count=1; 
        }

        else if(readyque[i] > 0){
            readyque[i] = readyque[i] - Quantumtime;
            sum = sum + Quantumtime;
        }

        if(readyque[i]==0 && count==1)  {  
            y--; //decrement the process no.  
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i+1, busttime[i], sum-arrivaltime[i], sum-arrivaltime[i]-busttime[i]);  
            wt = wt+sum - arrivaltime[i]- busttime[i];  
            tat = tat+sum-arrivaltime[i];  
            count =0;     
        }
          if(i==Numbofprocess-1)  
        {  
                i=0;  
        }  
        else if(arrivaltime[i+1]<=sum)  
        {  
                i++;  
        }  
        else  
        {  
                i=0;  
        } 


    }
avg_wt = wt * 1.0/Numbofprocess;  
avg_tat = tat * 1.0/Numbofprocess;  
printf("\n Average Turn Around Time: \t%f", avg_wt);  
printf("\n Average Waiting Time: \t%f", avg_tat); 
}