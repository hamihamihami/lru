#include<stdio.h>
struct fcfs
{
int at,bt,st,ft,wt,ta,pid;
};
void swap(struct fcfs *x,struct fcfs *y)
{
struct fcfs t;
t=*x;
*x=*y;
*y=t;
}
int main()
{
int n,i,j;
float avgwt=0,avgta=0;
printf("\n enter no.of processors");
scanf("%d",&n);
struct fcfs f[n];
for(i=0;i<n;i++)
{
printf("enter pid,at,bt time:");
scanf("%d%d%d",&f[i].pid,&f[i].at,&f[i].bt);
}
for(i=0;i<n;i++)
{
for(j=0;j<n-1;j++)
{
if(f[j].at>f[j+1].at)
{
swap(&f[j],&f[j+1]);
}
}
}
f[0].st=f[0].at;
for(i=1;i<n;i++)
{
if(f[i].at>f[i-1].st+f[i-1].bt)
f[i].st=f[i].at;
else
f[i].st=f[i-1].st+f[i-1].bt;
}
for(i=0;i<n;i++)
{
f[i].ft=f[i].st+f[i].bt;
f[i].wt=f[i].st-f[i].at;
}
for(i=0;i<n;i++)
{
f[i].ta=f[i].bt+f[i].wt;
}
for(i=0;i<n;i++)
{
avgwt=avgwt+f[i].wt;
avgta=avgta+f[i].ta;
}
printf("\n process\t at\t bt\t st\t ft\t wt\t ta\n");
for(i=0;i<n;i++)
{
printf("\n   p%d   \t %d\t %d\t %d\t %d\t %d\t %d",f[i].pid,f[i].at,f[i].bt,f[i].st,f[i].ft,f[i].wt,f[i].ta);
}
printf("\n avg waiting time=%f",avgwt/n);
printf("\n avg ta time=%f",avgta/n);
return 0;
}

