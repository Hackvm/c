#include<stdio.h>

void main(){
    int i,j,arr[20],n,arr1[20],temp,temp2,temp3;
    printf("The Number of Elements: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter the Number %d: ",i);
        scanf("%d",&arr[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(arr[j]%2==0){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] =temp;
            }
        }
    }
    int count=0;
    for(int i=1;i<=n;i++){
            if(arr[i]%2==0){
                // temp2 = arr[i];
                count=count+1;
            }
        }
    for(int i=1;i<=count;i++){
        for(int j=1;j<=count-1;j++){
            if(arr[j]>arr[j+1]){
                temp2 = arr[j];
                arr[j] =arr[j+1];
                arr[j+1] = temp2;
            }
        }
    }
    for(int i=count+1;i<=n;i++){
        for(int j=count+1;j<=n-1;j++){
            if(arr[j]>arr[j+1]){
                temp3 = arr[j];
                arr[j] =arr[j+1];
                arr[j+1] = temp3;
            }
        }
    }


// printf("\n%d \t\t%d\n",temp2,count);
printf("\nThe Even And Odd is:\n");
for(int i=1;i<=n;i++){
    printf("%d  ",arr[i]);
    }

}