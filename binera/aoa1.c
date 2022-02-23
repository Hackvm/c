#include <stdio.h>
 
int main()
{
   int list[100], len, i, j, pos, swap;
  
   printf("\nEnter the number of elements: ");
   scanf("%d", &len);
   printf("\nEnter %d Numbers:\n", len);
  
 
   for (i = 0; i < len; i++)
       scanf("%d", &list[i]);
 
   for(i = 0; i < len - 1; i++) {
  
       pos = i;
       for(j = i + 1; j < len; j++) {
           if(list[pos] > list[j])
               pos = j;
       }
 
       if(pos != i) {
           swap = list[i];
           list[i] = list[pos];
           list[pos] = swap;
       }
   }
 
   printf("\n\nResult:\n");
   for(i = 0; i < len; i++)
       printf("%d  ", list[i]);
  
   printf("\n");
   return 0;
}
