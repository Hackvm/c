#include<stdio.h>
#include<stdlib.h>
void main(){
    int num,lower,upper,mid,i,val;
    printf("Enter the size of an array:");
    scanf("%d",&num);
    int arr[num];
    i=0;
    while(i<num){
    printf("Enter the data in array:");
    scanf("%d",&arr[i]);
    i++;
    }
    lower = 0;
    upper = num;

    printf("Enter the data you want to find:");
    scanf("%d",&val);
    //int count=0;
    while(lower<=upper){
        mid = (lower+upper)/2;
        if(val==arr[mid]){
            printf("The Elemet found is %d\n",val);
            //printf("the position of that element is %d\n\n",count);
            break;
        }

        else if(val<arr[mid]){
            //mid = (lower+mid)/2;
            upper = mid-1;
            printf("2.The Element foud at %d is %d\n",upper,arr[upper]);
            //printf("The position of that element is %d\n\n",count);
            break;
        }

        else{
            //mid = (mid+upper)/2;
            lower = mid+1;
            printf("3.The Element foud at %d is %d\n",lower,arr[lower]);
            //printf("The position of that element is %d\n\n",count);
            break;
        }
        //count = count +1;
    }


}