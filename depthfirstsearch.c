#include<stdio.h>
int a[20][20],visited[20],n,i,j;
int q[20];
int f=0,r=-1;
int isEmpty()
{
if(f>r)
{
return 1;
}
else
{
return 0;
}
}
int QInsert(int data)
{
q[++r]=data;
}
int QDelete()
{
int data=q[f++];
return data;
}
void bfs(int v)
{
int d;
if(!visited[v])
{
visited[v]=1;
printf("%d->",v);
}
for(i=1;i<=n;i++)
{
if(a[v][i]==1 && visited[i]==0)
{
QInsert(i);
}
}
if(!isEmpty())
{
d=QDelete();
bfs(d);
}
}
void dfs(int v)
{
int i;
visited[v]=1;
for(i=1;i<=n;i++)
{
if(a[v][i]==1 && visited[i]==0){
printf("\n %d -> %d",v,i);
dfs(i);
}
}
}
int main()
{
int v,ch;
printf("\n Enter no of vertices:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
visited[i]==0;
}
printf("\n Enter the adjacency matrix:");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
scanf("%d",&a[i][j]);
}
}
printf("\n Enter the starting vertice :");
scanf("%d",&v);
printf("Enter the choice:\n");
printf("1.Depth First Search\n");
printf("2.Breadth First Search\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
{
dfs(v);
for(i=1;i<=n;i++)
{
if(visited[i]==0)
{
dfs(i);
}
}
break;
}
case 2:
{
bfs(v);
for(i=1;i<=n;i++)
{
if(visited[i]==0)
{
bfs(i);
}
}
break;}
default:
printf("Invalid Input");
break;
}
}