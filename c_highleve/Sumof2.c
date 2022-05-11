#include<stdio.h>
void main(){
    int i,j,arr[10],n,x;
    printf("The Number you want the submition:");
    scanf("%d",&x);
    printf("The Number You Enter:");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        printf("Enter te Value in %d Number:",i);
        scanf("%d",&arr[i]);
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(arr[i] + arr[j] == x){
                printf("%d + %d = %d\n",arr[i],arr[j],arr[i]+arr[j]);

                if(arr[i] == arr[j]){
                     printf("Extra %d + %d = %d\n",arr[i],arr[j],arr[i]+arr[j]);
                }
            }
        }
    }

}
