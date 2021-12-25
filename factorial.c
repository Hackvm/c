#include<stdio.h>
#include<stdlib.h>
void main(){
    int i=1,n,j=1;
    printf("Enter the lemnt you want the factorail:");
    scanf("%d",&n);
    for(i=n;i>1;i--){
        printf("%dx",i*1);
    }
    printf("%d",i);

    for(i=n;i>1;i--){
        j = i*j;
    }
    printf("=%d",j);
}