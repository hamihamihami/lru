#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
struct pri{
int pid,at,prio,bt,st,ft,wt,ta;
}s[10];
int main()
{
int i,n,completed=0,current_time=0,totwt=0,totta=0;
float avgwt,avgta;
bool is_completed[10]={false};
printf("\n enter no.of processos:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\n enter pid,at,bt,priority of process %d:",i+1);
scanf("%d%d%d%d",&s[i].pid,&s[i].at,&s[i].bt,&s[i].prio);
}
while(completed!=n)
{
 int min_index=-1;
 int min=INT_MAX;
 for(i=0;i<n;i++)
 {
 if(s[i].at<=current_time&&is_completed[i]!=true)
 {
 if(s[i].prio<min)
 {
 min=s[i].prio;
 min_index=i;
 }
 if(s[i].prio==min)
 {
 if(s[i].at<s[min_index].at)
 {
 min=s[i].prio;
 min_index=i;
 }
 }
 }
 }
 if(min_index==-1)
 current_time++;
 else
 {
 s[min_index].st=current_time;
 s[min_index].ft=s[min_index].st+s[min_index].bt;
 s[min_index].wt=s[min_index].st-s[min_index].at;
 s[min_index].ta=s[min_index].bt+s[min_index].wt;
 completed++;
 current_time=s[min_index].ft;
 is_completed[min_index]=true;
 }
}
printf("\n process at\t prio\t bt\t st\t ft\t wt\t ta");
for(i=0;i<n;i++)
{
printf("\np%d\t   %d\t %d\t %d\t %d\t %d\t %d\t %d",s[i].pid,s[i].at,s[i].prio,s[i].bt,s[i].st,s[i].ft,s[i].wt,s[i].ta);
 totwt+=s[i].wt;
 totta+=s[i].ta;
}
avgwt=(float)totwt/n;
avgta=(float)totta/n;

printf("\n avg waiting time=%f \n avg turn around time=%f",avgwt,avgta);
return 0;
}

