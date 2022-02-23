#include<stdio.h>
#include<math.h>
 
void insertion_sort(int list[], int n)
{
   int i, j, key;
   for (i = 1; i < n; i++) {
       key = list[i];
       j = i - 1;
 
       while (j >= 0 && list[j] > key) {
           list[j + 1] = list[j];
           j = j - 1;
       }
 
 
       list[j + 1] = key;
   }
}
 
int main()
{
   int list[100], len, i;
  
   printf("\nEnter the number of elements: ");
   scanf("%d", &len);
   printf("\nEnter %d Numbers:\n", len);
  
   for (i = 0; i < len; i++)
       scanf("%d", &list[i]);
 
   insertion_sort(list, len);
  
   printf("\n\nResult:\n");
   for(int k = 0; k < len; k++)
       printf("%d  ", list[k]);
  
   printf("\n");
 
   return 0;
}
